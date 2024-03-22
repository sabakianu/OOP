#pragma once
class Canvas
{
private:
    char** x;
    int a, b;// add private data members
public:
    Canvas(int width, int height)
    {
        a = width;
        b = height;

        x = new char* [b];
        for (int i = 0; i < a; ++i) {
            x[i] = new char[a];
        }
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                x[i][j] = ' ';
    };

    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void SetPixel(int x, int y, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};
