#ifndef COPPER_HPP
#define COPPER_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

namespace sandsim{
	class Copper: public Tile {
		public:
			Copper();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif