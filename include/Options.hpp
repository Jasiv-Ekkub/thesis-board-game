#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <Scene.hpp>

class Options : public Scene
{
	Options() = default;
	
	public:
	void load() override;
	void update() override;
	void unload() override;

	static Options* getInstance();
};

#endif
