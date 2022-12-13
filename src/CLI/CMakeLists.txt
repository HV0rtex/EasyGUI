
add_executable(EasyGUI-CLI
    src/main.cpp
    src/parser.cpp
)

target_include_directories(EasyGUI-CLI
    PUBLIC inc
)

install(target EasyGUI-CLI DESTINATION ${PROJECT_BINARY_DIR})