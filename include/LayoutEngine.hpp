#ifndef LAYOUTENGINE_HPP
#define LAYOUTENGINE_HPP

#include <raylib.h>

#include <GameManager.hpp>

class LayoutEngine
{
	const DisplayInfo& displayInfo;
	int columns;
	int rows;
	int border;

	LayoutEngine(const DisplayInfo& displayInfo);

	public:
	LayoutEngine(const LayoutEngine&) = delete;
	LayoutEngine& operator=(const LayoutEngine&) = delete;

	static LayoutEngine& getInstance();
	void setupGrid(const int& columns, const int& rows, const int& border);
	Rectangle getPlacement(const int& leftCell, const int& rightCell, const int& topCell, const int& bottomCell);
};

#endif
