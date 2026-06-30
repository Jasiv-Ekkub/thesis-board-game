#include <iostream>

#include <GameManager.hpp>

GameManager* GameManager::getInstance()
{
	static GameManager instance;
	return &instance;
}

void GameManager::changeScene(Scene* scene)
{
	nextScene = scene;
	refresh();
}

void GameManager::update()
{
	if(IsWindowResized())
	{
		refresh();
	}
	if(nextScene)
	{
		if(currentScene)
			currentScene->unload();
		currentScene = nextScene;
		nextScene = nullptr;
		currentScene->load();
	}
	if(currentScene)
		currentScene->update();
}

GameManager::~GameManager()
{
	if(currentScene)
		currentScene->unload();
}

const int& GameManager::getRenderWidth() { return renderWidth; }
const int& GameManager::getRenderHeight() { return renderHeight; }

void GameManager::refresh()
{
	renderWidth = GetRenderWidth();
	renderHeight = GetRenderHeight();
}


