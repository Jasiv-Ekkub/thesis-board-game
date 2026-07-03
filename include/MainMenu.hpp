#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <raylib.h>

#include <Scene.hpp>

class MainMenu : public Scene
{
	MainMenu() = default;

	Texture2D logoImage;

	public:
	void load() override;
	void update() override;
	void unload() override;

	static MainMenu* getInstance();
};

#endif
