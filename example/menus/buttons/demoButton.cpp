#include "../buttons.hpp"

void demoButton_action ()
{
    easyGUI::Application* app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        app->setActiveMenu(1);
    }
}