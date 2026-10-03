# learn-c-snippets

Small, self-contained C programs, each exploring one idea.

| Folder | Topic |
|---|---|
| `array_simple/` | Summing array elements |
| `arr_addr_size/` | Array addresses and element sizes |
| `bit_manip/` | Setting and clearing bits |
| `Bit_reversal/` | Reversing the bits of a byte |
| `element_size/` | Counting array elements with `sizeof` |
| `extern_test/` | Sharing globals across files with `extern` |
| `logic_test/` | Struct layout and logic puzzles (C and C++) |
| `state_test/` | State machine implementations |
| `struct/` | Struct initialisation |
| `unary_test/` | Unary operators on unsigned values |
| `dumm_code/` | Hello-world scratch file |
| `practice/` | Practice question list |

## Building

Each folder builds on its own, for example:

```sh
clang-cl -g bit_manip/bit_set_clear.c -o bit_set_clear.exe
# or
gcc -g bit_manip/bit_set_clear.c -o bit_set_clear
```

`.vscode/tasks.json` has a clang-cl "build active file" task.
