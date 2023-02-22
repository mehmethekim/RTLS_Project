#include <iostream>
#include "components/include/Tag.hpp"
#include "components/include/StateMachine.hpp"
#include "components/include/ActiveObject.hpp"
int main(){
    std::cout<<"Initializing..."<<std::endl;

    Tag * obj1 = new Tag(1);
    // Tag * obj2 = new Tag(2);
    // std::thread th1(&Tag::Run, obj1);
    // std::thread th2(&Tag::Run, obj2);
    // th1.join(); 
    // th2.join();
    
    return 0;
}
