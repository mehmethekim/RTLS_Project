#include "StateMachine.hpp"
#include <algorithm>
using namespace std;

StateMachine::StateMachine(State start_state):current_state_{start_state}{
    AddState(start_state);
}
/**
 * @brief Add the new_state to the vector table if it does not exist.
 * 
 * @param new_state 
 */
void StateMachine::AddState(State new_state){
    auto it = std::find_if(StateTable.begin(), StateTable.end(), [new_state](const auto& state)
    {
        return state.name_ == new_state.name_;
    });
    if (it != StateTable.end())
    {
        StateTable.push_back(new_state);
    }
}
void StateMachine::AddEvent(Event new_event){
    auto it = std::find_if(EventTable.begin(), EventTable.end(), [new_event](const auto& event)
    {
        return event.name_ == new_event.name_;
    });
    if (it != EventTable.end())
    {
        EventTable.push_back(new_event);
    }
}
void StateMachine::AddTransition(State old_state, State new_state, Event event){
    //if states does not exist, add to vector tables.
    AddState(old_state);
    AddState(new_state);
    AddEvent(event);
    tuple<State,Event,State> new_transition = make_tuple(old_state,event,new_state);
    TransitionTable.push_back(new_transition);
}
State StateMachine::ProcessEvent(Event event){
    //iterate over transition table. Find current state and incoming event tuple.
    auto it = std::find_if(TransitionTable.begin(), TransitionTable.end(), [this,event](const auto& tuple)
    {
        return (get<0>(tuple)).name_== (this->current_state_).name_
        && 
        ((get<1>(tuple)).name_ ==event.name_);   
    });

    if (it != TransitionTable.end())
    {  
        //Transition
        auto index = std::distance(TransitionTable.begin(), it);
        current_state_ = get<2>(TransitionTable[index]);
    }
    return current_state_;
}

State StateMachine::GetCurrentState(){
    return current_state_;
}