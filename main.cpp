#include <irrlicht/irrlicht.h>

#include <iostream>

#include "game.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(){
	horror::Game game;
	if(!game.init()){
		std::cout << "Game initialization failed. Quitting..." << std::endl;
		return -1; 
	}

	game.loop();

	game.cleanup();

	return 0;
}
