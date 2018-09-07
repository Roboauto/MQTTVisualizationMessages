#pragma once

#include <vector>

#include <msgpack.hpp>

namespace MQTTVisualizationMsgs {
    enum PxlFormat {
        RGB,
        RGBA
    };

    struct Image {
        unsigned int width;
        unsigned int height;

        unsigned char pxlFormat;

        std::vector<unsigned char> data;

        MSGPACK_DEFINE(width, height, pxlFormat, data)
    };
}