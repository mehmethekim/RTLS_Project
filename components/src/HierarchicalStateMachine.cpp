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
void Hierarchical_State_Machine::Next_State(Top_State &r_State)
{
    p_Current_State = &r_State;
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



#include <iostream>
State_ Hierarchical_State_Machine::Get_Current_State(){
    return current_state_type_;
}