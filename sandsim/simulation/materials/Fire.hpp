#ifndef FIRE_HPP
#define FIRE_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

#include "Smoke.hpp"
#include "Steam.hpp"
#include "Ash.hpp"

namespace sandsim{
	class Fire: public Tile {
		public:
			Fire();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif