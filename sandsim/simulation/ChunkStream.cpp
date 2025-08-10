#include "ChunkStream.hpp"

namespace sandsim{
	
	ChunkStream::ChunkStream(){
		
	}
	
	void ChunkStream::saveChunk(EChunk* chunk,std::string filename){
		std::ofstream chunksave(filename+".dat");
		
		std::string offset_config=std::to_string(chunk->getOffsetX())+" "+std::to_string(chunk->getOffsetY())+'\n';
		chunksave << offset_config;
		for(int y=0;y<gameConfig.CHUNK_SIZE;y++){
			std::string t_line="";
			for(int x=0;x<gameConfig.CHUNK_SIZE;x++){
				t_line+=std::to_string(chunk->getTileData(y,x))+" ";
			}
			t_line+="\n";
			chunksave << t_line;
		}
		
		chunksave.close();
	}
	
	void ChunkStream::loadChunk(EChunk* temp_chunk,std::string filename){
		std::string temp_line;

		std::ifstream chunkload(filename+".dat");
		
		int cur_line=0;

		while (getline (chunkload, temp_line)&&cur_line!=gameConfig.CHUNK_SIZE+1) {
			if(cur_line==0){
				int offx;
				int offy;

				std::istringstream parser_offsets(temp_line);
				parser_offsets >> offx >> offy;

				if (parser_offsets) {
					temp_chunk->setOffset(offx,offy);
				} else {
					std::cerr << "Error reading in region file!" << std::endl;
				}
			} else {
				std::istringstream parser_values(temp_line);
				std::vector<int> numbers;
				int value;

				int r_col=0;
				while (parser_values >> value) {
					
					temp_chunk->setTile(cur_line-1,r_col,MaterialRegistry::createMaterialFromId(value));
					r_col++;
				}
			}
			
			cur_line++;
		}

		chunkload.close();
	}
	
	ChunkStream::~ChunkStream(){
		
	}
}