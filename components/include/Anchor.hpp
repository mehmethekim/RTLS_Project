#ifndef INC_ANCHOR
#define INC_ANCHOR
#include "ActiveObject.hpp"
class Anchor: public ActiveObject{
    private:
        int anchor_id_;
    public:
        Anchor(int id);
        ~Anchor();
        void AddStateMachine();
        void Run();
};

#endif /* INC_ANCHOR */
