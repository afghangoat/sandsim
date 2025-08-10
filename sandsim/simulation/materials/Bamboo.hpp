#ifndef BAMBOO_HPP
#define BAMBOO_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

namespace sandsim{
	class Bamboo: public Tile {
		public:
			Bamboo();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif