#include "Snake.h"
#include "SnakeRepository.h"
#include "SnakeHeadService.h"
#include "SnakeHandler.h"

int main() {
    Snake* snake = new Snake();
    SnakeRepository* snakeRepository = new SnakeRepository(snake);
    SnakeHeadService* snakeHeadService = new SnakeHeadService(snakeRepository);
    SnakeHandler* snakeHandler = new SnakeHandler(snakeHeadService);

    snakeHandler->listenKeyboardEvent();
    return 0;
}