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
    State start_state;
    this->stateMachine_ = new StateMachine(start_state);
    
    State checkpoint_one;
    State checkpoint_two;
    State checkpoint_three;

    Event go_to_state_one;
    Event go_to_state_two;
    Event go_to_state_three;

    this->stateMachine_->AddTransition(start_state, checkpoint_one, go_to_state_one);
    this->stateMachine_->AddTransition(checkpoint_one, checkpoint_two, go_to_state_two);
    this->stateMachine_->AddTransition(checkpoint_two, checkpoint_three, go_to_state_three);
    this->stateMachine_->AddTransition(checkpoint_three, checkpoint_one, go_to_state_one);

    currentState_ = start_state;
}