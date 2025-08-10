#ifndef ACID_HPP
#define ACID_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"
#include "Steam.hpp"
#include "Air.hpp"

namespace sandsim{
	class Acid: public Tile {
		public:
			Acid();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif