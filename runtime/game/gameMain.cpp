#include "../../engine/data/include/scene.h"

int main()
{
    Scene scene = SceneLoader::Load("projects/miJuego/scenes/level01.json");

    for (auto& obj : scene.objects)
    {
        // Ejemplo: dibujar algo
        // (de momento simple)
        printf("Object: %s at (%f, %f, %f)\n",
               obj.name.c_str(),
               obj.position.x,
               obj.position.y,
               obj.position.z);
    }

    return 0;
}