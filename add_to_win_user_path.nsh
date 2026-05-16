!define APP_PATH "$INSTDIR\\bin"

Section -Post
    ReadRegStr $0 HKCU "Environment" "Path"
    StrCpy $1 "$0;${APP_PATH}"
    WriteRegStr HKCU "Environment" "Path" $1
    SendMessage ${HWND_BROADCAST} ${WM_SETTINGCHANGE} 0 "STR:Environment"
SectionEnd
