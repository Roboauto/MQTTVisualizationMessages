#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <array>

#include <msgpack.hpp>

#include "Types.h"


namespace MQTTVisualizationMessages {
  enum MarkerType {
    ARROW = 0,
    CUBE,
    SPEHERE,
    CYLINDER,
    LINE_STRIP,
    LINE_LIST,
    CUBE_LIST,
    SPHERE_LIST,
    POINTS,
    TEXT_VIEW_FACING,
    MESH_RESOURCE,
    TRIANGLE_LIST
  };

  struct MarkerMsg {
    int sequence_id = 0;
    std::string frame_id{"map"};
    unsigned time_stamp = 0;

    std::string name_space{""};

    int id = 0;
    int type = 0;
    int action = 0;

    PoseXYZ position{}; //position
    Orientation orientation{}; //quaternion
    Scale scale{};
    Color color{};

    double lifetime = 0;

    bool frame_locked = false;

    std::vector<PoseXYZ> points{};
    std::vector<Color> colors{};

    std::string text{""};
    std::string mesh_resource{""};
    bool mesh_use_embedded_materials = false;

    MSGPACK_DEFINE (sequence_id, frame_id, time_stamp, name_space, id, type, action, position, orientation, scale,
                    color, lifetime, frame_locked, points, colors, text, mesh_resource, mesh_use_embedded_materials)

  };

  struct MarkerArrayMsg {
    std::vector<MarkerMsg> markers;
    MSGPACK_DEFINE (markers)
  };
}
