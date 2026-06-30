#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <Scene.hpp>

class GameManager
{
	Scene* currentScene;
	Scene* nextScene;

	GameManager() = default;
	~GameManager();

	public:
	static GameManager* getInstance();

	void changeScene(Scene* scene);
	void update();
};

#endif
