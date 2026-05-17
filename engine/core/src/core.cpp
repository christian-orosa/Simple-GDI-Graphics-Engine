#include "../include/core.h"
#include "../../window/include/thewindow.h"
#include "../../time/include/time.h"
#include "../../graphics/graphics.h"
#include "../../game/include/game.h"

namespace Core
{
    static bool g_Running = true;

    void Init(HINSTANCE hInstance)
    {
        if (!Window::Create(hInstance, 500, 500, L"totalEditor"))
        {
            g_Running = false;
            return;
        }

        Time::Init();

        if (!Graphics::Init(Window::GetHandle()))
        {
            g_Running = false;
            return;
        }
    }

    void Run()
    {
        while (g_Running)
        {
            Window::PollEvents();

            if (Window::ShouldClose())
                g_Running = false;

            float deltaTime = (float)Time::g_DeltaTime;

            Graphics::Clear({0, 0, 0});

            Game::Update(deltaTime);

            Graphics::Display();
        }
    }

    void Shutdown()
    {
        Graphics::Shutdown();
        Window::Destroy();
    }
}