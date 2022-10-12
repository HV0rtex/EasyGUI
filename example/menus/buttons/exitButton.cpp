#include "../buttons.hpp"

void exitButton_action ()
{
    easyGUI::Application* app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        app->stop();
    }
}