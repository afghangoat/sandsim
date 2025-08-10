#include "Glue.hpp"

namespace sandsim{
	Glue::Glue(): Tile(GLUE, ColorMap[GLUE]) {
		shadingSize=16;
		Glue::set_shading();
	}
	
	int Glue::getType() const {
		return GLUE;
	}
	
	void Glue::update(EChunk& inside_chunk, int x, int y) {
		//int upIndex = getTileDataAt(y - 1 , x);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftIndex = inside_chunk.getTileDataAt(y , x - 1);
		int rightIndex = inside_chunk.getTileDataAt(y , x + 1);
	
		if (belowIndex == AIR && (rightIndex == AIR || rightIndex == GLUE) && (leftIndex == AIR || leftIndex == GLUE)) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		}
	}
}