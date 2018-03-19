cmake_minimum_required(VERSION 3.8)
project(carsmashcpp)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "/usr/local/boost_1_66_0")


set(Box2D_INCLUDE_DIR /opt/Box2D/Box2D)
set(Box2D_LIBRARY_DIR /opt/Box2D/Box2D/Build/gmake/bin/Debug)

find_package(Boost 1.66.0)

include_directories(${Boost_INCLUDE_DIR} ${Box2D_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR} ${Box2D_LIBRARY_DIR})

set(SOURCE_FILES main.cpp networking/websocket_server_async.cpp networking/WebSocketServerAsync.cpp networking/WebSocketServerAsync.h networking/Session.cpp networking/Session.h networking/Listener.cpp networking/Listener.h)

add_executable (carsmashcpp
        ${BOOST_BEAST_INCLUDES}
        ${COMMON_INCLUDES}
        networking/websocket_server_async.cpp
        ${SOURCE_FILES}
        )

target_link_libraries( carsmashcpp ${Boost_LIBRARIES} -lBox2D -lpthread -lboost_system -lm)