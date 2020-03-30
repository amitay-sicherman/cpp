cmake_minimum_required(VERSION 3.14)
project(cpp_ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_ex1 main.cpp Matrix.cpp Matrix.h Activation.cpp Activation.h Dense.cpp Dense.h MlpNetwork.cpp MlpNetwork.h Digit.h)