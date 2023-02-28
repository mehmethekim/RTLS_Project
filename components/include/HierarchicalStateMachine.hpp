#ifndef COMPONENTS_INCLUDE_HIERARCHICALSTATEMACHINE
#define COMPONENTS_INCLUDE_HIERARCHICALSTATEMACHINE
#include <stdint.h>
class Message{
    
    public:
   
    enum Event: uint8_t{
        WASH_HAND = 0,
        INTERACT_WITH_PATIENT,
        INTERACT_END,
        TIMER_EXPIRED
    };
    Event GetType() const {return type_;}
    Message(Event type):type_{type}{}
    
    private:
    
    Event type_; 
};
enum class State_ : uint8_t
    {
        YELLOW = 0,
        RED,
        GREEN,
        GREEN_2
    };
class Hierarchical_State_Machine
{

    class Top_State
    {
    public:
        // ALL EVENTS IN THE OBJECT
        // virtual void onStart(Hierarchical_State_Machine &u,
        //                      const Message *p_Message) {}

        virtual void onWashHand(Hierarchical_State_Machine &u,
                                const Message *p_Message) {}

        virtual void onInteractWithPatient(Hierarchical_State_Machine &u,
                                           const Message *p_Message) {}
        virtual void onInteractEnd(Hierarchical_State_Machine &u,
                                   const Message *p_Message) {}

        virtual void onTimerExpired(Hierarchical_State_Machine &u,
                                    const Message *p_Message) {}
    };
    friend Top_State;

    class Yellow : public Top_State
    {
    public:
        void onInteractWithPatient(Hierarchical_State_Machine &u,
                                   const Message *p_Message);
        void onWashHand(Hierarchical_State_Machine &u,
                        const Message *p_Message);
    };
    friend Yellow;

    class Red : public Yellow
    {
    public:
        void onWashHand(Hierarchical_State_Machine &u,
                        const Message *p_Message);
    };
    friend Red;

    class Green : public Top_State
    {
    public:
        void onTimerExpired(Hierarchical_State_Machine &u,
                            const Message *p_Message);
        void onInteractWithPatient(Hierarchical_State_Machine &u,
                            const Message *p_Message);
    };
    friend Green;

    class Green_2 : public Top_State
    {
    public:
        void onInteractEnd(Hierarchical_State_Machine &u,
                                   const Message *p_Message);
    };
    friend Green_2;

private:
    Yellow Yellow_State;
    Red Red_State;
    Green Green_State;
    Green_2 Green_2_State;
    

    void Next_State(Top_State &r_State);

    Top_State *p_Current_State = &Yellow_State;
    State_ current_state_type_ = State_::YELLOW;

public:
    void On_Message(const Message *p_Message);
    State_ Get_Current_State();
};



#endif /* COMPONENTS_INCLUDE_HIERARCHICALSTATEMACHINE */
