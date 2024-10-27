#ifndef SNAKE_SERVICE_H
#define SNAKE_SERVICE_H
#include "Snake.h"
#include "SnakeRepository.h"

class SnakeHeadService {
private:
    SnakeRepository* snakeRepository;

    static void processSnakePoint(Snake* snake) {
        Element* head = snake->GetHead();
        setCapturePoint(head);
        updateNewPoint(head, snake->GetState());
    }

    static void setCapturePoint(Element* head) {
        Point* p = head->GetPoint();
        head->SetCaptured(p);
    }

    static void updateNewPoint(Element* head, int state) {
        Point* newP = new Point(head->GetPoint());

        switch (state) {
            case MOVING_UP:
                newP->increaseY(-1);
                break;
            case MOVING_DOWN:
                newP->increaseY(1);
                break;
            case MOVING_LEFT:
                newP->increaseX(-1);
                break;
            case MOVING_RIGHT:
                newP->increaseY(1);
                break;
            default:
                break;
        }
        head->SetPoint(newP);
    }
public:
    explicit SnakeHeadService(SnakeRepository* rep): snakeRepository(rep) {}

    void moveUp() {
        Snake* snake = snakeRepository->GetSnake();
        if (snake->GetState() == MOVING_DOWN) return;

        snake->SetState(MOVING_UP);
        processSnakePoint(snake);
    }

    void moveDown() {
        Snake* snake = snakeRepository->GetSnake();
        if (snake->GetState() == MOVING_UP) return;

        snake->SetState(MOVING_DOWN);
        processSnakePoint(snake);
    }

    void turnRight() {
        Snake* snake = snakeRepository->GetSnake();
        if (snake->GetState() == MOVING_LEFT) return;

        snake->SetState(MOVING_RIGHT);
        processSnakePoint(snake);
    }

    void turnLeft() {
        Snake* snake = snakeRepository->GetSnake();
        if (snake->GetState() == MOVING_RIGHT) return;

        snake->SetState(MOVING_LEFT);
        processSnakePoint(snake);
    }

    void goAhead() {
        Snake* snake = snakeRepository->GetSnake();
        switch (snake->GetState()) {
            case MOVING_UP:
                moveUp();
                break;
            case MOVING_DOWN:
                moveDown();
                break;
            case MOVING_LEFT:
                turnLeft();
                break;
            case MOVING_RIGHT:
                turnRight();
                break;
            default:
                break;
        }
    }

    void notify() {
        Snake* snake = snakeRepository->GetSnake();
        snake->notify();
    }

    void render() {
        Snake* snake = snakeRepository->GetSnake();
        snake->render();
    }
};
#endif