#include "Tnt.hpp"

namespace sandsim{
	Thremite::Thremite(): Tile(THERMITE, ColorMap[THERMITE]) {
		shadingSize=17;
		Thremite::set_shading();
	}
	
	int Thremite::getType() const {
		return THERMITE;
	}
	
	void Thremite::update(EChunk& inside_chunk, int x, int y) {
		int upIndex = inside_chunk.getTileDataAt(y-gameConfig.global_gravity , x);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
		int leftIndex = inside_chunk.getTileDataAt(y , x - 1);
		int rightIndex = inside_chunk.getTileDataAt(y , x + 1);
		
		if(belowIndex==FIRE||upIndex==FIRE||leftIndex==FIRE||rightIndex==FIRE){
			//std::cout << "debug";
			for(int ax=x-gameConfig.explosion_radius;ax<x+gameConfig.explosion_radius;ax++){
				for(int ay=y-gameConfig.explosion_radius;ay<y+gameConfig.explosion_radius;ay++){
					if(abs(ax-x)+abs(ay-y)<gameConfig.explosion_radius){
						if(rand()%2==0){
							inside_chunk.setTileAt(ay,ax,std::make_shared<Air>());
						} else {
							inside_chunk.setTileAt(ay,ax,std::make_shared<Smoke>());
						}
					}
				}
			}
		}
		else if (belowIndex == AIR || belowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		}
		
		else if (leftBelowIndex == AIR || leftBelowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		}
		
		else if ( rightBelowIndex == AIR || rightBelowIndex == WATER) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		}
	}
}