#include <iostream>
#include <windows.h>
#include <locale>


int main() {
    {
        // Get the handle to the console window
        HWND hwnd = GetConsoleWindow();

        // Get the handle to the console's output buffer
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // Set the font of the console window to "Consolas"
        CONSOLE_FONT_INFOEX fontInfo = {0};
        fontInfo.cbSize = sizeof(fontInfo);
        fontInfo.dwFontSize.Y = 16;
        wcscpy_s(fontInfo.FaceName, L"Consolas");
        SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    }

    {
        // don't know what is it
        // const std::ctype<wchar_t>& my_MM_facet = std::use_facet<std::ctype<wchar_t> >(std::locale(std::locale(), new my_MM_UTF_8));

        // Set the console output encoding to UTF-8
        std::locale::global(std::locale("my_MM.UTF-8"));

        // Print Burmese text to the console
        // should fail, not every system has this locale
        std::wcout << L"မင်္ဂလာပါ" << std::endl; 
    }

    // Output a message in the console window
    std::cout << "Hello, world!" << std::endl;

    return 0;
}
