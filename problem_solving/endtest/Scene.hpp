#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Object.hpp"
#include "colors.hpp"

using namespace std;

class Scene
{
public:
    string printout;
    Cursor c;
    vector<Object*> objects;
    string screenBuffer[29][50];

    Scene()
    {
        printout = "";
        ClearScreenBuf();  // ClearScreenBuf 함수로 ScreenBuffer 초기화
    }

    void AddObject(Object* object)
    {
        objects.push_back(object);
    }

    void DeleteObject()
    {
        objects.pop_back();
    }

    void Draw()
    {
        for (Object* object : objects)
        {
            if (object->Drawing == true)
            {
                object->Render(this->screenBuffer);
            }
        }

        // Render the screen buffer
        printout = "";

        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                printout += screenBuffer[i][j];
            }
            printout += Reset"\n";
        }

        cout << printout;
    }

    void ClearScreenBuf()  // system(cls) 대신 오브젝트를 지움
    {
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                screenBuffer[i][j] = "  ";
            }
        }
    }

    void GameStartObject() {
        for (Object* object : objects)
        {
            if (object->Drawing == true)
            {
                object->ReStart();
            }
        }
    }

};
