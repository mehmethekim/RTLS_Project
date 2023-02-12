#include <iostream>
#include "components/include/Tag.hpp"
#include "components/include/StateMachine.hpp"
int main(){
    std::cout<<"Initializing..."<<std::endl;

    // State red_state = {"RED"};
    // State yellow_state = {"YELLOW"};
    // State green_state = {"GREEN"};

    // Event event_one = {"go_to_yellow"};
    // Event event_two = {"go_to_red"};
    // Event event_three = {"go_to_green"};

    // StateMachine state_machine(red_state);
    // State temp_state;
    // state_machine.AddTransition(red_state,yellow_state,event_one);
    // state_machine.AddTransition(yellow_state,red_state,event_two);
    // state_machine.AddTransition(yellow_state,green_state,event_three);

    // temp_state = state_machine.ProcessEvent(event_two);
    // std::cout<<"Expected State: RED,Result: "<<temp_state.name_<<std::endl;
    
    // temp_state = state_machine.ProcessEvent(event_one);
    // std::cout<<"Expected State: YELLOW,Result: "<<temp_state.name_<<std::endl;

    // temp_state = state_machine.ProcessEvent(event_two);
    // std::cout<<"Expected State: RED,Result: "<<temp_state.name_<<std::endl;

    // temp_state = state_machine.ProcessEvent(event_one);
    // std::cout<<"Expected State: YELLOW,Result: "<<temp_state.name_<<std::endl;

    // temp_state = state_machine.ProcessEvent(event_three);
    // std::cout<<"Expected State: GREEN,Result: "<<temp_state.name_<<std::endl;

    // temp_state = state_machine.ProcessEvent(event_two);
    // std::cout<<"Expected State: GREEN,Result: "<<temp_state.name_<<std::endl;
    return 0;
}