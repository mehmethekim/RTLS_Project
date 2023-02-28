#include "gmock/gmock.h"
#include <gtest/gtest.h>


#include "HierarchicalStateMachine.hpp"

TEST(HierarchicalStateMachine, StartState) {
    Hierarchical_State_Machine hierarchical_state_machine;
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);
}

TEST(HierarchicalStateMachine, WashHand) {
    Hierarchical_State_Machine hierarchical_state_machine;

    Message* interact_message = new Message(Message::INTERACT_WITH_PATIENT);
    hierarchical_state_machine.On_Message(interact_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::RED);

    Message* wash_hand_message = new Message(Message::WASH_HAND);
    hierarchical_state_machine.On_Message(wash_hand_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::GREEN);

    Message* timer_expired_message = new Message(Message::TIMER_EXPIRED);
    hierarchical_state_machine.On_Message(timer_expired_message);
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);


}

TEST(HierarchicalStateMachine, PatientInteraction) {
    Hierarchical_State_Machine hierarchical_state_machine;
    //Start State
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);
    EXPECT_NE(hierarchical_state_machine.Get_Current_State(), State_::RED);
    //
}

TEST(HierarchicalStateMachine, Timer) {
    Hierarchical_State_Machine hierarchical_state_machine;
    //Start State
    EXPECT_EQ(hierarchical_state_machine.Get_Current_State(), State_::YELLOW);
    EXPECT_NE(hierarchical_state_machine.Get_Current_State(), State_::RED);
    //
}
