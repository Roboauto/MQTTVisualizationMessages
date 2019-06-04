#pragma once

#include <iostream>
#include <msgpack.hpp>

namespace MQTTVisualizationMessages {

    struct MapPosition {
        MapPosition() = default;
        MapPosition(const float x_, const float y_, const float z_) : x(x_), y(y_), z(z_) {}

        float x=0, y=0, z=0;

        MSGPACK_DEFINE_MAP(x,y,z)
    };

    struct MapOrientation{
        MapOrientation() = default;
        MapOrientation(const float x_, const float y_, const float z_, const float w_) : x(x_), y(y_), z(z_), w(w_) {}

        float x=0,y=0,z=0,w=1.0;

        MSGPACK_DEFINE_MAP(x,y,z,w)
    };

    struct OccupancyGridMsg {

        std::string frame_id{"map"};
        unsigned time_stamp = 0;
        std::string name_space{""};
        double resolution{};              // m/cell
        size_t width{};                   // cells
        size_t height{};                  // cells
        std::vector<int8_t> data{};

        MapPosition pose{0.0, 0.0, 0.0};
        MapOrientation orientation{0.0, 0.0, 0.0, 1.0};

        MSGPACK_DEFINE_MAP(frame_id, time_stamp, name_space, resolution, width, height, data, pose, orientation)
    };
}