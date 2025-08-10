#include "Wood.hpp"

namespace sandsim{
	Wood::Wood(): Tile(WOOD, ColorMap[WOOD]) {
		shadingSize=20;
		Wood::set_shading();
	}
	
	int Wood::getType() const {
		return WOOD;
	}
	
	void Wood::update(EChunk& inside_chunk, int x, int y) [[maybe_unused]] {
		(void)inside_chunk;
		(void)x;
		(void)y;
	}
}