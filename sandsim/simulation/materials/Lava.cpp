#include "Lava.hpp"

namespace sandsim{
	Lava::Lava(): Tile(LAVA, ColorMap[LAVA]) {
		shadingSize=12;
		Lava::set_shading();
	}
	
	int Lava::getType() const {
		return LAVA;
	}
	
	void Lava::update(EChunk& inside_chunk, int x, int y) {
		
		int rightIndex = inside_chunk.getTileDataAt(y , x+1);
		int leftIndex = inside_chunk.getTileDataAt(y , x-1);
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
			return;
		} else if(belowIndex == WATER){
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
			inside_chunk.setTileAt(y+gameConfig.global_gravity,x,std::make_shared<Rock>());
		} else if (leftBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
			return;
		} else if (rightBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
			return;
		}
		//Right
		if(rightIndex == AIR){
			inside_chunk.swapTiles(y, x, y, x + 1);
			return;
		} else if(rightIndex == WATER){
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
			inside_chunk.setTileAt(y,x+1,std::make_shared<Rock>());
		}
		//Left
		if(leftIndex == AIR){
			inside_chunk.swapTiles(y, x, y, x - 1);
			return;
		} else if(leftIndex == WATER){
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
			inside_chunk.setTileAt(y,x-1,std::make_shared<Rock>());
		}
	
		if(inside_chunk.getTileDataAt((y - gameConfig.global_gravity), x)==WATER){
			inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
			inside_chunk.setTileAt(y-gameConfig.global_gravity,x,std::make_shared<Rock>());
		}
	}
}