#include "Sapling.hpp"

namespace sandsim{
	Sapling::Sapling(): Tile(SAPLING, ColorMap[SAPLING]) {
		shadingSize=20;
		Sapling::set_shading();
	}
	
	int Sapling::getType() const {
		return SAPLING;
	}
	
	void Sapling::update(EChunk& inside_chunk, int x, int y) {
		int upIndex = inside_chunk.getTileDataAt(y-gameConfig.global_gravity , x);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftIndex = inside_chunk.getTileDataAt(y , x-1);
		int rightIndex = inside_chunk.getTileDataAt(y , x+1);
	
		if (belowIndex == AIR&&rightIndex!=WOOD&&leftIndex!=WOOD) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		}
		
		else if ((belowIndex==WOOD||belowIndex==DIRT||rightIndex==WOOD||leftIndex==WOOD)&&upIndex == AIR&&rand()%(gameConfig.plant_growth_rate/2)==0) {
			
			inside_chunk.setTileAt(y,x,std::make_shared<Wood>());
			if(rand()%(gameConfig.plant_growth_rate/3)==0){
				if(rand()%2==0&&leftIndex==AIR){
					inside_chunk.setTileAt(y,x-1,std::make_shared<Sapling>());
				} else if(rightIndex==AIR){
					inside_chunk.setTileAt(y,x+1,std::make_shared<Sapling>());
				}
			}
			if(rand()%(gameConfig.plant_growth_rate*gameConfig.plant_petal_rate)==0){
				inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Leaves>());
			} else {
				inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Sapling>());
			}
		}
	}
}