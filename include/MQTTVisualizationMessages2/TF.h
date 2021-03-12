#pragma once

#include <msgpack.hpp>
#include "Types.h"

namespace MQTTVisualizationMessages2 {
    struct TF {
        static constexpr const char* typeName = "TF";
        std::string from_frame{};
        std::string to_frame{};
        Time time{};

        Point vector{};
        Orientation rotation{};

        MSGPACK_DEFINE(from_frame, to_frame, time, vector, rotation)
    };

}