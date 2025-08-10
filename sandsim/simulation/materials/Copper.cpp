#include "Copper.hpp"

namespace sandsim{
	Copper::Copper(): Tile(COPPER, ColorMap[COPPER]) {
		shadingSize=20;
		Copper::set_shading();
	}
	
	int Copper::getType() const {
		return COPPER;
	}
	
	void Copper::update(EChunk& inside_chunk, int x, int y) {
		
		//TODO make it generate smoke on electricity
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR || belowIndex == WATER || belowIndex == SAND) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		}else if (leftBelowIndex == AIR || leftBelowIndex == WATER || belowIndex == SAND) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		}else if ( rightBelowIndex == AIR || rightBelowIndex == WATER || belowIndex == SAND) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		}
	}
}