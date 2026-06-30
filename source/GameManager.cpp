#define ISCENE_IMPLEMENTATION
#include <GameManager.hpp>

GameManager* GameManager::getInstance()
{
	static GameManager instance;
	return &instance;
}

void GameManager::changeScene(Scene* scene)
{
	nextScene = scene;
}

void GameManager::update()
{
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
