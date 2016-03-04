#include "instance.hpp"

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

void defineInstanceLib(lua_State *L) {
	lua_createtable(L, 0, 0);
	lua_setglobal(L, "Instance");
}