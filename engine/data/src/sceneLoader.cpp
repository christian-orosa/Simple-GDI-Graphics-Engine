#include "../include/Scene.h"
#include <fstream>
#include <sstream>

namespace SceneLoader
{
    Scene Load(const std::string& path)
    {
        Scene scene;

        std::ifstream file(path);
        if (!file.is_open())
            return scene;

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();

        size_t pos = 0;

        while ((pos = content.find("\"name\"", pos)) != std::string::npos)
        {
            SceneObject obj;

            // NAME
            size_t start = content.find("\"", pos + 6) + 1;
            size_t end = content.find("\"", start);
            obj.name = content.substr(start, end - start);

            // POSITION
            size_t pPos = content.find("\"position\"", end);
            sscanf(content.c_str() + content.find("[", pPos),
                   "[%f,%f,%f]",
                   &obj.position.x,
                   &obj.position.y,
                   &obj.position.z);

            // ROTATION
            size_t rPos = content.find("\"rotation\"", pPos);
            sscanf(content.c_str() + content.find("[", rPos),
                   "[%f,%f,%f]",
                   &obj.rotation.x,
                   &obj.rotation.y,
                   &obj.rotation.z);

            // SCALE
            size_t sPos = content.find("\"scale\"", rPos);
            sscanf(content.c_str() + content.find("[", sPos),
                   "[%f,%f,%f]",
                   &obj.scale.x,
                   &obj.scale.y,
                   &obj.scale.z);

            scene.objects.push_back(obj);

            pos = sPos;
        }

        return scene;
    }
}