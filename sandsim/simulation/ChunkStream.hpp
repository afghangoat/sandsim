#ifndef CHUNKSTREAM_HPP
#define CHUNKSTREAM_HPP

#include "ExtendedChunk.hpp"
#include "MaterialRegistry.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <cstdlib>

namespace sandsim{
	//load in chunks from txt file,
	//loader class,
	class ChunkStream{
		private:
			
		public:
			ChunkStream();
			
			void saveChunk(EChunk* chunk,std::string filename);
			
			void loadChunk(EChunk* temp_chunk,std::string filename);
			
			~ChunkStream();
	};
}

#endif