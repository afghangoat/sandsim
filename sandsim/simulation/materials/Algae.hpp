#ifndef ALGAE_HPP
#define ALGAE_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

namespace sandsim{
	class Algae: public Tile {
		public:
			Algae();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif