# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Version V3.0.0 - Packaging Overhaul

This release adds support for CMake and CPack pacakges, many OS optimizations and a lot more
features to the Assets and Application libraries. This is also the first release which has been
thoroughly tested for both performance and functionality.

## Added

Project management:
- Added GUI to CLI and you can now created interfaces using the CLI.
- Added UI customization file from where you can easily customize the entire application

GUI elements:
- Added Slider
- Added Radiobox
- Reworked buttons and other old elements
- Added preloaded font

Application control:
- Tweaked callback support
- Added support for multi-windowed applications
- Added different moments where routines can be executed
- Added non-event-based routines

Customization options:
- Added a configuration file where default customizations are provided
- Added ability to change all elements via customization file

Library support:
- The library can now be included in CMake projects via find_package
- The library can now be downloaded from APT (on linux) and WINGET (on Windows)

Testing:
- Added unit tests for several components
- Added quality tests which measure CPU / GPU and memory usage

Optimizations:
- Tweaked easyGUI::Point functions
- Reduced memory usage by adding a component manager

## Fixed

Optimizations:
- Fixed Windows compilation warnings

## Removed

GUI Elements:
- Button (can now be replaced with a framed Label)

## Version V2.1.0 - Performance update (04.03.2023)

This release introduces new UI Elements and brings some performance improvements across all operating systems.
This version also introduces some new customization options for Labels and Images. Furthermore, with each release
package comes an executable which can be used to setup projects faster by providing code generation methods.

## Added

Project management:
- Added CLI for managing projects

GUI Elements:
- Line separator

Application control:
- Added support for custom functions (with any arguments / return type)

Customization options:
- Images can now be framed.
- Added text decoration options (bold, italic, underline)

Library support:
- Windows SHARED libraries

## Fixed

Bugs:
- Bug where application crashes with multiple initial menu error
- Bug where image wouldn't scale properly
- Bug where button text would exceed bounds

Libraries:
- Windows SHARED libraries

Optimizations:
- Improved performance of Routine handling
- Reduced memory consumption
- Removed memory leaks

Documentation:
- Updated installation guide
- Updated usage guide
- Updated README file
- Updated code documentation

## Removed

Libraries:
- Exceptions library

## Version V2.0.1 - Windows maintanance (7.12.2022)

This release drops the support for **shared libraries** on Windows OS, due to linkage errors found in testing.
The support will be continued once the errors have been fixed in an upcomming version. Furthermore, this patch fixes
static linkage on windows.

## Removed

Library support:
- Windows SHARED libraries

## Fixed

Library support:
- Windows STATIC libraries

## Version V2.0.0 - GUI Overhaul (5.12.2022)

This release provides many performance improvements as well as some quality of life improvements
such as access to the internal parts for more flexibility. On top of that, more GUI elements are 
added and the documentation has been improved.

Furthermore, the extension is now officially supported on all major operating systems (Windows, Linux adn MacOS).

## Added

Application control:
- Converter class to facilitate conversion between assets
- Internal component getter methods
- Components can now be moved by routines
- Application now scales with window size
- Added option to align elements in respect to other elements or the window

GUI Elements:
- Text box
- Password box
- Check box
- Image

## Fixed

Application control:
- Menus and components are linked to a unique ID now
- Fixed memory leaks caused by singletons.

Source files:
- Reworked demo project to be more meaningful
- Lowered header file dimensions

GUI Elements:
- Reworked FontManager as a template class that manages multiple assets.
- Lowered the amount of arguments in constructors (missing arguments have been set as default options)

## Removed

Source control:
- Removed the testing phase
- Removed Unit Test artefact
- Removed tests directory

## Version V1.1.0 - Documentation overhaul (7.10.2022)

This release provides an overhaul to the existing documentation and an improvement to the overall
understanding and ease of use of the extension.

## Added

Source documentation:
- Extensive installation guide
- User manual

Application control:
- Logging system
- Custom exceptions

## Fixed

Source documentation:
- Reworked the documentation of the demo project's sources
- Reworked the class documentation generated by Doxygen
- README file is now easier to navigate
- Changelog is now up to date

## Removed

Nothing has been removed.

## Version V1.0.0 - First Release (18.09.2022)

This is the first release of the extension. As of right now, only basic facilities are supported:
- App creation
- Labels
- Buttons
- Routines

Note: **The application is not yet responsive**, as that feature has not been implemented. However
the Button's text is automatically centered withing the button borders.

The application provides a demo project that shows how much work is simplified and provides a ground for further projects (as one can simply use the skeleton provided in the demo), as well as standard **Doxygen** documentation.

### Added

Application control:
- Size
- Title
- Routines

GUI Elements:
- Label
- Button

Source documentation
- Doxygen documentation
- Demo application

### Fixed

As this is the first release, there are now fixes / bug reports.

### Removed

As this is the first release, no elements have been removed.