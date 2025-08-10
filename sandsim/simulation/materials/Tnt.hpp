#ifndef TNT_HPP
#define TNT_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

#include "Smoke.hpp"
#include "Air.hpp"

namespace sandsim{
	class Thremite: public Tile {
		public:
			Thremite();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif