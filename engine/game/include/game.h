#pragma once

#include <iostream>



namespace Game
{
	
	static bool initialized = false;
	
    void Init();
	void FixedUpdate(double fixedDeltaTime);
    void Update(double deltaTime);
    void Render();
    void Shutdown();
}
