#include "game.hpp"

#include <iostream>

using namespace horror;

irr::IrrlichtDevice* Game::getDevice(){
	return this->device;
}

irr::scene::ISceneManager* Game::getSmgr(){
	return this->smgr;
}

irr::video::IVideoDriver* Game::getDriver(){
	return this->driver;
}

irr::gui::IGUIEnvironment* Game::getGuienv(){
	return this->guienv;
}

bool Game::init(){
	this->device = irr::createDevice(
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(640, 480),
		16,
		false,
		false,
		true,
		0
	);

	if(!this->device){
		std::cout << "Failed to create irrlicht device." << std::endl;
		return false;
	}

	this->device->setWindowCaption(L"The Horror");

	this->driver = this->device->getVideoDriver();
	this->smgr = this->device->getSceneManager();
	this->guienv = this->device->getGUIEnvironment();

	return true;
}

void Game::loop(){
	while(this->device->run()){
		this->driver->beginScene(true, true, irr::video::SColor(255, 127, 0, 127));

		this->smgr->drawAll();
		this->guienv->drawAll();

		this->driver->endScene();
	}
}

void Game::cleanup(){
	this->device->drop();
}
