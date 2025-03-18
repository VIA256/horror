#ifndef HPP_HORROR_GAME_HPP
#define HPP_HORROR_GAME_HPP

#include <irrlicht/irrlicht.h>

namespace horror{
	class Game{
	private:
		irr::IrrlichtDevice* device = NULL;
		irr::scene::ISceneManager* smgr = NULL;
		irr::video::IVideoDriver* driver = NULL;
		irr::gui::IGUIEnvironment* guienv = NULL;

	public:
		irr::IrrlichtDevice* getDevice();
		irr::scene::ISceneManager* getSmgr();
		irr::video::IVideoDriver* getDriver();
		irr::gui::IGUIEnvironment* getGuienv();

		bool init();
		void loop();
		void cleanup();
	};
}

#endif
