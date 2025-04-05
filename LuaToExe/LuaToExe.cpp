#include <iostream>
#include <fstream>
#include <termcolor/termcolor.hpp>
#include <windows.h>

std::string encrypt(std::string c) {
    auto size = c.size();
    std::string enc;
    enc.reserve(size);
    for (char ch : c) {
        enc.push_back(ch + 42);
    }
    return enc;
}

int main()
{
    char filename[512];
    std::cout << termcolor::cyan << "Welcome to LuaToExe\nMade by Defacube\n";
    std::cout << "Enter full file path: ";
    std::cin >> filename;
    std::cout << "\n";
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        std::cout << termcolor::red << "Error opening input file.\n" << termcolor::white;
        char temp[1];
        std::cin >> temp;
        exit(1);
    }
    std::string code_dec((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    in.close();
    std::string code = encrypt(code_dec);
    RemoveDirectoryA("output");
    system("mkdir output > NUL");
    system("copy LuaToExeBINARY.exe output > NUL");
    system("copy lua53.dll output > NUL");
    /*HANDLE h = CreateFileA("output\\lua.bin",
        GENERIC_WRITE, 
        0,             
        0,             
        CREATE_ALWAYS, 
        FILE_ATTRIBUTE_NORMAL,
        0);
    if (!h) {
        std::cout << termcolor::red << "Error creating lua.bin file.\n" << termcolor::white;
        char temp[1];
        std::cin >> temp;
        exit(1);
    }*/
    std::ofstream out("output\\lua.bin", std::ios::binary);
    out << code;
    out.close();
    std::cout << termcolor::green << "Success!\n" << termcolor::white;
    char temp[1];
    std::cin >> temp;
    return 0;
}