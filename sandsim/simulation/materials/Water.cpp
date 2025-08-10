#include "Water.hpp"

namespace sandsim{
	Water::Water(): Tile(WATER, ColorMap[WATER]) {
		shadingSize=10;
		Water::set_shading();
	}
	
	int Water::getType() const {
		return WATER;
	}
	
	void Water::update(EChunk& inside_chunk, int x, int y) {
		int rightIndex = inside_chunk.getTileDataAt(y , x+1);
		int leftIndex = inside_chunk.getTileDataAt(y , x-1);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		}
	
		else if (leftBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		}
	
		else if (rightBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		} else if(rightIndex == AIR){ //Right
			inside_chunk.swapTiles(y, x, y, x + 1);
		} else if(leftIndex == AIR){ //Left
			inside_chunk.swapTiles(y, x, y, x - 1);
		}
	}
}