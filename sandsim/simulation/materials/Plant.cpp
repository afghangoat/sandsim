#include "Plant.hpp"

namespace sandsim{
	Plant::Plant(): Tile(PLANT, ColorMap[PLANT]) {
		shadingSize=18;
		Plant::set_shading();
	}
	
	int Plant::getType() const {
		return PLANT;
	}
	
	void Plant::update(EChunk& inside_chunk, int x, int y) {
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int upIndex = inside_chunk.getTileDataAt(y - gameConfig.global_gravity , x);
		int upRightIndex = inside_chunk.getTileDataAt(y - gameConfig.global_gravity , x+1);
		int upLeftIndex = inside_chunk.getTileDataAt(y - gameConfig.global_gravity , x-1);
	
		if (belowIndex == WATER||upIndex==GRAVEL||upIndex==DIRT) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
	
		}
		//GROW
		else if (rand()%gameConfig.plant_growth_rate==0) { //belowIndex == DIRT && upIndex == WATER
			if(rand()%4!=0&&upIndex==AIR){
				inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Plant>());
			} else if(rand()%2==0&&upRightIndex==AIR){
				inside_chunk.setTileAt(y-gameConfig.global_gravity,x+1,std::make_shared<Plant>());
			} else if(upLeftIndex==AIR){
				inside_chunk.setTileAt(y-gameConfig.global_gravity,x-1,std::make_shared<Plant>());
			}
		
		//PETAL BLOOM
		} else if(rand()%(gameConfig.plant_growth_rate*gameConfig.plant_petal_rate)==0){
			inside_chunk.setTileAt(y-gameConfig.global_gravity,x-1,std::make_shared<Petal>());
		}
	}
}