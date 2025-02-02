#include "main.h"

#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

lua_State* L;

lua_State* getLuaState(){
	return L;
}

#include <stdio.h>

int main(void){
	L = luaL_newstate();
	luaL_openlibs(L);
	
	if(luaL_dofile(L, "hello.lua") != LUA_OK){
		printf("error running \"hello.lua\"\n");
		return -1;
	}
	
	return 0;
}
