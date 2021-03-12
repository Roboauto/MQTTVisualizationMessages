#pragma once

#include <msgpack.hpp>

namespace MQTTVisualizationMessages2 {
    struct Topic {
        std::string name{};
        std::string type{};

        MSGPACK_DEFINE(name, type)
    };

    struct Topics {
        static constexpr const char* typeName = "Topics";

        std::vector<Topic> topics{};

        MSGPACK_DEFINE(topics)
    };

}
