
add_executable(EasyGUI-CLI
    src/main.cpp
    src/parser.cpp
    src/generators.cpp
    src/fileGenerators.cpp
)

target_include_directories(EasyGUI-CLI
    PUBLIC inc
)

install(TARGETS EasyGUI-CLI DESTINATION ${PROJECT_RUNTIME_DIR})