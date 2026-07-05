#include <raylib.h>
#include <raygui.h>

#include <GameManager.hpp>
#include <MainMenu.hpp>
#include <Options.hpp>

void Options::load()
{
	//Loading
	Scene::load();
}

void Options::update()
{
	if(GuiButton(layoutEngine.getPlacement(6,9,6,6), "Main Menu"))
	{
		gameManager.changeScene(MainMenu::getInstance());
	}
	if(GuiButton(layoutEngine.getPlacement(6,9,5,5), "Toggle fullscreen"))
	{
		ToggleFullscreen();
	}
}

void Options::unload()
{
	//Unloading
	Scene::unload();
}

Options* Options::getInstance()
{
	static Options instance;
	return &instance;
}
