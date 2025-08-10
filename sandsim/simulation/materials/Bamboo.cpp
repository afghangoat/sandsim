#include "Bamboo.hpp"

namespace sandsim{
	Bamboo::Bamboo(): Tile(BAMBOO, ColorMap[BAMBOO]) {
		shadingSize=20;
		Bamboo::set_shading();
	}
	
	int Bamboo::getType() const {
		return BAMBOO;
	}
	
	void Bamboo::update(EChunk& inside_chunk, int x, int y) {
		
		// bamboo (grows upwards on sand, only on sand and dirt), 
		int upIndex = inside_chunk.getTileDataAt(y-gameConfig.global_gravity , x);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
	
		if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		} else if ((belowIndex==SAND||belowIndex==BAMBOO||belowIndex==DIRT)&&upIndex == AIR&&rand()%gameConfig.plant_growth_rate==0) {
			inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Bamboo>());
		}
	}
}