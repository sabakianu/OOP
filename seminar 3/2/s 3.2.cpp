#include <iostream>
#include "canvas.h"
int main()
{
    Canvas c = { 100,100 };

    c.DrawRect(10, 10, 40, 40, '*');
    c.FillRect(10, 10, 40, 40, '&');
    c.SetPoint(30, 30, 'x');
    c.DrawCircle(70, 70, 10, '6');
    c.FillCircle(70, 70, 10, '*');
    c.DrawLine(20, 90, 40, 80, 'g');
    c.Print();
    c.Clear();
}