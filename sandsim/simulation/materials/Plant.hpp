#ifndef PLANT_HPP
#define PLANT_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"
#include "Petal.hpp"

namespace sandsim{
	class Plant: public Tile {
		public:
			Plant();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif