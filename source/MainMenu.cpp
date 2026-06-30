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
	int buttonWidth = gameManager->getRenderWidth()/4 - 20;
	if(GuiButton(gameManager->getAnchoredRectangle<1,3,1,2>(0, 0, buttonWidth, 50), "Options"))
	{
		gameManager->changeScene(Options::getInstance());
	}
	if(GuiButton(gameManager->getAnchoredRectangle<2,3,1,2>(0, 0, buttonWidth, 50), "Options"))
	{
		gameManager->changeScene(Options::getInstance());
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
