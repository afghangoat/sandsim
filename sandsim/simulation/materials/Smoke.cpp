#include "Smoke.hpp"

namespace sandsim{
	Smoke::Smoke(): Tile(SMOKE, ColorMap[SMOKE]) {
		shadingSize=20;
		Smoke::set_shading();
	}
	
	int Smoke::getType() const {
		return SMOKE;
	}
	
	void Smoke::update(EChunk& inside_chunk, int x, int y) {
		
		int chmod=0;
		int upIndex = (y - gameConfig.global_gravity) * gameConfig.CHUNK_SIZE + x;
		if (y <=0) {
			chmod=gameConfig.global_gravity;
			upIndex+=gameConfig.CHUNK_SIZE;
		}
			
		int randdir=0;
		if(rand()%2==0){
			randdir=1;
		}
		else if(rand()%2==0){
			randdir=-1;
		}
		
		int d=inside_chunk.getTileDataAt(upIndex+randdir);
		if (d == AIR ) {
			inside_chunk.swapTiles(y, x, y - gameConfig.global_gravity+chmod, x+randdir);
			if(rand()%100==0){
				inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
			}
		}
	}
}