#include "../buttons.hpp"

void demoButton_action ()
{
    easyGUI::Application* app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        easyGUI::Menu* menu = app->getActiveMenu();

        std::string user = easyGUI::Converter::getTextbox(menu->getComponent(3))->getText();
        std::string pass = easyGUI::Converter::getPasswordBox(menu->getComponent(4))->getText();

        INFO << pass << "\n";

        if(user == "admin" && pass == "admin")
        {
            app->setActiveMenu(1);
        }
    }
}