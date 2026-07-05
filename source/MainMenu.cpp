#include <raylib.h>
#include <raygui.h>

#include <GameManager.hpp>
#include <LayoutEngine.hpp>
#include <MainMenu.hpp>
#include <Options.hpp>

void MainMenu::load()
{
	Scene::load();
	logoImage = LoadTexture("resource/texture/texture0.png");
}

void MainMenu::update()
{
	DrawTexturePro(logoImage, {0,0,logoImage.width,logoImage.height}, layoutEngine.getFittedPlacement(3,12, 1, 3, 2), {}, 0, WHITE);
	if(GuiButton(layoutEngine.getPlacement(6,9,4,4), "Play"))
	{
	}
	if(GuiButton(layoutEngine.getPlacement(6,9,5,5), "Options"))
	{
		gameManager.changeScene(Options::getInstance());
	}
	if(GuiButton(layoutEngine.getPlacement(6,9,6,6), "Exit"))
	{
		gameManager.setIsExiting(true);
	}
}

void MainMenu::unload()
{
	Scene::unload();
	UnloadTexture(logoImage);
}

MainMenu* MainMenu::getInstance()
{
	static MainMenu instance;
	return &instance;
}
