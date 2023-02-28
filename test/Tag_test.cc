#include "gmock/gmock.h"
#include <gtest/gtest.h>


#include "Tag.hpp"
#include<unistd.h>             
TEST(TagTest, StartState) {
    Tag* tag = new Tag(1);
    EXPECT_EQ(tag->GetCurrentState(), State_::YELLOW);
}
TEST(TagTest, WashBeforeInteraction) {
    Tag* tag = new Tag(1);
    std::thread th1(&Tag::Run, tag);

    Message* wash_hand_message = new Message(Message::WASH_HAND);
    Message* timer_expired_message = new Message(Message::TIMER_EXPIRED);
    Message* interact_message = new Message(Message::INTERACT_WITH_PATIENT);
    Message* interact_end_message = new Message(Message::INTERACT_END);

    tag->NotifyEvent(wash_hand_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::GREEN);

    tag->NotifyEvent(interact_message);usleep(100);
    
    EXPECT_EQ(tag->GetCurrentState(), State_::GREEN_2);

    tag->NotifyEvent(interact_end_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::RED);

    tag->NotifyEvent(wash_hand_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::GREEN);

    tag->NotifyEvent(timer_expired_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::YELLOW);

    tag->Stop();
    th1.join(); 
}

TEST(TagTest, InteractAndWashHand) {
    Tag* tag = new Tag(1);
    std::thread th1(&Tag::Run, tag);

    Message* wash_hand_message = new Message(Message::WASH_HAND);
    Message* timer_expired_message = new Message(Message::TIMER_EXPIRED);
    Message* interact_message = new Message(Message::INTERACT_WITH_PATIENT);
    Message* interact_end_message = new Message(Message::INTERACT_END);

    tag->NotifyEvent(interact_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::RED);
    EXPECT_NE(tag->GetCurrentState(), State_::YELLOW);

    tag->NotifyEvent(wash_hand_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::GREEN);

    tag->NotifyEvent(timer_expired_message);usleep(100);
    EXPECT_EQ(tag->GetCurrentState(), State_::YELLOW);

    tag->Stop();
    th1.join();

}