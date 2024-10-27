#ifndef ITEM_H
#define ITEM_H
#include "Point.h"

class Item {
protected:
    Point* point;
    char character;

public:
    Item() : point(new Point(0, 0)), character('*') {};

    Item(Point* point) : point(point), character('*') {};

    Item(Point* point, char chrt) : point(point), character(chrt) {};
    ~Item();

    Point* GetPoint() const {
        return point;
    }

    void SetPoint(Point* point) {
        point = point;
    }

    char GetCharacter() const {
        return character;
    }

    void SetCharacter(char character) {
        character = character;
    }
};
#endif