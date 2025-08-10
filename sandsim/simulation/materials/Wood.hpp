#ifndef WOOD_HPP
#define WOOD_HPP

#include "../TileUtils.hpp"

namespace sandsim{
	class Wood: public Tile {
		public:
			Wood();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif