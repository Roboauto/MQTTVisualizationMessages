#pragma once

#include <iostream>
#include <msgpack.hpp>

#include "Types.h"

namespace MQTTVisualizationMsgs {

    typedef std::pair<std::string, std::vector<float>> Channel;

    struct PointCloudMsg {
        std::string frame_id{"map"};
        unsigned time_stamp = 0;

        std::string name_space{""};

        std::vector< PoseXYZ > points{};
        std::vector< Channel > channels{};

        MSGPACK_DEFINE(frame_id, time_stamp, name_space, points, channels)
    };
}
