#ifndef SCENE_HPP
#define SCENE_HPP

#include <GameManager.hpp>

class Scene
{
	bool isLoaded;

	protected:
	GameManager* gameManager;
	Scene();
	~Scene();

	public:
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	virtual void load();
	virtual void update();
	virtual void unload();
};
#else
class Scene;
#endif
