#pragma once
#include <vector>
#include <string>
#include "Object.hpp"
#include "colors.hpp"
#include "Cursor.hpp"
#include "Scene.hpp"

std::vector<std::vector<std::string>> image;

class Cloud : public Object
{
public:
    int CloudmoveCount;
    int CloudmoveSpeed;

    Cloud(int x, int y, int startX, int startY, int speed) : Object(startX, startY)
    {
        X = x;
        Y = y;
        Drawing = true;
        StartX = startX;
        StartY = startY;
        CloudmoveCount = 0;
        CloudmoveSpeed = speed;
        ImageSet();
        image.resize(3, vector<string>(7));
    }
    string cloudshape[3][7] = {
         {"  ", White" ■",Blue" ■",White" ■",Blue"■" Reset,"  ","  "},
         {White" ■",Blue" ■",White" ■",Blue" ■",White" ■",Blue"■" Reset,"  "},
         {"  ",White" ■",Blue" ■",White" ■",Blue"■" Reset,"  ","  "}
    };
    void SetDrawing(bool t) {
        Drawing = t;
    }
    void Render(string screenBuffer[29][50])
    {
        for (int i = 0; i < StartY; i++)
        {
            int currentY = Y + i;  // 실제 Y 좌표 계산
            if (currentY < 29)
            {
                for (int j = 0; j < StartX; j++)
                {
                    int currentX = X + j;  // 실제 X 좌표 계산
                    if (currentX >= 0 && currentX < 50)
                    {
                        if (cloudshape[i][j] != "  ")
                        {
                            screenBuffer[currentY][currentX] = cloudshape[i][j];
                        }
                    }
                }
            }
        }
    }
    void ImageSet() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 7; j++) {
                image[i][j] = cloudshape[i][j];
            }
        }
    }
    void MoveCloud() {
        if (CloudmoveCount == CloudmoveSpeed) {
            X--;
            if (X + StartX < 0) {
                X = 50;
            }
            CloudmoveCount = 0;
        }
        else {
            CloudmoveCount++;
        }
    }
};



class Mountain : public Object
{
public:
    int MountainCount;
    int MountainSpeed;

    Mountain(int x, int y, int startX, int startY) : Object(startX, startY)
    {
        X = x;
        Y = y;
        Drawing = true;
        StartX = startX;
        StartY = startY;
        MountainCount = 0;
        MountainSpeed = 120; // 점수 120씩  이동
        ImageSet();


    }

    string Mountainshape[12][20] = {
        {"  ","  ","  ","  ","  ",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset,"  ","  " ,"  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset,"  ","  " ,"  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  " Reset,"  ","  ","  " ,"  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  " Reset,"  ","  ","  " ,"  ","  ","  ","  ","  "},
        {"  ","  ",BgLyellow" ■",BgLyellow" ■",BgLyellow" ■",BgLyellow" ■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset,"  ","  ","  " ,"  ","  ","  ","  "},
       {"  ","  ",BgLyellow" ■",BgLyellow" ■",BgLyellow" ■",BgLyellow" ■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset,"  ","  ","  " ,"  ","  ","  ","  "},
        {"  ","  ","  ","  ",BgLyellow" ■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow" ■" Reset,"  ","  ","  "},
        {"  ","  ","  ","  ",BgLyellow" ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  " Reset,"  ","  "},
        {"  ","  ","  ","  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"   ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  ",BgLyellow"  " Reset,"  ","  "},
        {"  ","  ","  ",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset,"  "},
        {"  ","  ","  ",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset,"  "},
        {"  ",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■",BgLyellow"■" Reset},

    };
    void setDrawing(bool t) {
        Drawing = t;
    }
    void Render(string screenBuffer[29][50])
    {
        for (int i = 0; i < StartY; i++)
        {
            int currentY = Y + i;  // 실제 Y 좌표 계산
            if (currentY < 29)
            {
                for (int j = 0; j < StartX; j++)
                {
                    int currentX = X + j;  // 실제 X 좌표 계산
                    if (currentX >= 0 && currentX < 50)
                    {
                        if (Mountainshape[i][j] != "  ")
                        {
                            screenBuffer[currentY][currentX] = Mountainshape[i][j];
                        }
                    }
                }

            }
        }
    }
    void ImageSet() {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 20; j++) {
                image[i][j] = Mountainshape[i][j];
            }
        }
    }

    void MoveMountain() {
        if (MountainCount == MountainSpeed) {
            X--;
            if (X + StartX < 0) {
                X = 50;
            }
            MountainCount = 0;
        }
        else {
            MountainCount++;
        }
    }
};
class Obstacle : public Object {
public:
    int MoveCount;
    int MoveSpeed;
    bool Falling;
    string obstacleImage[3][2] = {
        {Pink"■",Pink"■" Reset},
        {White"  " Reset},
        {White"  " Reset}

    };
    Obstacle(int x, int y, int startX, int startY) : Object(startX, startY) {
        X = x;
        Y = y;
        Drawing = true;
        StartX = startX;
        StartY = startY;
        ImageSet();

        // image 초기화
        image.resize(StartY);
        for (int i = 0; i < StartY; i++)
        {
            image[i].resize(StartX);
            for (int j = 0; j < StartX; j++)
            {
                image[i][j] = obstacleImage[i][j];
            }
        }

    }

    void Render(string screenBuffer[29][50]) {

        for (int i = 0; i < StartY; i++)
        {
            int currentY = Y + i;  // 실제 Y 좌표 계산
            if (currentY < 29)
            {
                for (int j = 0; j < StartX; j++)
                {
                    int currentX = X + j;  // 실제 X 좌표 계산
                    if (currentX >= 0 && currentX < 50)
                    {
                        if (obstacleImage[i][j] != "  ")
                        {
                            screenBuffer[currentY][currentX] = obstacleImage[i][j];
                        }
                    }
                }

            }
        }
    }
    void ImageSet() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                image[i][j] = obstacleImage[i][j];
            }
        }
    }


    void MoveObstacle() {
        if (Falling == false) {
            X--;
            if (X + StartX < 0) {
                X = 50;
            }
        }
    }

    void resetPosition(int x, int y, int startX, int startY) {
        X = x;
        Y = y;
        StartX = startX;
        StartY = startY;

    }
};

class Ground : public Object
{
    vector<vector<string>> image;
public:
    Cursor c;
    int ColorCount;


