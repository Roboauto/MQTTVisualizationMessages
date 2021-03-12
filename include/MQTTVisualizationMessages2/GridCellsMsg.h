#pragma once

#include <msgpack.hpp>

namespace MQTTVisualizationMessages2 {
    struct GridCells {
        static constexpr const char* typeName = "GridCells";

        MSGPACK_DEFINE()
    };

}
