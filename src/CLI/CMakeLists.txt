
add_executable(easyGUI-CLI
    src/main.cpp
    src/parser.cpp
    src/generators.cpp
    src/fileGenerators.cpp
)

target_include_directories(easyGUI-CLI
    PUBLIC inc
)

install(TARGETS easyGUI-CLI DESTINATION ${PROJECT_RUNTIME_DIR})