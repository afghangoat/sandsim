#include "Fire.hpp"

namespace sandsim{
	Fire::Fire(): Tile(FIRE, ColorMap[FIRE]) {
		shadingSize=22;
		Fire::set_shading();
	}
	
	int Fire::getType() const {
		return FIRE;
	}
	
	void Fire::update(EChunk& inside_chunk, int x, int y) {
		
		int upIndex = inside_chunk.getTileDataAt(y-gameConfig.global_gravity , x);
		
		int rightIndex = inside_chunk.getTileDataAt(y , x+1);
		int leftIndex = inside_chunk.getTileDataAt(y , x-1);
		
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
		
		//BURN
		if(rand()%gameConfig.fire_spread_rate==0){
			if (belowIndex == OIL||belowIndex == WOOD||belowIndex == PLANT||belowIndex == LEAVES||belowIndex == COAL) {
				inside_chunk.setTileAt(y+gameConfig.global_gravity,x,std::make_shared<Fire>());
				inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
			}
			if (upIndex == OIL||upIndex == WOOD||upIndex == PLANT||upIndex == LEAVES||upIndex == COAL) {
				inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Fire>());
				inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
			}
			if (rightIndex == OIL||rightIndex == WOOD||rightIndex == PLANT||rightIndex == LEAVES||rightIndex == COAL) {
				inside_chunk.setTileAt(y,x+1,std::make_shared<Fire>());
				inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
			}
			if (leftIndex == OIL||leftIndex == WOOD||leftIndex == PLANT||leftIndex == LEAVES||leftIndex == COAL) {
				inside_chunk.setTileAt(y,x-1,std::make_shared<Fire>());
				inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
			}
			if(rand()%12==0){
				if(rand()%2==0){
					inside_chunk.setTileAt(y,x,std::make_shared<Smoke>());
				} else{
					inside_chunk.setTileAt(y,x,std::make_shared<Ash>());
				}
			} else {
				inside_chunk.setTileAt(y,x,std::make_shared<Fire>()); //Burn anim TODO, make this method of inheritance
			}
			
		} else if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		} else if (leftBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		} else if ( rightBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		} else if (belowIndex == WATER) {
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
		} else if (upIndex == WATER) {
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
		} else if (rightIndex == WATER) {
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
		} else if (leftIndex == WATER) {
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
		}
	}
	
}