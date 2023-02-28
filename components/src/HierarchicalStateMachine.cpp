#include "HierarchicalStateMachine.hpp"
#include <assert.h>
void Hierarchical_State_Machine::On_Message(const Message *p_Message)
{
    switch (p_Message->GetType())
    {
    case Message::WASH_HAND:
        p_Current_State->onWashHand(*this, p_Message);
        break;

    case Message::INTERACT_WITH_PATIENT:
        p_Current_State->onInteractWithPatient(*this, p_Message);
        break;

    case Message::INTERACT_END:
        p_Current_State->onInteractEnd(*this, p_Message);
        break;

    case Message::TIMER_EXPIRED:
        p_Current_State->onTimerExpired(*this, p_Message);
        break;

    default:
        assert("Invalid Message");
        break;
    }
}
#include <iostream>
void Hierarchical_State_Machine::Next_State(Top_State &r_State)
{
    p_Current_State = &r_State;
    // Update current_state_type_ with the new state.
    if(dynamic_cast<Red*>(p_Current_State) != nullptr){
        std::cout << "Red State" << std::endl;
        current_state_type_  = State_::RED;
    }
    //Moved Red to top because Red is also Yellow class
    else if(dynamic_cast<Yellow*>(p_Current_State) != nullptr){
        std::cout << "Yellow State" << std::endl;
        current_state_type_  = State_::YELLOW;
    }
    else if(dynamic_cast<Green*>(p_Current_State) != nullptr){
        std::cout << "Green State" << std::endl;
        current_state_type_  = State_::GREEN;
    }
    else if(dynamic_cast<Green_2*>(p_Current_State) != nullptr){
        std::cout << "Green_2 State" << std::endl;
        current_state_type_  = State_::GREEN_2;
    }
    else{
        assert("Invalid State");
    }
    
}

void Hierarchical_State_Machine::Yellow::onInteractWithPatient(
                                   Hierarchical_State_Machine &u, 
                                   const Message *p_Message)
{
    u.Next_State(u.Red_State);

}


void Hierarchical_State_Machine::Yellow::onWashHand(
                                   Hierarchical_State_Machine &u, 
                                   const Message *p_Message)
{
    u.Next_State(u.Green_State);
}


void Hierarchical_State_Machine::Red::onWashHand(
                                   Hierarchical_State_Machine &u, 
                                   const Message *p_Message)
{
    u.Next_State(u.Green_State);
}


void Hierarchical_State_Machine::Green::onTimerExpired(
                                   Hierarchical_State_Machine &u, 
                                   const Message *p_Message)
{
    u.Next_State(u.Yellow_State);
}
void Hierarchical_State_Machine::Green::onInteractWithPatient(
                                   Hierarchical_State_Machine &u, 
                                   const Message *p_Message)
{
    u.Next_State(u.Green_2_State);
}

void Hierarchical_State_Machine::Green_2::onInteractEnd(
                                   Hierarchical_State_Machine &u, 
                                   const Message *p_Message)
{
    u.Next_State(u.Red_State);
}

State_ Hierarchical_State_Machine::Get_Current_State(){
    return current_state_type_;
}