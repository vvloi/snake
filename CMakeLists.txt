cmake_minimum_required(VERSION 3.29)
project(snake)

set(CMAKE_CXX_STANDARD 14)

include_directories(dto)
include_directories(handler)
include_directories(repository)
include_directories(service)

add_executable(snake
    app/SnakeApplication.cpp
    dto/Element.h
    dto/Item.h
    dto/Point.h
    dto/Snake.h
    handler/SnakeHandler.h
    repository/SnakeRepository.h
    service/SnakeHeadService.h)
