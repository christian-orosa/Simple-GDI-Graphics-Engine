#pragma once
#include <vector>
#include <string>
#include "../../maths/include/Vector3D.h"

struct SceneObject
{
    std::string name;
    bbe::Vector3D position;
    bbe::Vector3D rotation;
    bbe::Vector3D scale;
};

struct Scene
{
    std::vector<SceneObject> objects;
};