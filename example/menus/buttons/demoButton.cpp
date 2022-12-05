#include "../buttons.hpp"

void demoButton_action ()
{
    easyGUI::Application* app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        easyGUI::Menu* menu = app->getActiveMenu();

        std::string user = easyGUI::Converter::getTextbox(menu->getComponent("uName"))->getText();
        std::string pass = easyGUI::Converter::getTextbox(menu->getComponent("pass"))->getText();

        if(user == "admin" && pass == "admin")
        {
            app->setActiveMenu("second");
        }
    }
}