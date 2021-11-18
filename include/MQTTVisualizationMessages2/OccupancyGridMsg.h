#pragma once

#include <iostream>
#include <msgpack.hpp>

#include "Types.h"

namespace MQTTVisualizationMessages2 {

    struct OccupancyGridMsg {
        static constexpr const char* typeName = "nav_msgs/OccupancyGrid";

        int sequence_id = 0;
        std::string frame{};
        Time time{};

        double resolution{}; // m/cell
        size_t width{};      // cells
        size_t height{};     // cells
        std::vector<int8_t> data{};

        Point pose{0.0, 0.0, 0.0};
        Orientation orientation{0.0, 0.0, 0.0, 1.0};

        MSGPACK_DEFINE_MAP(frame, time , resolution, width, height, data, pose, orientation)
    };
}