    Ground(int startX, int startY) : Object(startX, startY) {
        X = 0;
        Y = 27;
        Drawing = true;
        ColorCount = 0;
        StartX = startX;
        StartY = startY;

        Setting();

        image.resize(startY);
        for (int i = 0; i < startY; i++) {
            image[i].resize(startX);
            for (int j = 0; j < startX; j++) {
                image[i][j] = groundImage[i][j];
            }
        }

    }

    string groundImage[2][50];

    void Setting()
    {
        int ColorCount = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 49; j++)
            {

                if (ColorCount == 5) {
                    groundImage[i][j] = Yellow"■";
                    ColorCount = 0;
                }
                else {
                    groundImage[i][j] = Green" ■";
                    ColorCount++;

                }

            }
        }
    }
    void Render(string screenBuffer[29][50])
    {
        for (int i = 0; i < 50; i++) {
            screenBuffer[27][i] = groundImage[0][i];
            screenBuffer[28][i] = groundImage[1][i];
        }
    }
    void MoveGround() {
        for (int i = 0; i < StartY; i++)
        {
            for (int j = 0; j < StartX; j++)
            {
                groundImage[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < StartY; i++)
        {
            for (int j = 0; j < (StartX - 1); j++)
            {
                image[i][j] = groundImage[i][j + 1];
            }

            image[i][50] = groundImage[i][0];
        }
    }
};

class Player : public Object
{
public:
    Cursor c;
    int MCount;
    bool Isjump;
    bool Isfall;
    int JCount;
    int groundY;

    const int KeyJump = 32; // 스페이스바의 키 코드


    Player(int x, int y, int startX, int startY) : Object(startX, startY)
    {
        /*PixImage();*/
        X = x;
        Y = y;
        StartX = startX;
        StartY = startY;
        groundY = y;
        Drawing = true;
        MCount = 0;
        JCount = 0;
        Isjump = false;
        Isfall = false;
        ImageSet();


        // image 초기화
        image.resize(StartY);
        for (int i = 0; i < StartY; i++)
        {
            image[i].resize(StartX);
            for (int j = 0; j < StartX; j++)
            {
                image[i][j] = playershape[i][j];
            }
        }
    }

    string playershape[6][8] = {
        {Red"■",Red"■",Red"■",Red"■",Red"■" Reset, "  ", "  ", "  "},
        {Red"■",Red"■",Red"■",Red"■",Red"■",Red"■" Reset, "  ", "  "},
        {White"■",Yellow"■",Yellow"■",White"□",White"□",White"□",Yellow"■" Reset, "  "},
        {Red"■",Red"■",Red"■",Red"■",Red"■" Reset, "  ", "  ", "  "},
        {Red"■",Red"■",Red"■",Red"■",Red"■" Reset, "  ", "  ", "  "},
        {Blue"■",Blue"■" Reset, "  ", "  ",Blue"■",Blue"■" Reset,"  ", "  "}
    };

    void Render(string screenBuffer[29][50])
    {
        for (int i = 0; i < StartY; i++)
        {
            for (int j = 0; j < StartX; j++)
            {
                if (image[i][j] != "  ")
                {
                    screenBuffer[Y + i][X + j] = image[i][j];
                }
            }
        }
    }
    void ImagePaste() {
        for (int i = 0; i < StartY; i++) {
            for (int j = 0; j < StartX; j++) {
                image[i][j] = playershape[i][j];
            }
        }
    }


    void JumpPlayer()
    {
        if (Isjump && !Isfall) {
            Y--;
            JCount++; // 점프 동작

            if (JCount >= 8) // 최대 점프 높이 도달
            {
                Isfall = true;
                Isjump = false;
            }
        }
        else if (Isfall) {
            Y++;
            JCount--; // 낙하 동작

            if (JCount == 1) // 최소 낙하 높이 도달(땅)
            {
                Isfall = false;
                Y = groundY; // 초기 Y값으로 되돌리기
                Isjump = false; // 다시 점프를 시작할 수 있도록 Isjump를 false로 설정
            }
        }
        else if (!Isjump && !Isfall && KeyPressed(KeyJump)) {
            Isjump = true;
            JCount = 0;
        }
    }
    bool KeyPressed(int key)
    {
        if (key == KeyJump) {

            if (GetAsyncKeyState(0x20) & 0x8000)
            {
                return true;
            }
        }
        return false;
    }

    void StartJump()
    {
        if (!Isjump && !Isfall) { // Isjump가 false이고 Isfall이 false일 때에만 점프를 시작
            Isjump = true;
            JCount = 0;
        }
    }

    bool Crash(Obstacle& ob) {   // 충돌 처리
        if (ob.X >= X && ob.X <= X + 6)
        {
            if ((Y + 4) >= 23) {
                return true;
            }
        }



        return false;
    }

};


class TitlePage : public Object
{
public:
    string Titleshape[20][30] = {

        {"  ",White"■",Gray"■",White"■",Gray"■",White"■",Gray"■",White"■",Gray"■" Reset,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ",White"■" Reset,"  ","  ","  ",White"■" Reset,"  ","  ","  ",White"■" Reset,"  "," ",White"■" Reset,"  ",White"■" Reset,"  ","  ","  ",White"■" Reset,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ",White"■" Reset,"  ","  ",White"■" Reset,"  " ,"  ","  ","  ",White"■" Reset,"  "," ",White"■" Reset,"  ",White"■",White"■" Reset,"  ","  "," ",White"■" Reset,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ",White"■",White"■",White"■" Reset,"  ","  ","  ","  ","   ",White"■" Reset,"  "," ",White"■" Reset,"  ",White"■" Reset,"  ",White"■" Reset,"   ",White"■" Reset,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ",White"■" Reset,"  ","  ",White"■" Reset,"  " ,"  ","  ","  ",White"■" Reset,"  "," ",White"■" Reset,"  ",White"■" Reset,"  ","  ",White"■" Reset,White"■" Reset,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ",White"■" Reset,"  ","  ","  ",White"■" Reset,"  ","  ","  ","  ",White"■" Reset,"  ","  ",White"■" Reset,"  ","  ","  ",White"■" Reset,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  " ,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  " ,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  " ,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  " ,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  " ,"  ","  ","  ","  ","  ","Y","혹","은","y","를","  ","입","력","하","면","  ","게","임","시","작","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  " ,"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "}

    };
    TitlePage(int x, int y, int startX, int startY) : Object(startX, startY) {
        X = x;
        Y = y;
        Drawing = true;
        StartX = startX;
        StartY = startY;
    }
    void Render(string screenBuffer[29][50])
    {

        for (int i = 0; i < StartY; i++)
        {
            int currentY = Y + i;  // 실제 Y 좌표 계산
            if (currentY < 29)
            {
                for (int j = 0; j < StartX; j++)
                {
                    int currentX = X + j;  // 실제 X 좌표 계산
                    if (currentX >= 0 && currentX < 50)
                    {
                        if (Titleshape[i][j] != "  ")
                        {
                            screenBuffer[currentY][currentX] = Titleshape[i][j];
                        }
                    }
                }

            }

        }

    }
};


