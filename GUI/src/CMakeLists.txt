cmake_minimum_required(VERSION 3.5)

project(gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(RPC_DIR "../../RPC")

find_package(Qt5 COMPONENTS Widgets Core Gui Charts REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

include_directories(${RPC_DIR})

add_executable(gui 
    main.cpp 
    ${RPC_DIR}/service.pb.cc 
    ${RPC_DIR}/service.grpc.pb.cc 
    Client_bridge.cpp 
    MainWindow.cpp 
    RPC_client.cpp
)

target_link_libraries(gui
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Gui
  Qt${QT_VERSION_MAJOR}::Charts
  Qt${QT_VERSION_MAJOR}::Widgets
  gRPC::grpc++
  gRPC::grpc++_reflection
  protobuf::libprotobuf
)
