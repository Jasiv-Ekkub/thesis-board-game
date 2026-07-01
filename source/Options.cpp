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
	if(GuiButton({10, 10, 250, 50}, "Main menu"))
	{
		gameManager.changeScene(MainMenu::getInstance());
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
