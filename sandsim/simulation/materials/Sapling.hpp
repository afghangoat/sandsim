#ifndef SAPLING_HPP
#define SAPLING_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

#include "Wood.hpp"
#include "Leaves.hpp"

namespace sandsim{
	class Sapling: public Tile {
		public:
			Sapling();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif