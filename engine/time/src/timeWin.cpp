#include "../include/time.h"
#include <windows.h>
#include <iostream>

namespace Time
{
    

    

    void Init()
    {
        QueryPerformanceFrequency(&g_Frequency);
        QueryPerformanceCounter(&g_LastCounter);

        g_DeltaTime = 0.0;
        g_Time      = 0.0;
    }

    void Update()
    {
        LARGE_INTEGER current;
        QueryPerformanceCounter(&current);

        LONGLONG deltaCounts = current.QuadPart - g_LastCounter.QuadPart;
        g_LastCounter = current;

        g_DeltaTime = static_cast<double>(deltaCounts) /
                      static_cast<double>(g_Frequency.QuadPart);

        g_Time += g_DeltaTime;
    }

    double DeltaTime()
    {
        return g_DeltaTime;
    }

    double TimeSinceStart()
    {
        return g_Time;
    }
}