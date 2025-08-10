#ifndef GRAVEL_HPP
#define GRAVEL_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

namespace sandsim{
	class Gravel: public Tile {
		public:
			Gravel();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif