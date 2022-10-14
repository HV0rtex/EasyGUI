#include "../buttons.hpp"

void backButton_action ()
{
    easyGUI::Application* app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        app->setActiveMenu(0);

        easyGUI::Converter::getTextbox(app->getActiveMenu()->getComponent(3))->clear();
        easyGUI::Converter::getTextbox(app->getActiveMenu()->getComponent(4))->clear();
    }
}