cmake_minimum_required(VERSION 3.29)
project(snake)

set(CMAKE_CXX_STANDARD 14)

include_directories(archived/dto)
include_directories(archived/handler)
include_directories(archived/repository)
include_directories(archived/service)

add_executable(snake
        archived/app/SnakeApplication.cpp
        archived/dto/Element.h
        archived/dto/Item.h
        archived/dto/Point.h
        archived/dto/Snake.h
        archived/handler/SnakeHandler.h
        archived/repository/SnakeRepository.h
        archived/service/SnakeHeadService.h)
