#include "Sand.hpp"

namespace sandsim{
	Sand::Sand(): Tile(SAND, ColorMap[SAND]) {
		shadingSize=20;
		Sand::set_shading();
	}
	
	int Sand::getType() const {
		return SAND;
	}
	
	void Sand::update(EChunk& inside_chunk, int x, int y) {
		int belowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x);
		int leftBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x - 1);
		int rightBelowIndex = inside_chunk.getTileDataAt(y + gameConfig.global_gravity , x + 1);
	
		if (belowIndex == AIR || belowIndex == WATER) {
			//std::cout << "wah 2" << std::endl;
			//std::cout << "Moving to... " << x << " " << y+1 << std::endl;
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x);
		}
		else if (leftBelowIndex == AIR || leftBelowIndex == WATER) {
			//std::cout << "wah" << std::endl;
			//std::cout << "Moving to... " << x-1 << " " << y+1 << std::endl;
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x - 1);
			//inside_chunk.setTileAt(y,x,std::make_shared<Air>());
			//inside_chunk.setTileAt(y+1,x-1,std::make_shared<Sand>());
		}
	
		else if ( rightBelowIndex == AIR || rightBelowIndex == WATER) {
			//std::cout << "wah" << std::endl;
			//std::cout << "Moving to... " << x+1 << " " << y+1 << std::endl;
			inside_chunk.swapTiles(y, x, y + gameConfig.global_gravity, x + 1);
			//inside_chunk.setTileAt(y,x,std::make_shared<Air>());
			//inside_chunk.setTileAt(y+1,x+1,std::make_shared<Sand>());
		}
	}
}