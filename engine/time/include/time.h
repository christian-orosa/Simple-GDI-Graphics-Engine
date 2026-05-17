#pragma once

#include <windows.h>
#include <iostream>

namespace Time
{
	static LARGE_INTEGER g_Frequency;
    static LARGE_INTEGER g_LastCounter;

    static double g_DeltaTime = 0.0;
    static double g_Time = 0.0;
	
	
    void Init();
    void Update();

    double DeltaTime();
    double TimeSinceStart();
}

