#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <styles/style_cyber.h>

#include <GameManager.hpp>
#include <MainMenu.hpp>

GameManager& gameManager = GameManager::getInstance();

int main()
{
	InitWindow(800, 600, "Business Cities");
	SetWindowMinSize(800, 600);
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	GuiLoadStyleCyber();
	GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

	gameManager.changeScene(MainMenu::getInstance());

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

		gameManager.update();
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
