cmake_minimum_required(VERSION 3.12)

project(bunnies VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/exampleNames.txt ${CMAKE_CURRENT_SOURCE_DIR}/exampleNames.txt 
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(include)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/bunny.cpp
    src/field.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)