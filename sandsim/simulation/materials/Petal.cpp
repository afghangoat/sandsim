#include "Petal.hpp"

namespace sandsim{
	Petal::Petal(): Tile(PETAL, ColorMap[PETAL]) {
		shadingSize=18;
		Petal::set_shading();
	}
	
	int Petal::getType() const {
		return PETAL;
	}
	
	void Petal::update(EChunk& inside_chunk, int x, int y) {
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
	
		if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
	
		} else if(belowIndex==WATER){
			inside_chunk.setTileAt(y,x,std::make_shared<Air>());
		} else if(belowIndex==LAVA||belowIndex==FIRE){
			inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
		}
	}
}