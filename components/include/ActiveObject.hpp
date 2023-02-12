#ifndef COMPONENTS_INCLUDE_ACTIVEOBJECT
#define COMPONENTS_INCLUDE_ACTIVEOBJECT
#include "StateMachine.h"
#include <queue>
  
using namespace std;
  
/**
 * @brief Active objects can hold states, can receive events and act accordingly.
 * It has a state machine that holds all the states and transitions. 
 * Event pool to hold incoming events, that can build up. 
 * A thread will run to consume events as they come.
 * 
 * 
 */
class ActiveObject{
    private:
        StateMachine stateMachine_;
        State currentState_;
        queue<Event> eventQueue; //Queue that holds incoming events.

        void ProcessEvent(Event event); /*
            stateMachine.ProcessEvent(currentState_,event)
        */
    public:
        ActiveObject();
        void Run();

};
#endif /* COMPONENTS_INCLUDE_ACTIVEOBJECT */
