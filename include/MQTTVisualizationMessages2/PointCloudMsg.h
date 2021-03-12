#pragma once

#include <iostream>
#include <msgpack.hpp>

#include "Types.h"

namespace MQTTVisualizationMessages2 {

    typedef std::pair<std::string, std::vector<float>> Channel;

    struct PointCloudMsg {
        static constexpr const char* typeName = "PointCloudMsg";

        int sequence_id = 0;
        std::string frame{};
        Time time{};

        std::string name_space{};

        std::vector<Point> points{};
        std::vector<Channel> channels{};

        MSGPACK_DEFINE(frame, time, name_space, points, channels)
    };
}
