#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include <GameManager.hpp>
#include <MainMenu.hpp>

GameManager* gameManager = GameManager::getInstance();

int main()
{
	InitWindow(800, 600, "Business Cities");

	gameManager->changeScene(MainMenu::getInstance());

	while (!WindowShouldClose())
	{
		BeginDrawing();
		gameManager->update();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
