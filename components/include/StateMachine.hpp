#ifndef COMPONENTS_INCLUDE_STATEMACHINE
#define COMPONENTS_INCLUDE_STATEMACHINE
#include <string> 
#include <tuple>
#include <vector>

using namespace std;

struct State{
    string name_;
};

struct Event{
        string name_;
};

class StateMachine{
private:
    vector<tuple<State,Event,State>> TransitionTable;//(old_state,incoming_evt->new_state)
    vector<State> StateTable;
    vector<Event> EventTable;
    State current_state_;
    void AddState(State new_state);
    void AddEvent(Event new_event);
    
public:
    StateMachine(State start_state);
    void AddTransition(State old_state, State new_state, Event event);
    State ProcessEvent(Event event);
    State GetCurrentState();
    ~StateMachine() {}
};
#endif /* COMPONENTS_INCLUDE_STATEMACHINE */
