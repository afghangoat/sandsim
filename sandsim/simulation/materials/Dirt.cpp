#include "Dirt.hpp"

namespace sandsim{
	Dirt::Dirt(): Tile(DIRT, ColorMap[DIRT]) {
		shadingSize=20;
		Dirt::set_shading();
	}
	
	int Dirt::getType() const {
		return DIRT;
	}
	
	void Dirt::update(EChunk& inside_chunk, int x, int y) {
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR || belowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		} else if (rand()%4==0 && (leftBelowIndex == AIR || leftBelowIndex == WATER)) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		} else if (rand()%4==0 && (rightBelowIndex == AIR || rightBelowIndex == WATER)) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		}
	}
}