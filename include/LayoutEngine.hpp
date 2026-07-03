#ifndef LAYOUTENGINE_HPP
#define LAYOUTENGINE_HPP

#include <raylib.h>
#include <cstdint>

#include <GameManager.hpp>

using namespace std;

class LayoutEngine
{
	const DisplayInfo& displayInfo;
	uint8_t columns;
	uint8_t rows;
	uint8_t border;

	LayoutEngine(const DisplayInfo& displayInfo);

	public:
	LayoutEngine(const LayoutEngine&) = delete;
	LayoutEngine& operator=(const LayoutEngine&) = delete;

	static LayoutEngine& getInstance();
	void setupGrid(const uint8_t& columns, const uint8_t& rows, const uint8_t& border);
	Rectangle getPlacement(const uint8_t& leftCell, const uint8_t& rightCell, const uint8_t& topCell, const uint8_t& bottomCell);
	Rectangle getFittedPlacement(const uint8_t& leftCell, const uint8_t& rightCell, const uint8_t& topCell, const uint8_t& bottomCell, const float& ratio);
};

#else

class LayoutEngine;

#endif
