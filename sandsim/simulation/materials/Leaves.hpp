#ifndef LEAVES_HPP
#define LEAVES_HPP

#include "../TileUtils.hpp"

namespace sandsim{
	class Leaves: public Tile {
		public:
			Leaves();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif