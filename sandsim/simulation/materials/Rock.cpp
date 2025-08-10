#include "Rock.hpp"

namespace sandsim{
	Rock::Rock(): Tile(ROCK, ColorMap[ROCK]) {
		shadingSize=20;
		Rock::set_shading();
	}
	
	int Rock::getType() const {
		return ROCK;
	}
	
	void Rock::update(EChunk& inside_chunk, int x, int y) [[maybe_unused]] {
		(void)inside_chunk;
		(void)x;
		(void)y;
	}
}