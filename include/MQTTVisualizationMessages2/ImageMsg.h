#pragma once

#include "Time.h"

#include <vector>
#include <msgpack.hpp>

namespace MQTTVisualizationMessages2 {
    enum PxlFormat {
        RGB,
        RGBA
    };

    struct Image {
        static constexpr const char* typeName = "Image";

        int sequence_id = 0;
        std::string frame{};
        Time time{};

        unsigned int width = 0;
        unsigned int height = 0;

        unsigned char pxlFormat = 0;

        std::vector<unsigned char> data{};

        MSGPACK_DEFINE(width, height, pxlFormat, data)
    };
}