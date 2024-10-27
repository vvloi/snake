#ifndef SNAKE_HANDLER_H
#define SNAKE_HANDLER_H
#include <windows.h>
#include "SnakeHeadService.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
class SnakeHandler
{
private:
    SnakeHeadService* snakeHeadService;
public:
    SnakeHandler(SnakeHeadService* snakeHeadService) : snakeHeadService(snakeHeadService) {}

    void listenKeyboardEvent() const {
        cout << "\nlistenKeyboardEvent" << endl;
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hInput, &mode);
        SetConsoleMode(hInput, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));

        INPUT_RECORD inputRecord;
        DWORD events;

        while (true)
        {
            ReadConsoleInput(hInput, &inputRecord, 1, &events);
            snakeHeadService->goAhead();

            if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown)
            {
                if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                    break;
                }

                switch (inputRecord.Event.KeyEvent.wVirtualKeyCode)
                {
                case VK_UP:
                    snakeHeadService->moveUp();
                    break;
                case VK_DOWN:
                    snakeHeadService->moveDown();
                    break;
                case VK_LEFT:
                    snakeHeadService->turnLeft();
                    break;
                case VK_RIGHT:
                    snakeHeadService->turnRight();
                    break;
                default:
                    snakeHeadService->goAhead();
                    break;
                }
            }
            snakeHeadService->notify();
            snakeHeadService->render();
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "end game" << endl;
    }
};
#endif