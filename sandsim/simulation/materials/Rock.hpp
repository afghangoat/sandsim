#ifndef ROCK_HPP
#define ROCK_HPP

#include "../TileUtils.hpp"

namespace sandsim{
	class Rock: public Tile {
		public:
			Rock();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif