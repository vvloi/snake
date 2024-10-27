#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(Point *point)
    {
        this->x = point->x;
        this->y = point->y;
    }

    int GetX() const
    {
        return x;
    }

    void SetX(int x)
    {
        this->x = x;
    }

    int GetY() const
    {
        return y;
    }

    void SetY(int y)
    {
        this->y = y;
    }

    void increaseX(int increaseValue) {
        this->x += increaseValue;
    }

    void increaseY(int increaseValue) {
        this->y += increaseValue;
    }
};
#endif