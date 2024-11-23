Online IDE


A simple Qt-based desktop browser application built using Qt 6.8 and QWebEngineView. This lightweight browser features basic navigation functionality such as URL loading, back, forward, and reload options.

Features
Open and navigate to any URL.
Desktop shortcut and Start Menu integration via an installer.
Requirements
Qt 6.8 with WebEngine module.
C++ Compiler: MSVC 2022.
Operating System: Windows (x64 recommended).
Dependencies:
Qt6WebEngineWidgets.dll
Qt6Core.dll
Qt6Widgets.dll
Installation
Using Prebuilt Installer
Download the Online_IDE_Installer.exe from the releases section.
Run the installer and follow the on-screen instructions.
Launch the application from the desktop shortcut or Start Menu.

Build from Source
Clone this repository:
bash
Copy code
git clone https://github.com/Electro-Robo-Gaming/Online_IDE.git
Open the project in Qt Creator or Visual Studio with the Qt plugin.
Build and run the project:
bash
Copy code
qmake && make
Usage
Launch the application.
Enter a URL in the address bar and press Enter.
Use the toolbar buttons for navigation:
Back: Go to the previous page.
Forward: Go to the next page.
Reload: Refresh the current page.
File Structure
bash
Copy code
Online_IDE/
├── src/
│   ├── main.cpp               # Entry point of the application
│   ├── onlineide.h           # onlineide class header
│   ├── onlineide.cpp         # onlineide class implementation
│   └── resources.qrc          # Resource file for icons
├── icons/
│   └── onlineide.ico            # Application icon
├── installer/
│   └── installer.nsi          # NSIS installer script
├── build/                     # Compiled binaries (generated after build)
├── README.md                  # Project documentation
└── LICENSE                    # License file
How to Package
After building the application, use windeployqt:
bash
Copy code
windeployqt --webengine Online_IDE.exe
Verify the following files are included in the build folder:
Required Qt DLLs (e.g., Qt6Core.dll, Qt6WebEngineWidgets.dll).
Plugins (e.g., platforms/qwindows.dll).
Executable (Online_IDE.exe).
Use the NSIS installer script to package the application:
bash
Copy code
makensis installer.nsi

Known Issues
Some web features may not work due to missing WebEngine dependencies.
Application may not run if required DLLs are not included.
Contributing
Fork the repository.
Create a new branch:
bash
Copy code
git checkout -b feature-branch
Commit your changes and push:
bash
Copy code
git commit -m "Added new feature"
git push origin feature-branch
Create a pull request.
License
This project is licensed under the MIT License.

Contact
Developer: Aroop V
Repository: Online IDE