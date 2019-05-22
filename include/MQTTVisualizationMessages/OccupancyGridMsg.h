#pragma once

#include <iostream>
#include <msgpack.hpp>

namespace MQTTVisualizationMessages {

    struct OccupancyGridMsg {

        std::string frame_id{"map"};
        unsigned time_stamp = 0;
        std::string name_space{""};
        double resolution{};              // m/cell
        size_t width{};                   // cells
        size_t height{};                  // cells
        std::vector<int8_t> data{};

        MSGPACK_DEFINE(frame_id, time_stamp, name_space, resolution, width, height, data)
    };
}