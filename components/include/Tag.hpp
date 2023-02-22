#ifndef INC_TAG
#define INC_TAG
#include "ActiveObject.hpp"
class Tag : public ActiveObject{
    public:
        Tag(int id);
        ~Tag();
        void AddStateMachine();
        void Run();
};

#endif /* INC_TAG */
