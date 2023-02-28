#include "ActiveObject.hpp"
#include <iostream>

ActiveObject::ActiveObject(int id):obj_id_(id), stateMachine_(nullptr){}

// ActiveObject Run function
// void ActiveObject::Run(){
//     std::cout<<"Thread has started"<<std::endl;
//     while(true){
//         //Check if there are any events in the queue.
//         std::cout<<"Hi:"<<obj_id_<<std::endl;
//         std::this_thread::sleep_for(2000ms);
//     }
// }
State_ ActiveObject::GetCurrentState(){
    return stateMachine_->Get_Current_State();
}
void ActiveObject::NotifyEvent(Message *p_Message){
    eventQueue.push(p_Message);
}
void ActiveObject::ProcessEvent(Message *p_Message){
    stateMachine_->On_Message(p_Message);
}
