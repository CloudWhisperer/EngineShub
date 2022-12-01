cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  include_directories(
    contrib/emcc-emscripten-wasm/include
  )

  link_directories(
    contrib/emcc-emscripten-wasm/lib
  )

  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ${CMAKE_SOURCE_DIR}/resources@resources")
  set(LIBOPENAL openal)
endif()


include_directories(
    src
    contrib/include
    contrib/cl-windows-amd64/include
)

link_directories(
 ${PROJECT_SOURCE_DIR}/contrib/lib
 contrib/cl-windows-amd64/lib
)

add_library(myengine
    src/myengine/Core.cpp
    src/myengine/Core.h

    src/myengine/Entity.cpp
    src/myengine/Entity.h

    src/myengine/myengine.h

    src/myengine/Transform.h
    src/myengine/Transform.cpp

    src/myengine/Component.h
    src/myengine/Component.cpp

    src/myengine/TriangleRenderer.h
    src/myengine/TriangleRenderer.cpp

    src/myengine/SoundSource.cpp
    src/myengine/SoundSource.h

    #src/myengine/stb_vorbis.c
)
target_link_libraries(myengine SDL2 SDL2main rend)

add_executable(game
    src/game/main.cpp
    src/game/TestScene.cpp

    src/game/TestScene.h
)

target_link_libraries(game myengine)
target_link_libraries(myengine openal32)


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
target_link_libraries(rend GLEW32 OpenGL32)