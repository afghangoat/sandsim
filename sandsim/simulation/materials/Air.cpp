#include "Air.hpp"

namespace sandsim{
	Air::Air(): Tile(AIR, ColorMap[AIR]) {
		shadingSize=0;
		Air::set_shading();
	}
	
	int Air::getType() const {
		return AIR;
	}
	
	void Air::update(EChunk& inside_chunk, int x, int y) [[maybe_unused]] {
		(void)inside_chunk;
		(void)x;
		(void)y;
	}
}