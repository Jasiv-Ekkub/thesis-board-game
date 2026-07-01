#include <LayoutEngine.hpp>
#include <GameManager.hpp>

LayoutEngine::LayoutEngine(const DisplayInfo& displayInfo): displayInfo(displayInfo) {}

LayoutEngine& LayoutEngine::getInstance()
{
	static LayoutEngine instance(GameManager::getInstance().getDisplayInfo());
	return instance;
}

void LayoutEngine::setupGrid(const int& columns, const int& rows, const int& border)
{
	this->columns = columns;
	this->rows = rows;
	this->border = border;
}

Rectangle LayoutEngine::getPlacement(const int& leftCell, const int& rightCell, const int& topCell, const int& bottomCell)
{
	if(leftCell > rightCell || topCell > bottomCell ||
		leftCell < 0 || topCell < 0 ||
		rightCell >= columns || bottomCell >= rows
		) return {};

	int deltaX = displayInfo.renderWidth / columns;
	int deltaY = displayInfo.renderHeight / rows;

	return {
		leftCell * deltaX + border,
		topCell * deltaY + border,
		(rightCell - leftCell + 1) * deltaX - (border<<1),
		(bottomCell - topCell + 1) * deltaY - (border<<1) 
		};
}
