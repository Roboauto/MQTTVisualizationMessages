#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <array>

#include <msgpack.hpp>

#include "Types.h"
#include "Time.h"

namespace MQTTVisualizationMessages2 {
    enum class MarkerType {
        Arrow = 0,
        Cube,
        Sphere,
        Cylinder,
        LineStrip,
        LineList,
        CubeList,
        SphereList,
        Points,
        TextViewFacing,
        MeshResource,
        TriangleList
    };


    enum class MarkerAction {
        Add,
        Modify,
        Delete,
        DelteAll
    };

    struct MarkerMsg {
        static constexpr const char* typeName = "MarkerMsg";

        int sequence_id = 0;
        std::string frame{};
        Time time{};

        std::string name_space{""};

        int id = 0;
        MarkerType type{};
        MarkerAction action{};

        Point position{};          //position
        Orientation orientation{}; //quaternion
        Scale scale{};
        Color color{};

        double lifetime = 0;

        bool frame_locked = false;

        std::vector<Point> points{};
        std::vector<Color> colors{};

        std::string text{""};
        std::string mesh_resource{""};
        bool mesh_use_embedded_materials = false;

        MSGPACK_DEFINE(sequence_id, frame, time, name_space, id, type, action, position, orientation, scale,
                       color, lifetime, frame_locked, points, colors, text, mesh_resource, mesh_use_embedded_materials)
    };

    struct MarkerArrayMsg {
        static constexpr const char* typeName = "MarkerArrayMsg";
        std::vector<MarkerMsg> markers;
        MSGPACK_DEFINE(markers)
    };
}

MSGPACK_ADD_ENUM(MQTTVisualizationMessages2::MarkerAction)
MSGPACK_ADD_ENUM(MQTTVisualizationMessages2::MarkerType)
