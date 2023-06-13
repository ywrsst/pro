#ifndef CURSOR_H
#define CURSOR_H

#include <windows.h>

class Cursor {
public:
    Cursor() {}

    void gotoxy(int x, int y) {  //gotoxy이용해서 좌표 이동
        COORD Pos = { x,y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
        //SetConsoleCursorPosition 함수를 사용하여 커서의 위치를 변경
        CONSOLE_CURSOR_INFO ConsoleCursor; //SetConsoleCursorInfo 함수를 사용하여 커서의 가시성과 크기를 조정
        ConsoleCursor.bVisible = false; //ConsoleCursor.bVisible을 false로 설정하여 커서를 보이지 않도록
        ConsoleCursor.dwSize = 1; //, ConsoleCursor.dwSize를 1로 설정하여 커서 크기를 1로 지정
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
    }
};

#endif  // CURSOR_H
