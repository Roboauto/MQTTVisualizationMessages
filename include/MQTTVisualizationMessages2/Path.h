#pragma once

#include <msgpack.hpp>

#include "Types.h"
#include <vector>

namespace MQTTVisualizationMessages2 {

    struct Path {
        static constexpr const char* typeName = "Path";

        int sequence_id = 0;
        std::string frame{};
        Time time{};

        std::vector<Pose> poses{};
        MSGPACK_DEFINE(frame, time, poses)
    };
}