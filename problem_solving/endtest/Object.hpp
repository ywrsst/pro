#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

class Object {
public:
    int X;  // x좌표
    int Y;  // y좌표

    int StartX; // 가로
    int StartY; // 세로

    bool Drawing;  // 오브젝트를 그렸는가

    std::vector<std::vector<std::string>> image;

    Object(int startX, int startY) // X = 가로 Y = 세로
    {
        X = 0;
        Y = 0;
        Drawing = true;
        StartX = startX;
        StartY = startY;
        image.resize(StartY, std::vector<std::string>(StartX));
    }

    virtual void Render(std::string screenBuffer[29][50])
    {
        // 기본적으로 아무 작업도 수행하지 않음
    }
    virtual void ReStart() {}

    virtual void ImageSet() {}
};

#endif  // OBJECT_H
