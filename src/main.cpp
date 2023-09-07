#include <iostream>
#include <locale>

int main()
{
    // Set the console output encoding to UTF-8
    std::locale::global(std::locale("en_US.UTF-8"));

    // Print Burmese text to the console
    std::wcout << L"မင်္ဂလာပါ" << std::endl;

    return 0;
}