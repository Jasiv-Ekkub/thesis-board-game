#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <raylib.h>

#include <Scene.hpp>

class GameManager
{
	Scene* currentScene;
	Scene* nextScene;

	GameManager() = default;
	~GameManager();

	int renderWidth;
	int renderHeight;

	public:
	static GameManager* getInstance();

	void changeScene(Scene* scene);
	void update();

	void refresh();
	const int& getRenderWidth();
	const int& getRenderHeight();

	template <int x, int X, int y, int Y>
	Rectangle getAnchoredRectangle(const int& px, const int& py, const int& sx, const int& sy)
	{
		return {
			(renderWidth - sx) * x / X + px,
			(renderHeight - sy) * y / Y + py,
			sx,
			sy
		};
	}
};
#else
class GameManager;

template <int x, int X, int y, int Y>
Rectangle getAnchoredRectangle(const int& px, const int& py, const int& sx, const int& sy);
#endif
