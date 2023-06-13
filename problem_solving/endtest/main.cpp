#include <iostream>
#include <vector>
#include <string>
#include "Objects.hpp"
#include "colors.hpp"
#include <windows.h> //gotoxy 사용을 위해 추가 
#include <conio.h> // _kbhit, _getch 함수를 사용하기 위해 추가
#include "Object.hpp"
#include "Cursor.hpp"
#include "Scene.hpp"



using namespace std;

int main()
{
    system("mode con cols=140 lines=30");
    Scene scene;
    Cursor c;

    Player player(0, 21, 8, 6);
    Cloud cloud(40, 2, 7, 3, 3);
    Ground ground(50, 2);
    Mountain mountain(19, 14, 20, 12);
    Obstacle ob(40, 24, 2, 3);
    TitlePage title(10, 5, 30, 20);
    bool playerCollided = false;
    bool GameStart = false;
    bool IsStart = false;
    int score = 0;

    while (true)
    {
        while (!IsStart)
        {
            scene.AddObject(&title);
            scene.Draw();
            char userInput;
            cin >> userInput;
            if (userInput == 'Y' || userInput == 'y')
            {
                scene.DeleteObject();
                scene.AddObject(&cloud);
                scene.AddObject(&ob);
                scene.AddObject(&mountain);
                scene.AddObject(&player);
                scene.AddObject(&ground);
                IsStart = true;
                scene.ClearScreenBuf();
                score = 0; // 점수를 0으로 초기화
            }
        }

        bool isGameRePlay = true;
        while (isGameRePlay)
        {
            bool isGamePlay = true;
            while (isGamePlay)
            {
                c.gotoxy(0, 0);
                player.JumpPlayer();
                cloud.MoveCloud();
                mountain.MoveMountain();
                ob.MoveObstacle();
                isGamePlay = !player.Crash(ob);
                scene.Draw();
                scene.GameStartObject();
                cout << "Score : " << score;
                score++;
                scene.ClearScreenBuf();

                if (_kbhit())
                {
                    char key = _getch();
                    if (key == ' ')
                    {
                        player.StartJump();
                    }
                }

                Sleep(100);
            }

            cout << "  ""Game Over ! 다시 플레이 하고 싶으면 R을 입력해주세요";
            char userInput;
            cin >> userInput;

            if (userInput == 'R' || userInput == 'r')
            {
                scene.DeleteObject();
                scene.DeleteObject();
                scene.DeleteObject();
                scene.DeleteObject();
                scene.DeleteObject();
                ob.resetPosition(40, 24, 2, 3);

                scene.AddObject(&cloud);
                scene.AddObject(&ob);
                scene.AddObject(&mountain);
                scene.AddObject(&player);
                scene.AddObject(&ground);
                IsStart = true;
                scene.ClearScreenBuf();

                score = 0; // 점수를 0으로 초기화
            }
            else
            {
                isGameRePlay = false;
            }
        }
    }

    return 0;
}
