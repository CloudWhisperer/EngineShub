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
    src/myengine/Core.h

    src/myengine/Entity.cpp
    src/myengine/Entity.h

    src/myengine/myengine.h

    src/myengine/Component.h
    src/myengine/Component.cpp

    src/myengine/TriangleRenderer.h
    #src/myengine/TriangleRenderer.cpp
)
target_link_libraries(myengine SDL2 SDL2main)

add_executable(game
    src/game/main.cpp
    src/game/TestScene.cpp

    src/game/TestScene.h
)

target_link_libraries(game myengine)


add_library(rend
 src/rend/Animation.cpp
 src/rend/Buffer.cpp
 src/rend/Mesh.cpp
 src/rend/Model.cpp
 src/rend/ModelRenderer.cpp
 src/rend/RenderTexture.cpp
 src/rend/Renderer.cpp
 src/rend/Shader.cpp
 src/rend/Texture.cpp
 src/rend/rendmath.cpp
)
target_link_libraries(rend GLEW GL)

add_library(myengine
 src/myengine/Core.cpp
 src/myengine/Entity.cpp
 src/myengine/Component.cpp
 src/myengine/TriangleRenderer.cpp
)
target_link_libraries(myengine rend SDL2)