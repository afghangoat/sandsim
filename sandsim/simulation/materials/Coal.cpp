#include "Coal.hpp"

namespace sandsim{
	Coal::Coal(): Tile(COAL, ColorMap[COAL]) {
		shadingSize=18;
		Coal::set_shading();
	}
	
	int Coal::getType() const {
		return COAL;
	}
	
	void Coal::update(EChunk& inside_chunk, int x, int y) {
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR || belowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
	
		}
		
		else if (leftBelowIndex == AIR || leftBelowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
	
		}
		
		else if ( rightBelowIndex == AIR || rightBelowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		}
	}
}