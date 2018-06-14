cmake_minimum_required(VERSION 3.8)
project(carsmashcpp)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "/usr/local/boost_1_66_0")


set(Box2D_INCLUDE_DIR /opt/Box2D/Box2D)
set(Box2D_LIBRARY_DIR /opt/Box2D/Box2D/Build/gmake/bin/Debug)
set(JSON_INCLUDE_DIR /opt/json/single_include)

find_package(Boost 1.66.0)

include_directories(${Boost_INCLUDE_DIR} ${Box2D_INCLUDE_DIR} ${JSON_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR} ${Box2D_LIBRARY_DIR})

set(SOURCE_FILES main.cpp networking/websocket_server_async.cpp networking/WebSocketServerAsync.cpp networking/WebSocketServerAsync.h networking/Session.cpp networking/Session.h networking/Listener.cpp networking/Listener.h game/Game.cpp game/Game.h game/player/PlayersManager.cpp game/player/PlayersManager.h game/player/Player.cpp game/player/Player.h networking/SessionI.cpp networking/SessionI.h networking/ListenerI.cpp networking/ListenerI.h networking/ListenerObserverI.cpp networking/ListenerObserverI.h utils/ThreadSafeQueue.h utils/ThreadSafeQueueI.h game/player/GameSession.cpp game/player/GameSession.h game/entities/EntityI.cpp game/entities/EntityI.h game/box2D/Box2dManager.cpp game/box2D/Box2dManager.h game/entities/car/CarFactory.cpp game/entities/car/CarFactory.h game/entities/car/Car.cpp game/entities/car/Car.h game/entities/car/CarPart.cpp game/entities/car/CarPart.h game/entities/car/CarModels.cpp game/entities/car/CarModels.h game/entities/car/CarPrototype.cpp game/entities/car/CarPrototype.h game/box2D/JointPrototype.cpp game/box2D/JointPrototype.h game/entities/car/CarPartPrototype.cpp game/entities/car/CarPartPrototype.h game/entities/car/CarBodyPrototype.cpp game/entities/car/CarBodyPrototype.h game/dataCollector/DataCollectableI.cpp game/dataCollector/DataCollectableI.h game/dataCollector/DataCollector.cpp game/dataCollector/DataCollector.h game/dataCollector/DataCollectableOnceI.cpp game/dataCollector/DataCollectableOnceI.h game/player/PlayerI.cpp game/player/PlayerI.h networking/MsgAcceptorI.cpp networking/MsgAcceptorI.h game/input/KeyboardManager.cpp game/input/KeyboardManager.h utils/Utilities.cpp utils/Utilities.h game/entities/car/CarEngine/CarEngine.cpp game/entities/car/CarEngine/CarEngine.h game/box2D/interactionManager/GameContactListener.cpp game/box2D/interactionManager/GameContactListener.h game/box2D/interactionManager/InteractiveEntityPartA.cpp game/box2D/interactionManager/InteractiveEntityPartA.h game/box2D/interactionManager/collideMasks.h)

add_executable(carsmashcpp
        ${BOOST_BEAST_INCLUDES}
        ${COMMON_INCLUDES}
        networking/websocket_server_async.cpp
        ${SOURCE_FILES}
        )

target_link_libraries(carsmashcpp ${Boost_LIBRARIES} -lBox2D -lpthread -lboost_system -lm)