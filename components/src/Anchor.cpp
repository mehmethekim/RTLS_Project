#include "Anchor.hpp"
#include <iostream>
// Tag constructor
Anchor::Anchor(int id) : ActiveObject(id) , anchor_id_{ id } { 
    AddStateMachine();
}

// Tag destructor
Anchor::~Anchor() {}

// Tag Run function
void Anchor::Run(){
    //Pre thread function.
    std::cout << "Thread has started" << std::endl;

}
void Anchor::AddStateMachine(){

}
