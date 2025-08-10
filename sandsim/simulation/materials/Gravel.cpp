#include "Gravel.hpp"

namespace sandsim{
	Gravel::Gravel(): Tile(GRAVEL, ColorMap[GRAVEL]) {
		shadingSize=20;
		Gravel::set_shading();
	}
	
	int Gravel::getType() const {
		return GRAVEL;
	}
	
	void Gravel::update(EChunk& inside_chunk, int x, int y) {
		
		int rightIndex = inside_chunk.getTileDataAt(y , x+1);
		int leftIndex = inside_chunk.getTileDataAt(y , x-1);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
	
		if (rightIndex == AIR||leftIndex==AIR||rightIndex == WATER||leftIndex==WATER) {
			if(belowIndex==AIR||belowIndex==WATER){
				inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
			}
		}
	}
}