#include <LayoutEngine.hpp>
#include <GameManager.hpp>

LayoutEngine::LayoutEngine(const DisplayInfo& displayInfo): displayInfo(displayInfo) {}

LayoutEngine& LayoutEngine::getInstance()
{
	static LayoutEngine instance(GameManager::getInstance().getDisplayInfo());
	return instance;
}

void LayoutEngine::setupGrid(const uint8_t& columns, const uint8_t& rows, const uint8_t& border)
{
	this->columns = columns;
	this->rows = rows;
	this->border = border;
}

Rectangle LayoutEngine::getPlacement(const uint8_t& leftCell, const uint8_t& rightCell, const uint8_t& topCell, const uint8_t& bottomCell)
{
	if(leftCell > rightCell || topCell > bottomCell ||
		leftCell < 0 || topCell < 0 ||
		rightCell >= columns || bottomCell >= rows
		) return {};

	uint64_t deltaX = displayInfo.renderWidth / columns;
	uint64_t deltaY = displayInfo.renderHeight / rows;

	return {
		leftCell * deltaX + border,
		topCell * deltaY + border,
		(rightCell - leftCell + 1) * deltaX - (border<<1),
		(bottomCell - topCell + 1) * deltaY - (border<<1) 
		};
}
Rectangle LayoutEngine::getFittedPlacement(const uint8_t& leftCell, const uint8_t& rightCell, const uint8_t& topCell, const uint8_t& bottomCell, const float& ratio)
{
	Rectangle rect = getPlacement(leftCell, rightCell, topCell, bottomCell);

	Rectangle retu;
	
	if(rect.width/rect.height < ratio)
	{
		retu.width = rect.width;
		retu.height = rect.width / ratio;
	}
	else
	{
		retu.width = rect.height * ratio;
		retu.height = rect.height;
	}

	retu.x = ((rect.width - retu.width) / 2) + rect.x;
	retu.y = ((rect.height - retu.height) / 2) + rect.y;

	return retu; 
}
