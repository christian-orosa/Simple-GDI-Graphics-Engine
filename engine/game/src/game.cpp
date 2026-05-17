#include "../include/game.h"
#include "../../graphics/graphics.h"
#include <cmath>


namespace Game
{
    // Estado interno del juego (simple por ahora)
    static float g_Time = 0.0f;

    void Init()
    {
        g_Time = 0.0f;
    }

    void Update(float deltaTime)
    {
        g_Time += deltaTime;

        // Color dinámico simple (para verificar que todo funciona)
        int r = (int)( (sin(g_Time) * 0.5f + 0.5f) * 255 );
        int g = (int)( (sin(g_Time + 2.0f) * 0.5f + 0.5f) * 255 );
        int b = (int)( (sin(g_Time + 4.0f) * 0.5f + 0.5f) * 255 );

        Graphics::Clear({ r, g, b });

        // Aquí iría:
        // - input
        // - lógica
        // - entidades
        // - físicas
    }

    void Shutdown()
    {
        // Limpieza futura (recursos, memoria, etc)
    }
}