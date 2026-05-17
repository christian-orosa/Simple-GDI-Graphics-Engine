#pragma once
#include <windows.h>

namespace Graphics
{
    struct Color
    {
        unsigned char r, g, b;

        Color(unsigned char r, unsigned char g, unsigned char b)
            : r(r), g(g), b(b) {}
    };

    bool Init(HWND hwnd);
	void Resize(int width, int height);
    void Clear(const Color& color);

    void DrawRect(int x, int y, int width, int height, const Color& color);
    void DrawLine(int x1, int y1, int x2, int y2, const Color& color);
    void DrawCircle(int x, int y, int radius, const Color& color);

    void Display();
    void Shutdown();
}