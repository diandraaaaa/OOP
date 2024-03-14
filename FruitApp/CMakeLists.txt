cmake_minimum_required(VERSION 3.24)
project(L4_Stoica_Diandra)

set(CMAKE_CXX_STANDARD 17)

add_executable(L4_Stoica_Diandra Shop.cpp FruitUi.h FruitUi.cpp Fruit.h Fruit.cpp FruitRepo.cpp FruitRepo.h FruitController.h FruitController.cpp tests.cpp tests.h)
