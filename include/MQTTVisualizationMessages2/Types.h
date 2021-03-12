#pragma once

#include <msgpack.hpp>


namespace MQTTVisualizationMessages2 {
    enum Action {
        Add = 0,
        Delete = 2,
        Delete_All = 3
    };

    struct Orientation {
        Orientation() = default;
        Orientation(const float x_, const float y_, const float z_, const float w_)
                    : x(x_)
                    , y(y_)
                    , z(z_)
                    , w(w_) {
        }

        float x = 0, y = 0, z = 0, w = 1.0;

        MSGPACK_DEFINE(x, y, z, w)
    };

    struct Point {
        Point() = default;
        Point(const float x_, const float y_, const float z_)
                    : x(x_)
                    , y(y_)
                    , z(z_) {
        }

        float x, y, z;

        MSGPACK_DEFINE(x, y, z)
    };

    struct Pose {
        Point point{};
        Orientation orientation{};

        MSGPACK_DEFINE(point, orientation)
    };

    struct PointXYZI {
        PointXYZI() = default;
        PointXYZI(const float x_, const float y_, const float z_, const float w_)
                    : x(x_)
                    , y(y_)
                    , z(z_)
                    , i(w_) {
        }

        float x, y, z, i;

        MSGPACK_DEFINE(x, y, z, i)
    };

    struct Scale {
        Scale() = default;
        Scale(const float x_, const float y_, const float z_)
                    : x(x_)
                    , y(y_)
                    , z(z_) {
        }

        float x = 0.1f, y = 0.1f, z = 0.1f;

        MSGPACK_DEFINE(x, y, z)
    };

    struct Color {
        Color() = default;
        Color(const float r_, const float g_, const float b_, const float a_)
                    : r(r_)
                    , g(g_)
                    , b(b_)
                    , a(a_) {
        }

        float r = 1, g = 1, b = 1, a = 1;

        MSGPACK_DEFINE(r, g, b, a)
    };
}
