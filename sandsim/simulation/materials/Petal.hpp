#ifndef PETAL_HPP
#define PETAL_HPP

#include "../TileUtils.hpp"
#include "../SimulationConfig.hpp"

#include "Smoke.hpp"
#include "Air.hpp"

namespace sandsim{
	class Petal: public Tile {
		public:
			Petal();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif