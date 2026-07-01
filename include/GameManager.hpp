#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <raylib.h>

#include <Scene.hpp>

struct DisplayInfo
{
	int renderWidth;
	int renderHeight;
};

class GameManager
{
	Scene* currentScene;
	Scene* nextScene;

	GameManager() = default;
	~GameManager();

	DisplayInfo displayInfo;

	public:
	static GameManager& getInstance();

	void changeScene(Scene* scene);
	void update();

	void refresh();
	const DisplayInfo& getDisplayInfo();
};

#else

class GameManager;

#endif
