#include <Scene.hpp>

Scene::~Scene()
{
	if(isLoaded)
	{
		unload();
	}
}

void Scene::load()
{
	isLoaded = true;
}

void Scene::update(){}

void Scene::unload()
{
	isLoaded = false;
}
