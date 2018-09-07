#pragma once

#include <vector>

#include <msgpack.hpp>

namespace MQTTVisualizationMsgs {
    enum PxlFormat {
        RGB,
        RGBA
    };

    struct Image {
        unsigned int width = 0;
        unsigned int height = 0;

        unsigned char pxlFormat = 0;

        std::vector<unsigned char> data;

        MSGPACK_DEFINE(width, height, pxlFormat, data)
    };
}