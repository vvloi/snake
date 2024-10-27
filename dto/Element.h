
#ifndef ELEMENT_H
#define ELEMENT_H

#include "Item.h"
class Element : public Item {
private:
    Element* next = nullptr;
    Point* captured = nullptr;
    bool isTail = false;

public:
    Element(Point* point) : Item(point) {};

    Element(Point* point, bool isTail) : Item(point), isTail(isTail) {};

    Element(Point* point, char chrt) : Item(point, chrt) {};
    ~Element() {
        delete captured;
    };

    void moveToNextPosition() {
        if (next == nullptr) return;

        // no need capture point for tail
        if (!isTail) {
            // capture current point
            captured = new Point(point);
        }


        if (next->captured == nullptr) return;
        // move to the old position of the next cursor
        point = next->captured;
    }

    Element* GetNext() const {
        return next;
    }

    void SetNext(Element* next) {
        this->next = next;
    }

    Point* GetCaptured() const {
        return captured;
    }

    void SetCaptured(Point* captured) {
        this->captured = captured;
    }

};

#endif