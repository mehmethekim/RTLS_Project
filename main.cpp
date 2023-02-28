#include <iostream>
#include "components/include/Tag.hpp"
#include "components/include/StateMachine.hpp"
#include "components/include/ActiveObject.hpp"
#include "components/include/HierarchicalStateMachine.hpp"
int main(){
    std::cout<<"Initializing..."<<std::endl;

    Hierarchical_State_Machine hierarchical_state_machine;

    std::cout<<(int)hierarchical_state_machine.Get_Current_State()<<std::endl;
    
    return 0;
}
