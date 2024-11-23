OutFile "Online_IDE_Installer.exe"
InstallDir "$PROGRAMFILES\Online_IDE"

# Installer Section
Section "Install"
    CreateDirectory "$INSTDIR"
    SetOutPath "$INSTDIR"
    
    # Include all files from the debug folder
    File /r "G:\Online_IDE\build\Desktop_Qt_6_8_0_MSVC2022_64bit-Debug\debug\*.*"
    
    # Include the YouTube.ico icon
    File "G:\Online_IDE\onlineide.ico"
    
    # Include Qt libraries
    File "C:\Qt\6.8.0\msvc2022_64\bin\Qt6Core.dll"
    File "C:\Qt\6.8.0\msvc2022_64\bin\Qt6Gui.dll"
    File "C:\Qt\6.8.0\msvc2022_64\bin\Qt6Widgets.dll"
    File "C:\Qt\6.8.0\msvc2022_64\bin\Qt6Network.dll"
    File "C:\Qt\6.8.0\msvc2022_64\bin\Qt6WebEngineCore.dll"
    
    # Include Qt platform plugins (qwindows.dll)
    File /r "C:\Qt\6.8.0\msvc2022_64\plugins\platforms\*.*"

    # Create shortcuts
    CreateShortcut "$DESKTOP\Online IDE.lnk" "$INSTDIR\Online_IDE.exe" "$INSTDIR\onlineide.ico"
    CreateDirectory "$SMPROGRAMS\Online_IDE"
    CreateShortcut "$SMPROGRAMS\Online_IDE\Online_IDE.lnk" "$INSTDIR\Online_IDE.exe" "$INSTDIR\onlineide.ico"
    
    # Write uninstaller
    WriteUninstaller "$INSTDIR\Online_IDE_uninstall.exe"
    CreateShortcut "$SMPROGRAMS\Online_IDE\Online_IDE_uninstall.lnk" "$INSTDIR\Online_IDE_uninstall.exe"
SectionEnd

# Uninstaller Section
Section "Uninstall"
    Delete "$INSTDIR\*.*"
    RMDir "$INSTDIR"
    Delete "$DESKTOP\Online_IDE.lnk"
    Delete "$SMPROGRAMS\Online_IDE\Online_IDE.lnk"
    Delete "$SMPROGRAMS\Online_IDE\Online_IDE_uninstall.lnk"
    RMDir "$SMPROGRAMS\Online_IDE"
SectionEnd
