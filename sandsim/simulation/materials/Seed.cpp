#include "Seed.hpp"

namespace sandsim{
	Seed::Seed(): Tile(SEED, ColorMap[SEED]) {
		shadingSize=20;
		Seed::set_shading();
	}
	
	int Seed::getType() const {
		return SEED;
	}
	
	void Seed::update(EChunk& inside_chunk, int x, int y) {
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int upIndex = inside_chunk.getTileDataAt(y - gameConfig.global_gravity , x);
		
		if (belowIndex == AIR || belowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
	
		} else if (belowIndex == DIRT && upIndex == WATER) {
			
			inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Air>());
			inside_chunk.setTileAt(y,x,std::make_shared<Plant>());
	
		}
	}
}