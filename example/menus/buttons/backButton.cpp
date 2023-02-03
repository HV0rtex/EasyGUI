#include "../buttons.hpp"

void backButton_action ()
{
    easyGUI::ApplicationPtr app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        app->setActiveMenu("mainMenu");

        easyGUI::Converter::getTextbox(app->getActiveMenu()->getComponent("uName"))->clear();
        easyGUI::Converter::getTextbox(app->getActiveMenu()->getComponent("pass"))->clear();
    }
}