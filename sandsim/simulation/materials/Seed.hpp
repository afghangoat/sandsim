#ifndef SEED_HPP
#define SEED_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"
#include "Air.hpp"
#include "Plant.hpp"

namespace sandsim{
	class Seed: public Tile {
		public:
			Seed();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif