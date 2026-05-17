#include <string>
#include <fstream>
#include <cstddef>

#include "../../engine/data/include/scene.h"


void SaveScene(const Scene& scene, const std::string& path)
{
    std::ofstream file(path);

    file << "{\n \"objects\": [\n";

    for (size_t i = 0; i < scene.objects.size(); i++)
    {
        auto& obj = scene.objects[i];

        file << "  {\n";
        file << "    \"name\": \"" << obj.name << "\",\n";
        file << "    \"position\": [" << obj.position.x << "," << obj.position.y << "," << obj.position.z << "],\n";
        file << "    \"rotation\": [" << obj.rotation.x << "," << obj.rotation.y << "," << obj.rotation.z << "],\n";
        file << "    \"scale\": [" << obj.scale.x << "," << obj.scale.y << "," << obj.scale.z << "]\n";
        file << "  }";

        if (i < scene.objects.size() - 1)
            file << ",";

        file << "\n";
    }

    file << " ]\n}";
}