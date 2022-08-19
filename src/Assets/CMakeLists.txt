
# ----- Defining library sets -----

add_library(
    assets STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Label.cpp
)

add_library(
    assets-shared SHARED

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Label.cpp
)

# ----- Defining includes -----

target_include_directories(
    assets PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_include_directories(
    assets-shared PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# ----- Linking dependencies -----

target_link_libraries(
    assets
    sfml-graphics
    sfml-window
    sfml-system
)

target_link_libraries(
    assets-shared
    sfml-graphics
    sfml-window
    sfml-system
)

# ----- Installing library -----

install( TARGETS assets DESTINATION ${PROJECT_LIBRARY_DIR} )
install( TARGETS assets-shared DESTINATION ${PROJECT_RUNTIME_DIR} )
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/inc/ DESTINATION ${PROJECT_INCLUDE_DIR} )