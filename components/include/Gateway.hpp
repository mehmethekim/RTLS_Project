#ifndef COMPONENTS_INCLUDE_GATEWAY
#define COMPONENTS_INCLUDE_GATEWAY

#include "Tag.hpp"
#include "Anchor.hpp"

#include <mqtt/async_client.h>
class Gateway{
    private:
        Tag* TagList;
        Anchor* AnchorList;

        void AddTag(int id);
        void AddAnchor(int id);
        void AddMqttPublisher();
        void AddMqttSubscriber();

    public:
        Gateway();
        ~Gateway();
        void Run();
};

#endif /* COMPONENTS_INCLUDE_GATEWAY */
