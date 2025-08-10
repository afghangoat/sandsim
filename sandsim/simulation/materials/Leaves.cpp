#include "Leaves.hpp"

namespace sandsim{
	Leaves::Leaves(): Tile(LEAVES, ColorMap[LEAVES]) {
		shadingSize=20;
		Leaves::set_shading();
	}
	
	int Leaves::getType() const {
		return LEAVES;
	}
	
	void Leaves::update(EChunk& inside_chunk, int x, int y) [[maybe_unused]] {
		(void)inside_chunk;
		(void)x;
		(void)y;
	}
}