#include "gmock/gmock.h"
#include <gtest/gtest.h>


#include "StateMachine.hpp"

// class MockStateMachine : public StateMachine
// {
// public:
//     MockStateMachine(State start_state) : StateMachine(start_state) {}
//     MOCK_METHOD(void,AddState,(State new_state), (override));
//     MOCK_METHOD(void,AddEvent,(Event new_event), (override));
//     MOCK_METHOD(void,AddTransition,(State old_state, State new_state, Event event), (override));
//     MOCK_METHOD(State,ProcessEvent,(Event event), (override));
// };

TEST(StateMachineTest, ChangeStateCorrectly) {
  State start_state{"start"};

  State red_state = {"RED"};
  State yellow_state = {"YELLOW"};
  State green_state = {"GREEN"};

  Event event_one = {"go_to_yellow"};
  Event event_two = {"go_to_red"};
  Event event_three = {"go_to_green"};

  StateMachine state_machine(start_state);
  state_machine.AddTransition(start_state,red_state,event_two);
  state_machine.AddTransition(red_state,yellow_state,event_one);
  state_machine.AddTransition(yellow_state,red_state,event_two);
  state_machine.AddTransition(yellow_state,green_state,event_three);

  EXPECT_EQ((state_machine.ProcessEvent(event_two)).name_ , "RED");
  EXPECT_EQ((state_machine.ProcessEvent(event_one)).name_ , "YELLOW");
  EXPECT_EQ((state_machine.ProcessEvent(event_two)).name_ , "RED");
  EXPECT_EQ((state_machine.ProcessEvent(event_one)).name_ , "YELLOW");
  EXPECT_EQ((state_machine.ProcessEvent(event_three)).name_ , "GREEN");
  EXPECT_EQ((state_machine.ProcessEvent(event_two)).name_ , "GREEN");


}
