#include "Algae.hpp"

namespace sandsim{
	Algae::Algae(): Tile(ALGAE, ColorMap[ALGAE]) {
		shadingSize=20;
		Algae::set_shading();
	}
	
	int Algae::getType() const {
		return ALGAE;
	}
	
	void Algae::update(EChunk& inside_chunk, int x, int y) {
		
		int upIndex = inside_chunk.getTileDataAt(y-gameConfig.global_gravity , x);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
	
		if (belowIndex == AIR||belowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		} else if (upIndex == WATER&&rand()%gameConfig.plant_growth_rate==0) {
			inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Algae>());
		}
	}
}