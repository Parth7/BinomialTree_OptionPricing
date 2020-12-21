cmake_minimum_required(VERSION 3.17)
project(BinaryTree_Options)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinaryTree_Options main.cpp TreeAmerican.h TreeProduct.h TreeProduct.cpp PayOffBridge.h
        PayOff.h PayOff.cpp PayOffBridge.cpp TreeAmerican.cpp TreeEuropean.h TreeEuropean.cpp BinomialTree.cpp BinomialTree.h parameters.cpp parameters.h arrays.h arrays.cpp PayoffForward.cpp PayoffForward.h)