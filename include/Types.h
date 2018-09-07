#pragma once

#include <msgpack.hpp>

namespace MQTTVisualizationMsgs {
    struct PoseXYZ{
        PoseXYZ() = default;
        PoseXYZ(const float x, const float y, const float z) : x(x), y(y), z(z) {}

        float x, y, z;

        MSGPACK_DEFINE(x,y,z)
    };

    struct PoseXYZI{
        PoseXYZI() = default;
        PoseXYZI(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), i(w) {}

        float x, y, z, i;

        MSGPACK_DEFINE(x,y,z,i)
    };

    struct Scale{
        Scale() = default;
        Scale(const float x, const float y, const float z) : x(x), y(y), z(z) {}

        float x=0.1, y=0.1, z=0.1;

        MSGPACK_DEFINE(x,y,z)
    };

    struct Color{
        Color() = default;
        Color(const float r, const float g, const float b, const float a) : r(r), g(g), b(b), a(a) {}

        float r=1,g=1,b=1,a=1;

        MSGPACK_DEFINE(r,g,b,a)
    };

    struct Orientation{
        Orientation() = default;
        Orientation(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

        float x=0,y=0,z=0,w=1.0;

        MSGPACK_DEFINE(x,y,z,w)
    };

    struct Properties{
    public:
        Properties() = default;
        Properties(Color color, Scale scale, std::string frame, Orientation orientation={0,0,0,1}) :
                color_(color),
                scale_(scale),
                orientation_(orientation),
                frame_(std::move(frame))
        {

        }

        Color color_{};
        Scale scale_{};
        Orientation orientation_{};
        std::string frame_ = "map";
    };
}
