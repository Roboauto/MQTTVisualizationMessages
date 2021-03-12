#pragma once

#include <msgpack.hpp>

namespace MQTTVisualizationMessages2 {
    struct Time {
        static constexpr const char* typeName = "Time";

        unsigned int sec;
        unsigned int nsec;
        MSGPACK_DEFINE(sec, nsec)
    };

}
