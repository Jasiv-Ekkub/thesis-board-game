#include <raylib.h>

#include <Options.hpp>

void Options::load()
{
	//Loading
	Scene::load();
}

void Options::update()
{
	ClearBackground(GRAY);
}

void Options::unload()
{
	//Unloading
	Scene::unload();
}

Options* Options::getInstance()
{
	static Options instance;
	return &instance;
}
