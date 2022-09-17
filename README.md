# EasyGUI ![Build](https://github.com/HV0rtex/ThreadPool/workflows/Linux/badge.svg?branch=main)

EasyGUI is an extension to the popular C++ graphics library: SFML.

The purpose of the extension is to remove the unnecessary work of creating standard GUI elements such as labels,
buttons, textboxes and so on. This way, you can focus more on the application logic and not waste meaningless time
creating a GUI.

## Table of contents

- [How it works](#how-it-works)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Support](#support)

## How it works

The extension provides wrapper classes around the standard SFML components, allowing you to create labels or even buttons
in just one line of code, saving you from the tedious work of doing all the bindings yourself. For instance, in order to
create a button in SFML you would have to:

- Create a RectangleShape and give it bounds and color
- Create a Text
- Compile to see if text is centered / fits
- If it doesn't repeat from step 2.
- Create the event handler for the button

This workflow is tedious and unnecessary. With EasyGUI all that workflow is reduced to just these two lines:

```
egui::Button myButton ( 
    egui::utils::Point(startX, startY),     // <-- Top-left corner
    egui::utils::Point(endX, endY),         // <-- Bottom-right corner
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

This way, you don't need to worry wether the button text will fit. If the text fits inside the button borders,
it will be automatically centered, otherwise a warning will be issued and the text / shape will be readjusted accordingly.

## What is provided

In every realease, you will have provided both static and dynamic libraries to suit your prefered way of
linkage, the API headers as well as a demo project.

## Prerequisites

Before attempting to use the extension you must make sure you have the following dependencies installed:

- [SFML](https://www.sfml-dev.org/)

## Installation

After you have downloaded the release package specific for your operating system, please go the link corresponding
to your IDE:

- [Code::Blocks](#installation---codeblocks)
- [Visual Studio Code](#installation---vs-code)

If you didn't manage to find an appropriate release package, then follow these steps bellow:

1. Download the **src** directory and copy it inside your project
2. Append the headers and sources to your project to be built.

**Note: Depending on your build system, the third step may be achieved in different ways.**

## Installation - Code::Blocks

After you have downloaded the release package, follow these steps:

1. Unpack the package
2. Go to *Settings > Compiler > Search directories > Compiler* and add the **include** directory
3. Go to *Settings > Compiler > Search directories > Linker* and add the **lib** directory
4. Go to *Settings > Linker > Libraries* and add the following libraries, in this order:
   - easyGUI-application
   - easyGUI-assets
5. Make sure that this order of linkage is verified
   - easyGUI-application
   - easyGUI-assets
   - sfml-graphics
   - sfml-window
   - sfml-system

Then you can try and build one of the examples in order to test that everything works accordingly

## Installation - VS Code

After you have downloaded the release package, follow these steps:

1. Unpack the package
2. Go to *Settings > Compiler > Include directories* and add the **include** directory
3. Go to *Settings > Linker > Search directories* and add the **lib** directory
4. Go to *Settings > Linker > Libraries* and add the following libraries, in this order:
   - easyGUI-application
   - easyGUI-assets

Then you can try and build one of the examples in order to test that everything works accordingly

## Support

The project is licensed under the **MIT License** and can be used free of charge. However if you would like to
support the development of this extension, follow one of these links depending on your preffered support method:

- [Buy me a coffee](buymeacoffee.com/hvrtx)
- [Report a bug](https://github.com/HV0rtex/ThreadPool/issues/new?assignees=HV0rtex&labels=bug&template=bug_report.md&title=)
- [Submit a suggestion](https://github.com/HV0rtex/ThreadPool/issues/new?assignees=HV0rtex&labels=enhancement&template=feature_request.md&title=)
