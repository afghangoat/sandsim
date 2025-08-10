#ifndef SAND_HPP
#define SAND_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

namespace sandsim{
	class Sand: public Tile {
		public:
			Sand();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif