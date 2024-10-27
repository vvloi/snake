#ifndef SNAKE_REPOSITORY_H
#define SNAKE_REPOSITORY_H
#include "Snake.h"

class SnakeRepository {
private:
    Snake* snake;

public:
    explicit SnakeRepository(Snake *snake)
        : snake(snake) {
    }


    Snake* GetSnake() const {
        return snake;
    }

    void SetSnake(Snake* snake) {
        snake = snake;
    }
};
#endif