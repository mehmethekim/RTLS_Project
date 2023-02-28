#ifndef COMPONENTS_INCLUDE_ACTIVEOBJECT
#define COMPONENTS_INCLUDE_ACTIVEOBJECT
#include "HierarchicalStateMachine.hpp"
#include <queue>
#include <thread>
  
using namespace std;
  
/**
 * @brief Active objects can hold states, can receive events and act accordingly.
 * It has a state machine that holds all the states and transitions. 
 * Event pool to hold incoming events, that can build up. 
 * A thread will run to consume events as they come.
 * 
 */
class ActiveObject{
    protected:
        int obj_id_;
        Hierarchical_State_Machine* stateMachine_;
        queue<Message*> eventQueue; //Queue that holds incoming events.
        void ProcessEvent(Message *p_Message);
    public:
        ActiveObject(int id);
        State_ GetCurrentState();
        void NotifyEvent(Message *p_Message);
        // virtual void Run();
};
#endif /* COMPONENTS_INCLUDE_ACTIVEOBJECT */
