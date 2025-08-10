#ifndef SMOKE_HPP
#define SMOKE_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

namespace sandsim{
	class Smoke: public Tile {
		public:
			Smoke();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif