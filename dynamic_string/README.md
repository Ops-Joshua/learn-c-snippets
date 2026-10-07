# Dynamic memory for strings

Code snippets for strings processing and pointer snippets. One common issues with string handling is pointer passing and ownership.

| File                   | Description                                                                                                                        |
| ---------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| out_param.c            | Out-parameter (`T **out`) plus a status code pattern                                                                               |
| bug_unintialized_var.c | Show issue of non-allocated dynamic memory... the function stack overlap causes the memory to access previous function stack data. |
| string_ptr_passing.c   | Show snippets of Callee allocating and passing allocated memory to Caller.<br/><br/>- getbuf() uses preallocated                   |

## Out Param key idea

Callee returns an `int` status and passes the result up through a double pointer. The callee hands the pointer over only after its own work has succeeded, so ownership is never ambiguous. Caller free's the pointer after use.

Rules that keep this safe:

- Set `*out = NULL` first, before anything can fail.
- Assign `*out` only as the last step, after everything has succeeded.
- On failure, each level frees only what it allocated itself.


q
## String passing snippets

There are 2 key examples

- Caller prellocates buffer and passes the pointer to a function taking 1 level pointer

- Caller passes pointer to be use to a function taking 2 levels pointer.

## Uninitialized array issue.

`dyn_line` is declared but **never assigned** before it's printed and passed into `use_dynallocated`. C does not zero-initialize automatic (stack) variables — `dyn_line` just contains whatever bit pattern was already sitting in that stack slot.

Here's why that pattern happens to look like `fline`'s address:

1. `main()` calls `getbuf()` first (line 109), which allocates `fline` via `malloc` and stores that heap pointer in its local stack slot.
2. `getbuf()` returns — its stack frame is popped, but the actual bytes in memory aren't cleared, they're just no longer "owned."
3. `main()` then calls `getdynbuf()` (line 109). Because `getdynbuf`'s locals (`dyn_line`, `next`) are laid out similarly to `getbuf`'s locals (`fline`, `next`) and the call happens right after `getbuf` returns, the compiler often reuses the *exact same stack addresses* for the new frame.
4. Since `dyn_line` is never written to before being read, it picks up whatever was last stored at that address — which is `fline`'s old heap pointer value, left over from `getbuf()`.

So `&dyn_line == &fline` (same stack slot address) is plausible because of identical frame layout, and `dyn_line`'s *content* equaling `fline`'s old value is just stale memory being read back — not a real connection between the two.



# Summary

Everything in C is passed **by value**, so the function always gets a *copy* of whatever you pass. The difference is what that copy points at:

- With `char *str`, the function gets a copy of the **pointer**. It can change the **characters** the pointer points at, but not the caller's pointer itself.
- With `char **str`, the function gets the **address of the caller's pointer variable**. It can change the characters **and** make the caller's pointer point somewhere else.

```
caller:   char *p ───────────► [ h e l l o \0 ]
                ▲                    ▲
f(char *s):     │       s (copy) ────┘   s can reach the chars only
g(char **s):    s ──────┘                s reaches p itself, so *s = ... changes p
```

## The classic bug

```c
void alloc_bad(char *s)  { s = malloc(10); strcpy(s, "hi"); }   // changes the local copy only
void alloc_ok (char **s) { *s = malloc(10); strcpy(*s, "hi"); } // changes the caller's p

char *p = NULL;
alloc_bad(p);    // p is still NULL, and the 10 bytes are leaked
alloc_ok(&p);    // p now points at "hi"
free(p);
```
