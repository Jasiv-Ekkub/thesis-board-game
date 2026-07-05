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
	bool isExiting;

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

	const bool& getIsExiting();
	void setIsExiting(bool isExiting);
};

#else

struct DisplayInfo;
class GameManager;

#endif
