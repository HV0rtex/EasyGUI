# EasyGUI ![Build](https://github.com/HV0rtex/EasyGUI/workflows/Linux/badge.svg?branch=main)

EasyGUI is an extension to the popular C++ graphics library: SFML.

The purpose of the extension is to remove the unnecessary work of creating standard GUI elements such as labels, buttons, textboxes and so on. This way, you can focus more on the application logic and not waste meaningless time creating a GUI.

## Table of contents

- [How it works](#how-it-works)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Support](#support)

## How it works

The extension provides wrapper classes around the standard SFML components, allowing you to create labels or even buttons in just one line of code, saving you from the tedious work of doing all the bindings yourself. For instance, in order to create a button in SFML you would have to:

- Create a RectangleShape and give it bounds and color
- Create a Text
- Compile to see if text is centered / fits
- If it doesn't repeat from step 2.
- Create the event handler for the button

This workflow is tedious and unnecessary. With EasyGUI all that workflow is reduced to just these two lines:

```
easyGUI::Button myButton ( 
    easyGUI::Point(startX, startY),         // <-- Top-left corner
    easyGUI::Point(endX, endY),             // <-- Bottom-right corner
    sf::Color(255,0,0),                     // <-- Border color
    sf::Color(0,0,0),                       // <-- Fill color
    sf::Color(255, 255, 255),               // <-- Text color

    "Demo button",                          // <-- Button text
    "/path/to/desired/font.ttf",            // <-- Desired font
    15,                                     // <-- Desired character size
    5                                       // <-- Border thickness
);

myButton.addOnClickAction ( action );       // <-- action is a void function with no params
```

This way, you don't need to worry wether the button text will fit. If the text fits inside the button borders, it will be automatically centered, otherwise the text / shape will be readjusted accordingly. For further information, please refer to our [User Manual](https://github.com/HV0rtex/EasyGUI/blob/main/docs/userManual.pdf).

## What is provided

In every realease, you will have provided both static and dynamic libraries to suit your prefered way of linkage, the API headers as well as a demo project.

## Prerequisites

Before attempting to use the extension you must make sure you have the following dependencies installed:

- [SFML](https://www.sfml-dev.org/)

## Installation

After downloading the realease package for your operating system (Note: For Windows you need to check the OS version: 32/64 bit and download the corresponding package), check out the [Installation Guide](https://github.com/HV0rtex/EasyGUI/blob/main/docs/installationGuide.pdf) in order to set everything up for your IDE.

## Support

The project is licensed under the **MIT License** and can be used free of charge. However if you would like to support the development of this extension, follow one of these links depending on your preffered support method:

- [Buy me a coffee](buymeacoffee.com/hvrtx)
- [Report a bug](https://github.com/HV0rtex/EasyGUI/issues/new?assignees=HV0rtex&labels=bug&template=bug_report.md&title=)
- [Submit a suggestion](https://github.com/HV0rtex/EasyGUI/issues/new?assignees=HV0rtex&labels=enhancement&template=feature_request.md&title=)
