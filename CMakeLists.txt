cmake_minimum_required(VERSION 3.17)
project(Practica0LeoAlvarado)

set(CMAKE_CXX_STANDARD 14)
find_package(ImageMagick REQUIRED COMPONENTS Magick++ )

add_executable(Practica0LeoAlvarado main.cpp Imagen.cpp Imagen.h PDF.cpp PDF.h)

add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
find_package(ImageMagick COMPONENTS Magick++)

INCLUDE_DIRECTORIES(
        "${ImageMagick_INCLUDE_DIRS}"
)

TARGET_LINK_LIBRARIES(Practica0LeoAlvarado
        "${ImageMagick_LIBRARIES}"
        )