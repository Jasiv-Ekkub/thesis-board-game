#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <Scene.hpp>

class MainMenu : public Scene
{
	MainMenu() = default;
	
	public:
	void load() override;
	void update() override;
	void unload() override;

	static MainMenu* getInstance();
};

#endif
