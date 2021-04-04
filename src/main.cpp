#ifndef LUASCRIPT_H
#define LUASCRIPT_H
#endif

#define LUA_OK 0

#include <iostream>
#include <string>
#include "lua.hpp"

int main() {
    std::string welcome = "--== LUA Test App ==--\n";
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    printf("%s", welcome.c_str()); // say hello

    if (luaL_dofile(L, "../data/test.lua") == LUA_OK)
    {
        printf("Lua ran properly!\n");
    }
    else {
        printf("Lua failed to run.\n");
        printf("Error: %s", lua_tostring(L, -1));
    }

    lua_close(L);
    printf("%s", welcome.c_str()); // say goodbye
    return 0;
}