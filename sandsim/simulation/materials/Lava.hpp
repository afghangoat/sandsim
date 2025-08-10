#ifndef LAVA_HPP
#define LAVA_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

#include "Rock.hpp"
#include "Steam.hpp"

namespace sandsim{
	class Lava: public Tile {
		public:
			Lava();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif