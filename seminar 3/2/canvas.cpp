#include "canvas.h"
#include <iostream>
#include <cmath>
using namespace std;
void Canvas::SetPixel(int x, int y, char ch)
{
    if (x >= 0 && x < this->a && y >= 0 && y < this->b)
        this->x[y][x] = ch;
}
void Canvas::DrawCircle(int xc, int yc, int radius, char ch)
{
    int r = radius;
    int t = 0;
    int err = 0;

    while (r >= t)
    {
        SetPixel(xc + r, yc + t, ch);
        SetPixel(xc - r, yc + t, ch);
        SetPixel(xc + r, yc - t, ch);
        SetPixel(xc - r, yc - t, ch);
        SetPixel(xc + t, yc + r, ch);
        SetPixel(xc - t, yc + r, ch);
        SetPixel(xc + t, yc - r, ch);
        SetPixel(xc - t, yc - r, ch);

        if (err <= 0)
        {
            t += 1;
            err += 2 * t + 1;
        }
        if (err > 0)
        {
            r -= 1;
            err -= 2 * r + 1;
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int dy = -ray; dy <= ray; dy++) {
        int width = sqrt(ray * ray - dy * dy)-0.5;
        for (int dx = -width+1; dx < width; dx++) {
            SetPixel(x + dx, y + dy, ch);
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		this->x[top][i] = ch;
		this->x[bottom][i] = ch;
	}
	for (int i = top; i <= bottom; i++)
	{
		this->x[i][left] = ch;
		this->x[i][right] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left+1; i < right; i++)
		for (int j = top+1; j < bottom; j++)
			this->x[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->x[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        this->x[y1][x1] = ch;
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
void Canvas::Print()
{
	for (int i = 0; i < this->b; i++)
	{
		for (int j = 0; j < this->a; j++)
			cout << this->x[i][j] << ' ';
		cout << endl;
	}
}// shows what was printed
void Canvas::Clear()
{
	for (int i = 0; i < this->b; i++)
		for (int j = 0; j < this->a; j++)
			this->x[i][j] = ' ';
}
// clears the canvas