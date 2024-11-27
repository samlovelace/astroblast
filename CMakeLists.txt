cmake_minimum_required(VERSION 3.8)
project(astroblast)

find_package(SFML REQUIRED COMPONENTS system window graphics)

set(SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/src/Asteroid.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/AsteroidHandler.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Explosion.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Spaceship.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Star.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/TravelingBackground.cpp    
)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${PROJECT_NAME} 
    ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)