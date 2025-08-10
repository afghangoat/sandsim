#ifndef AIR_HPP
#define AIR_HPP

#include "../TileUtils.hpp"

namespace sandsim{
	class Air: public Tile {
		public:
			Air();

			int getType() const override;
			
			void update(EChunk& inside_chunk, int x, int y) override;
	};
}

#endif