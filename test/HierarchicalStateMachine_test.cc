#include "gmock/gmock.h"
#include <gtest/gtest.h>


#include "HierarchicalStateMachine.hpp"

TEST(HierarchicalStateMachine, StartState) {
    Hierarchical_State_Machine hierarchical_state_machine;
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);
}

TEST(HierarchicalStateMachine, Timer) {
    Hierarchical_State_Machine hierarchical_state_machine;

    Message* wash_hand_message = new Message(Message::WASH_HAND);
    Message* timer_expired_message = new Message(Message::TIMER_EXPIRED);

    hierarchical_state_machine.On_Message(wash_hand_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::GREEN);

    hierarchical_state_machine.On_Message(timer_expired_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);

}

TEST(HierarchicalStateMachine, WashBeforeInteraction) {
    Hierarchical_State_Machine hierarchical_state_machine;

    Message* wash_hand_message = new Message(Message::WASH_HAND);
    Message* timer_expired_message = new Message(Message::TIMER_EXPIRED);
    Message* interact_message = new Message(Message::INTERACT_WITH_PATIENT);


    hierarchical_state_machine.On_Message(wash_hand_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::GREEN);

    hierarchical_state_machine.On_Message(interact_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::GREEN_2);

    Message* interact_end_message = new Message(Message::INTERACT_END);
    hierarchical_state_machine.On_Message(interact_end_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::RED);

    hierarchical_state_machine.On_Message(wash_hand_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::GREEN);

     
    hierarchical_state_machine.On_Message(timer_expired_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);
}

TEST(HierarchicalStateMachine, InteractAndWashHand) {
    Hierarchical_State_Machine hierarchical_state_machine;
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);

    Message* wash_hand_message = new Message(Message::WASH_HAND);
    Message* interact_message = new Message(Message::INTERACT_WITH_PATIENT);
    Message* timer_expired_message = new Message(Message::TIMER_EXPIRED);

    hierarchical_state_machine.On_Message(interact_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::RED);
    EXPECT_NE(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);

    
    hierarchical_state_machine.On_Message(wash_hand_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::GREEN);

   
    hierarchical_state_machine.On_Message(timer_expired_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);

}



