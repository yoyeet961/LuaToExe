#include <iostream>
#include <fstream>
#include <filesystem>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

std::string decrypt(std::string encrypted) {
    auto size = encrypted.size();
    std::string decrypted;
    decrypted.reserve(size);
    for (char ch : encrypted) {
        decrypted.push_back(ch - 42);
    }
    return decrypted;
}

int main()
{
    std::ifstream s("lua.bin");
    auto size = std::filesystem::file_size("lua.bin");
    std::string code_enc(size, ' ');
    s.read(&code_enc[0], size);
    std::string code = decrypt(code_enc);
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    int r = luaL_dostring(L, code.c_str());
    if (r != LUA_OK) {
        std::cout << "There was an error running the Lua code: " << lua_tostring(L, -1) << std::endl;
        char t[1];
        std::cin >> t;
    }
    lua_close(L);
    return 0;
}