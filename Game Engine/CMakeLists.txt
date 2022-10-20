cmake_minimum_required(VERSION 3.0)
project(MYENGINE)


include_directories(
    src
    src/contrib/includestuff/SDL2
    src/contrib/includestuff/GL
)

link_directories(
 ${PROJECT_SOURCE_DIR}/src/contrib/includestuff/SDL2/lib
 ${PROJECT_SOURCE_DIR}/src/contrib/includestuff/glew/lib
)

add_library(myengine
    src/myengine/Core.cpp
    src/myengine/Entity.cpp

    src/myengine/myengine.h
    src/myengine/Core.h
    src/myengine/Entity.h

    src/myengine/Component.h
    src/myengine/Component.cpp
)
target_link_libraries(myengine SDL2 SDL2main)

add_executable(game
    src/game/main.cpp
    src/game/TestScene.cpp

    src/game/TestScene.h
)

target_link_libraries(game myengine)