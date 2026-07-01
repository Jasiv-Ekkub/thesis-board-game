#include <raylib.h>
#include <raygui.h>

#include <GameManager.hpp>
#include <LayoutEngine.hpp>
#include <MainMenu.hpp>
#include <Options.hpp>

void MainMenu::load()
{
	//Loading
	Scene::load();
}

void MainMenu::update()
{
	LayoutEngine& le = LayoutEngine::getInstance();
	le.setupGrid(10,10,10);
	if(GuiButton(le.getPlacement(3,6,5,5), "Play"))
	{
	}
	if(GuiButton(le.getPlacement(3,6,6,6), "Options"))
	{
		gameManager.changeScene(Options::getInstance());
	}
	if(GuiButton(le.getPlacement(3,6,7,7), "Credits"))
	{
	}
	if(GuiButton(le.getPlacement(3,6,8,8), "Exit"))
	{
	}
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
