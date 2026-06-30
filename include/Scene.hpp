#ifndef SCENE_HPP
#define SCENE_HPP

class Scene
{
	bool isLoaded;

	protected:
	Scene() = default;
	~Scene();

	public:
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	virtual void load();
	virtual void update();
	virtual void unload();
};

#endif
