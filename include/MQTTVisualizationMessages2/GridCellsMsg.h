#pragma once

#include <msgpack.hpp>

namespace MQTTVisualizationMessages2 {
    struct GridCells {
        static constexpr const char* typeName = "nav_msgs/GridCells";

        MSGPACK_DEFINE()
    };

}
