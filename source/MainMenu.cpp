#include <raylib.h>
#include <raygui.h>

#include <GameManager.hpp>
#include <MainMenu.hpp>
#include <Options.hpp>

void MainMenu::load()
{
	//Loading
	Scene::load();
}

void MainMenu::update()
{
	ClearBackground(RAYWHITE);
	if(GuiButton({10, 10, 500, 50}, "Options"))
		GameManager::getInstance()->changeScene(Options::getInstance());
}

void MainMenu::unload()
{
	//Unloading
	Scene::unload();
}

MainMenu* MainMenu::getInstance()
{
	static MainMenu instance;
	return &instance;
}
