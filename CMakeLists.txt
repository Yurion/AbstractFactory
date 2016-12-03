cmake_minimum_required(VERSION 3.6)
project(AbstractFactory)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp enemy.h enemyHierarchyFactory.h enemyStandartFactory.h
        hierarchyGeneratorsSimple.h tuple_reverse.h)
add_executable(AbstractFactory ${SOURCE_FILES})
