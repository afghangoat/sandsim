#include "Acid.hpp"

namespace sandsim{
	Acid::Acid(): Tile(ACID, ColorMap[ACID]) {
		shadingSize=20;
		Acid::set_shading();
	}
	
	int Acid::getType() const {
		return ACID;
	}
	
	void Acid::update(EChunk& inside_chunk, int x, int y) {
		
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);	
		} else if(belowIndex != ACID&&rand()%8==0){
			inside_chunk.setTileAt(y+gameConfig.global_gravity,x,std::make_shared<Air>());
			if(rand()%9==0){
				inside_chunk.setTileAt(y,x,std::make_shared<Steam>());
			}
		} else if (leftBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
		} else if (rightBelowIndex == AIR) {
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
		}
	}
}