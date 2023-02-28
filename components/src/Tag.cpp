#include "Tag.hpp"
#include <iostream>

// Tag constructor
Tag::Tag(int id) : ActiveObject(id) {
    AddStateMachine();
}

// Tag destructor
Tag::~Tag() {}

// Tag Run function
void Tag::Run(){
    isRunning = true;
    while(isRunning){
        if(!eventQueue.empty()){
            Message* p_Message = eventQueue.front();
            eventQueue.pop();
            ProcessEvent(p_Message);
        }
    }

}
void Tag::AddStateMachine(){
    this->stateMachine_ = new Hierarchical_State_Machine();
}

void Tag::Stop(){
    isRunning = false;
}