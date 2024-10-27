#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
const int MOVING_UP = 1;
const int MOVING_DOWN = 2;
const int MOVING_LEFT = 3;
const int MOVING_RIGHT = 4;

#include "Element.h"
#include <random>
#include <windows.h>
using namespace std;

class Snake
{
private:
    Element *head;
    Element *tail;
    int state;

    int random()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(10, 20);
        return distr(gen);
    }

public:
    Snake()
    {
        state = MOVING_RIGHT;
        Point *tPoint = new Point(random(), random());
        tail = new Element(tPoint, true);

        Point *hPoint = new Point(tPoint);

        hPoint->increaseX(1);

        head = new Element(hPoint);

        tail->SetNext(head);
        head->SetNext(nullptr);
        render();
    };

    void notify()
    {
        Element *curr = tail;
        while (curr != head)
        {
            curr->moveToNextPosition();
            curr = curr->GetNext();
        }
    }

    Element *GetHead() const
    {
        return head;
    }

    void SetHead(Element *head)
    {
        head = head;
    }

    int GetState() const
    {
        return state;
    }

    void SetState(int state)
    {
        state = state;
    }

    void render() {
        COORD coord;
        Element* curr = tail;
        while (true) {
            Point* p = curr->GetPoint();
            coord.X = p->GetX();
            coord.Y = p->GetY();
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout << curr->GetCharacter();
            curr = curr->GetNext();
            if (curr == nullptr) return;
        }
    }
};
#endif