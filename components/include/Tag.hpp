#ifndef COMPONENTS_INCLUDE_TAG
#define COMPONENTS_INCLUDE_TAG
#include "ActiveObject.hpp"
class Tag : public ActiveObject{
    private:
    bool isRunning = false;
    public:
        Tag(int id);
        ~Tag();
        void AddStateMachine();
        void Run();
        void Stop();
};

#endif /* COMPONENTS_INCLUDE_TAG */
