#ifndef CED_HPP
#define CED_HPP

#include <memory>
#include "../core/Renderer.hpp"

namespace sandsim{
	
	class Tile;
	
	class EChunk{
		private:
		
			int offset_x;
			int offset_y;
			std::vector<std::shared_ptr<Tile>> chunk_data;
			
			int chunkUpdateCycle;
			
			EChunk* chunkAbove;
			EChunk* chunkRightAbove;
			EChunk* chunkLeftAbove;
			EChunk* chunkBelow;
			EChunk* chunkRightBelow;
			EChunk* chunkLeftBelow;
			EChunk* chunkRight;
			EChunk* chunkLeft;
			
			int getTileDataAtIndex(int idx) const;
			
		public:
		
			EChunk(int cX, int cY);
			
			EChunk(const EChunk& copient);
			
			~EChunk();
			
			int getOffsetX() const;
			int getOffsetY() const;
			
			void setOffset(int cX,int cY);
			
			void setChunkRelative(EChunk* relChunk,int relx,int rely);
			
			EChunk* getChunkRelative(int row,int col);

			Tile& getTile(int row, int col);
			
			int getTileData(int row, int col) const;
			
			int getTileDataAt(int row, int col) const;
			
			int getTileDataAt(int a) const;
			
			void updateTile(int y, int x);
				
			void setTile(int row, int col, std::shared_ptr<Tile> tile,bool doUpdateCycle=false);
			
			void setCycleAt(int row, int col, int newcycle);
			
			void setTileAt(int row, int col, std::shared_ptr<Tile> tile);
			
			void generateChunk();
			
			void swapTiles(int y1, int x1, int y2, int x2);
			
			void updateChunk();
			
			void drawChunk(Renderer& renderer);
			
			void checkDuplicates();
			
			void testFor(int material);
			
			void checkSame(int y1,int x1,int y2,int x2);
	};
}
#endif