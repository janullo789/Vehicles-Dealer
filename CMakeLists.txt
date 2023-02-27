cmake_minimum_required(VERSION 3.21)
project(Car_Dealer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Car_Dealer main.cpp Vehicle.cpp MotorVehicle.cpp Motorcycle.cpp Bicycle.cpp Car.cpp Factory.cpp)
