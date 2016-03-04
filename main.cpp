// Goal: Embed Lua to a C++ program with a custom class
// Goal: Use templates to define the Lua class

#include <iostream>


extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

void defineInstanceLib(lua_State *L) {
	lua_createtable(L, 0, 0);

	lua_pushstring(L, "HELLO");
	lua_pushstring(L, "WORLD");
	
	lua_settable(L, -3);
	lua_setglobal(L, "Instance");
}

int main() {
	std::cout << "Hello world" << std::endl;

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, "main.lua")) {
		std::cerr << "Failed to load main.lua" << std::endl;
		std::cerr << lua_tostring(L, -1) << std::endl;
		lua_pop(L, 1);
	}

	defineInstanceLib(L);

	if(lua_pcall(L, 0, LUA_MULTRET, 0)) {
		std::cerr << "Failed to execute main.lua" << std::endl;
		std::cerr << lua_tostring(L, -1) << std::endl;
		lua_pop(L, 1);
	}

	lua_close(L);

	return 0;
}