#include "Oil.hpp"

namespace sandsim{
	Oil::Oil(): Tile(OIL, ColorMap[OIL]) {
		shadingSize=10;
		Oil::set_shading();
	}
	
	int Oil::getType() const {
		return OIL;
	}
	
	void Oil::update(EChunk& inside_chunk, int x, int y) {
		
		int upIndex = inside_chunk.getTileDataAt(y-gameConfig.global_gravity , x);
		//int upRightIndex = getTileDataAt(y-1 , x+1);
		//int upLeftIndex = getTileDataAt(y-1 , x-1);
					
		int rightIndex = inside_chunk.getTileDataAt(y , x+1);
		int leftIndex = inside_chunk.getTileDataAt(y , x-1);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
					
		if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		} else if (leftBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		} else if (rightBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
			
		} else if(rightIndex == AIR){ //Right
			inside_chunk.swapTiles(y, x, y, x + 1);
			
		} else if(leftIndex == AIR){ //Left
			inside_chunk.swapTiles(y, x, y, x - 1);
			
		} else if (upIndex == WATER) {
			inside_chunk.swapTiles(y, x, y - gameConfig.global_gravity, x);
		} else if (rightIndex == WATER) {
			inside_chunk.swapTiles(y, x, y , x+1);
		} else if (leftIndex == WATER) {
			inside_chunk.swapTiles(y, x, y , x-1);
		}
	}
}