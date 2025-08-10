#include "Steam.hpp"

namespace sandsim{
	Steam::Steam(): Tile(STEAM, ColorMap[STEAM]) {
		shadingSize=12;
		Steam::set_shading();
	}
	
	int Steam::getType() const {
		return STEAM;
	}
	
	void Steam::update(EChunk& inside_chunk, int x, int y) {
		int chmod=0;
		int upIndex = (y - gameConfig.global_gravity) * gameConfig.CHUNK_SIZE + x;
		if (y <=0) {
			chmod=gameConfig.global_gravity;
			upIndex+=gameConfig.CHUNK_SIZE;
		}
	
		int randdir=0;
		if(rand()%3==0){
			randdir=1;
		}
		else if(rand()%3==0){
			randdir=-1;
		}
		int d=inside_chunk.getTileDataAt(upIndex+randdir);
		if (d == AIR || d == WATER) {
			inside_chunk.swapTiles(y, x, y - gameConfig.global_gravity+chmod, x+randdir);
		}
	}
}