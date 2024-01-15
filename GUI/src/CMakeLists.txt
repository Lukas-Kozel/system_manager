cmake_minimum_required(VERSION 3.5)

project(gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

add_executable(gui main.cpp service.pb.cc service.grpc.pb.cc)

target_link_libraries(gui Qt5::Widgets gRPC::grpc++ gRPC::grpc++_reflection protobuf::libprotobuf)
