/*
@startuml
'state diagram

'Keyboard FSM

[*] --> default
default --> shifted:SHIFT_depressed
shifted --> default:SHIFT_released


default : ANY_KEY/send_lower_case
shifted : ANY_KEY/send_upper_case


@enduml

@startuml
'state diagram
hide empty description
[*] --> Idle
Idle --> Check: Cyclic Request
Idle --> Error: Request failed
Check --> Idle: Passed \n (pending next group)
Check --> Wait: Passed (completed all groups)
Wait --> Idle: Timer reset.
Check --> Error : Failed
Error --> [*]

Check : Start Event loop

state Check {
    [*]-> nenNORMAL
    nenNORMAL --> nenDEBOUNCE: Failed
    nenNORMAL --> nenCLEANUP: Passed (All Done)
    nenDEBOUNCE --> nenCLEANUP: Passed (All retries)
    nenNORMAL --> [*] : Passed (pending next group)
    nenDEBOUNCE --> [*] : Passed (pending next group) /\n Failed
    nenCLEANUP --> [*]
    }

@enduml
*/

typedef short Signal;
typedef struct Event Event;
typedef struct Fsm Fsm;
typedef void (*State)(Fsm *, Event const *);

/* Event base class */
struct Event
{
   Signal sig;
};

/* Finite State Machine base class */
struct Fsm
{
   State state__; /* the current state */
};

/* "inlined" methods of Fsm class */
#define FsmCtor_(me_, init_) ((me_)->state__ = (State)(init_))
#define FsmInit(me_, e_)     (*(me_)->state__)((me_), (e_))
#define FsmDispatch(me_, e_) (*(me_)->state__)((me_), (e_))
#define FsmTran_(me_, targ_) ((me_)->state__ = (State)(targ_))

