#pragma once

#include <iostream>
#include <msgpack.hpp>

#include "Types.h"

namespace MQTTVisualizationMessages {

    struct OccupancyGridMsg {

        std::string frame_id{"map"};
        unsigned time_stamp = 0;
        std::string name_space{""};
        double resolution{};              // m/cell
        size_t width{};                   // cells
        size_t height{};                  // cells
        std::vector<int8_t> data{};

        PoseXYZ pose{0.0, 0.0, 0.0};
        Orientation orientation{0.0, 0.0, 0.0, 1.0};

        MSGPACK_DEFINE_MAP(frame_id, time_stamp, name_space, resolution, width, height, data, pose, orientation)
    };
}