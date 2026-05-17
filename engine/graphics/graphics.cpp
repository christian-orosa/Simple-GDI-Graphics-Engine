#include "graphics.h"

namespace Graphics
{
    static HWND s_hwnd = nullptr;
    static HDC s_hdc = nullptr;
    static HDC s_backBufferDC = nullptr;
    static HBITMAP s_backBufferBitmap = nullptr;

    static int s_width = 800;
    static int s_height = 600;

    bool Init(HWND hwnd)
    {
        s_hwnd = hwnd;
        s_hdc = GetDC(hwnd);

        RECT rect;
        GetClientRect(hwnd, &rect);
        s_width = rect.right - rect.left;
        s_height = rect.bottom - rect.top;

        s_backBufferDC = CreateCompatibleDC(s_hdc);
        s_backBufferBitmap = CreateCompatibleBitmap(s_hdc, s_width, s_height);

        SelectObject(s_backBufferDC, s_backBufferBitmap);

        return true;
    }
	
	void Resize(int width, int height)
	{
		if (width == 0 || height == 0)
			return;

		s_width = width;
		s_height = height;

		// Borrar buffer anterior
		if (s_backBufferBitmap)
		{
			DeleteObject(s_backBufferBitmap);
			s_backBufferBitmap = nullptr;
		}

		// Crear nuevo buffer
		s_backBufferBitmap = CreateCompatibleBitmap(s_hdc, s_width, s_height);
		SelectObject(s_backBufferDC, s_backBufferBitmap);
	}

    void Clear(const Color& color)
	{
		HBRUSH brush = CreateSolidBrush(RGB(color.r, color.g, color.b));

		RECT rect = { 0, 0, s_width, s_height };
		FillRect(s_backBufferDC, &rect, brush);

		DeleteObject(brush);
	}

    void DrawRect(int x, int y, int width, int height, const Color& color)
	{
		RECT rect = { x, y, x + width, y + height };

		HBRUSH brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
		FillRect(s_backBufferDC, &rect, brush);

		DeleteObject(brush);
	}
	
	void DrawLine(int x1, int y1, int x2, int y2, const Color& color)
	{
		HPEN pen = CreatePen(PS_SOLID, 1, RGB(color.r, color.g, color.b));
		HPEN oldPen = (HPEN)SelectObject(s_backBufferDC, pen);

		MoveToEx(s_backBufferDC, x1, y1, nullptr);
		LineTo(s_backBufferDC, x2, y2);

		SelectObject(s_backBufferDC, oldPen);
		DeleteObject(pen);
	}
	
	void DrawCircle(int x, int y, int radius, const Color& color)
	{
		HBRUSH brush = CreateSolidBrush(RGB(color.r, color.g, color.b));
		HBRUSH oldBrush = (HBRUSH)SelectObject(s_backBufferDC, brush);

		Ellipse(
			s_backBufferDC,
			x - radius,
			y - radius,
			x + radius,
			y + radius
		);

		SelectObject(s_backBufferDC, oldBrush);
		DeleteObject(brush);
	}

    void Display()
    {
        BitBlt(
            s_hdc,
            0, 0,
            s_width, s_height,
            s_backBufferDC,
            0, 0,
            SRCCOPY
        );
    }

    void Shutdown()
    {
        if (s_backBufferBitmap)
        {
            DeleteObject(s_backBufferBitmap);
            s_backBufferBitmap = nullptr;
        }

        if (s_backBufferDC)
        {
            DeleteDC(s_backBufferDC);
            s_backBufferDC = nullptr;
        }

        if (s_hdc)
        {
            ReleaseDC(s_hwnd, s_hdc);
            s_hdc = nullptr;
        }
    }
}