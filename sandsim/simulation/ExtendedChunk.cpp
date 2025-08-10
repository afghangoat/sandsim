#include "ExtendedChunk.hpp"

namespace sandsim{
	
	EChunk::EChunk(int cX, int cY){
		offset_x=cX*gameConfig.CHUNK_SIZE*VERT_SIZE;
		offset_y=cY*gameConfig.CHUNK_SIZE*VERT_SIZE;
		chunkUpdateCycle=0;
		//Tile& tile = matrix[row * gameConfig.CHUNK_SIZE + col];
		chunk_data.resize(gameConfig.CHUNK_SIZE * gameConfig.CHUNK_SIZE);
		for (int y = 0; y < gameConfig.CHUNK_SIZE; ++y) {
			for (int x = 0; x < gameConfig.CHUNK_SIZE; ++x) {
				chunk_data[y * gameConfig.CHUNK_SIZE + x] = std::make_shared<Air>();
			}
		}
		
		chunkAbove=nullptr;
		chunkRightAbove=nullptr;
		chunkLeftAbove=nullptr;
		chunkBelow=nullptr;
		chunkRightBelow=nullptr;
		chunkLeftBelow=nullptr;
		chunkRight=nullptr;
		chunkLeft=nullptr;
		
		//Adjustable action
		EChunk::generateChunk();
	}
	
	EChunk::EChunk(const EChunk& copient): offset_x(copient.offset_x), 
		offset_y(copient.offset_y),
		chunk_data(copient.chunk_data), 
		chunkUpdateCycle(copient.chunkUpdateCycle),
		chunkAbove(copient.chunkAbove ? new EChunk(*copient.chunkAbove) : nullptr),
		chunkRightAbove(copient.chunkRightAbove ? new EChunk(*copient.chunkRightAbove) : nullptr),
		chunkLeftAbove(copient.chunkLeftAbove ? new EChunk(*copient.chunkLeftAbove) : nullptr),
		chunkBelow(copient.chunkBelow ? new EChunk(*copient.chunkBelow) : nullptr),
		chunkRightBelow(copient.chunkRightBelow ? new EChunk(*copient.chunkRightBelow) : nullptr),
		chunkLeftBelow(copient.chunkLeftBelow ? new EChunk(*copient.chunkLeftBelow) : nullptr),
		chunkRight(copient.chunkRight ? new EChunk(*copient.chunkRight) : nullptr),
		chunkLeft(copient.chunkLeft ? new EChunk(*copient.chunkLeft) : nullptr) {
		// :(
	}
	
	EChunk::~EChunk() {
		//delete[] chunk_data;

		chunkAbove = nullptr;

		chunkRightAbove = nullptr;
		
		chunkLeftAbove = nullptr;
		
		chunkBelow = nullptr;
		
		chunkRightBelow = nullptr;
		
		chunkLeftBelow = nullptr;
		
		chunkRight = nullptr;
		
		chunkLeft = nullptr;
	}
	
	int EChunk::getOffsetX() const {
		return offset_x;
	}
	int EChunk::getOffsetY() const {
		return offset_y;
	}
	
	void EChunk::setOffset(int cX,int cY){
		offset_x=cX;
		offset_y=cY;
	}
	
	void EChunk::setChunkRelative(EChunk* relChunk,int relx,int rely) {
		switch(rely){
			case -1:
				if(relx==1){
					chunkRightAbove = relChunk;
				} else if(relx==-1){
					chunkLeftAbove = relChunk;
				} else {
					chunkAbove = relChunk;
				}
				break;
			case 0:
				if(relx==1){
					chunkRight = relChunk;
				} else if(relx==-1){
					chunkLeft = relChunk;
				}
				break;
			case 1:
				if(relx==1){
					chunkRightBelow = relChunk;
				} else if(relx==-1){
					chunkLeftBelow = relChunk;
				} else {
					chunkBelow = relChunk;
				}
				break;
		}
	}
	EChunk* EChunk::getChunkRelative(int row,int col){
		//Get chunk ref
		if(row<0){ //Left
			if(col<0&&chunkLeftAbove!=nullptr){
				return chunkLeftAbove;
			}
			if(col>=gameConfig.CHUNK_SIZE&&chunkLeftBelow!=nullptr){
				return chunkLeftBelow;
			}
			if(chunkLeft!=nullptr){
				return chunkLeft;
			}
			
		}
		if(row>gameConfig.CHUNK_SIZE-2&&chunkRightAbove!=nullptr){ //Right
			if(col<0){
				return chunkRightAbove;
			}
			if(col>=gameConfig.CHUNK_SIZE&&chunkRightBelow!=nullptr){
				return chunkRightBelow;
			}
			if(chunkRight!=nullptr){
				return chunkRight;
			}
		}
		if(col<0&&chunkAbove!=nullptr){
			return chunkAbove;
		} else if(col>=gameConfig.CHUNK_SIZE&&chunkBelow!=nullptr){
			return chunkBelow;
		}
		return this;
		
	}

	Tile& EChunk::getTile(int row, int col) {
		return *chunk_data[row * gameConfig.CHUNK_SIZE + col];
	}

	int EChunk::getTileData(int row, int col) const {
		return chunk_data[row * gameConfig.CHUNK_SIZE + col]->getType();
	}
	
	int EChunk::getTileDataAtIndex(int idx) const{
		int row = idx / gameConfig.CHUNK_SIZE;
		int col = idx % gameConfig.CHUNK_SIZE;
		
		//Get tile data
		if(row<1-gameConfig.global_gravity){ //Left
			if(col<0){
				if(chunkLeftAbove==nullptr){
					return NONE;
				} else {
					return chunkLeftAbove->chunk_data[(gameConfig.CHUNK_SIZE-1) * gameConfig.CHUNK_SIZE + col+gameConfig.CHUNK_SIZE]->getType();
				}
			} else if(col>=gameConfig.CHUNK_SIZE){
				if(chunkLeftBelow==nullptr){
					return NONE;
				} else {
					return chunkLeftBelow->chunk_data[(gameConfig.CHUNK_SIZE-1) * gameConfig.CHUNK_SIZE + col-gameConfig.CHUNK_SIZE]->getType();
				}
			} else if(chunkLeft!=nullptr){
				return chunkLeft->chunk_data[(gameConfig.CHUNK_SIZE-1) * gameConfig.CHUNK_SIZE + col]->getType();
			} else {
				return NONE;
			}
		} else if(row>gameConfig.CHUNK_SIZE-2){ //Right
			if(col<0){
				if(chunkRightAbove==nullptr){
					return NONE;
				} else {
					return chunkRightAbove->chunk_data[(row-gameConfig.CHUNK_SIZE) * gameConfig.CHUNK_SIZE + col+gameConfig.CHUNK_SIZE]->getType();
				}
			} else if(col>=gameConfig.CHUNK_SIZE){
				if(chunkRightBelow==nullptr){
					return NONE;
				} else {
					return chunkRightBelow->chunk_data[(row-gameConfig.CHUNK_SIZE) * gameConfig.CHUNK_SIZE + col-gameConfig.CHUNK_SIZE]->getType();
				}
			} else if(chunkRight!=nullptr){
				return chunkRight->chunk_data[(row-gameConfig.CHUNK_SIZE) * gameConfig.CHUNK_SIZE + col]->getType();
			} else {
				return NONE;
			}
		} else {
			if(col<0){
				if(chunkAbove==nullptr){
					return NONE;
				} else {
					return chunkAbove->chunk_data[row * gameConfig.CHUNK_SIZE + col+gameConfig.CHUNK_SIZE]->getType();
				}
			} else if(col>=gameConfig.CHUNK_SIZE){
				if(chunkBelow==nullptr){
					return NONE;
				} else {
					return chunkBelow->chunk_data[row * gameConfig.CHUNK_SIZE + col-gameConfig.CHUNK_SIZE]->getType();
				}
			} else {
				return chunk_data[row * gameConfig.CHUNK_SIZE + col]->getType();
			}
		}
		return NONE;
	}
	
	int EChunk::getTileDataAt(int row, int col) const {
		
		return getTileDataAtIndex(row * gameConfig.CHUNK_SIZE + col);
	}
	
	int EChunk::getTileDataAt(int a) const {
		
		return getTileDataAtIndex(a);
	}
	
	void EChunk::setTile(int row, int col, std::shared_ptr<Tile> tile,bool doUpdateCycle){
		
		int oc=chunk_data[row * gameConfig.CHUNK_SIZE + col]->getCycle();
		chunk_data[row * gameConfig.CHUNK_SIZE + col]=tile;
		if (doUpdateCycle==true){
			chunk_data[row * gameConfig.CHUNK_SIZE + col]->setCycle(chunkUpdateCycle);
		} else {
			chunk_data[row * gameConfig.CHUNK_SIZE + col]->setCycle(oc);
		}
		
	}
	
	void EChunk::setCycleAt(int row, int col, int newcycle){
		if(row<1-gameConfig.global_gravity){ //Left
			if(col<0&&chunkLeftAbove!=nullptr){
				chunkLeftAbove->chunk_data[(gameConfig.CHUNK_SIZE-1) * gameConfig.CHUNK_SIZE + col+gameConfig.CHUNK_SIZE]->setCycle(newcycle);
			} else if(col>=gameConfig.CHUNK_SIZE&&chunkLeftBelow!=nullptr){
				chunkLeftBelow->chunk_data[(gameConfig.CHUNK_SIZE-1) * gameConfig.CHUNK_SIZE + col-gameConfig.CHUNK_SIZE]->setCycle(newcycle);
			} else if(chunkLeft!=nullptr){
				chunkLeft->chunk_data[(gameConfig.CHUNK_SIZE-1) * gameConfig.CHUNK_SIZE + col]->setCycle(newcycle);
			}
		} else if(row>gameConfig.CHUNK_SIZE-2){ //Right
			if(col<0&&chunkRightAbove!=nullptr){
				chunkRightAbove->chunk_data[(row-gameConfig.CHUNK_SIZE) * gameConfig.CHUNK_SIZE + col+gameConfig.CHUNK_SIZE]->setCycle(newcycle);
			} else if(col>=gameConfig.CHUNK_SIZE&&chunkRightBelow!=nullptr){
				chunkRightBelow->chunk_data[(row-gameConfig.CHUNK_SIZE) * gameConfig.CHUNK_SIZE + col-gameConfig.CHUNK_SIZE]->setCycle(newcycle);
			} else if(chunkRight!=nullptr){
				chunkRight->chunk_data[(row-gameConfig.CHUNK_SIZE) * gameConfig.CHUNK_SIZE + col]->setCycle(newcycle);
			}
		} else {
			if(col<0&&chunkAbove!=nullptr){
				chunkAbove->chunk_data[row * gameConfig.CHUNK_SIZE + col+gameConfig.CHUNK_SIZE]->setCycle(newcycle);
			} else if(col>=gameConfig.CHUNK_SIZE&&chunkBelow!=nullptr){
				chunkBelow->chunk_data[row * gameConfig.CHUNK_SIZE + col-gameConfig.CHUNK_SIZE]->setCycle(newcycle);
			} else {
				chunk_data[row * gameConfig.CHUNK_SIZE + col]->setCycle(newcycle);
			}
		}
	}
	
	void EChunk::setTileAt(int row, int col, std::shared_ptr<Tile> tile){
		if(row<1-gameConfig.global_gravity){ //Left
			if(col<0&&chunkLeftAbove!=nullptr){
				chunkLeftAbove->setTile(row+gameConfig.CHUNK_SIZE,col+gameConfig.CHUNK_SIZE,tile);
			} else if(col>=gameConfig.CHUNK_SIZE&&chunkLeftBelow!=nullptr){
				chunkLeftBelow->setTile(row+gameConfig.CHUNK_SIZE,col-gameConfig.CHUNK_SIZE,tile);
			} else if(chunkLeft!=nullptr){
				chunkLeft->setTile(row+gameConfig.CHUNK_SIZE,col,tile);
			}
		} else if(row>gameConfig.CHUNK_SIZE-2){ //Right
			if(col<0&&chunkRightAbove!=nullptr){
				chunkRightAbove->setTile(row-gameConfig.CHUNK_SIZE,col+gameConfig.CHUNK_SIZE,tile);
			} else if(col>=gameConfig.CHUNK_SIZE&&chunkRightBelow!=nullptr){
				chunkRightBelow->setTile(row-gameConfig.CHUNK_SIZE,col-gameConfig.CHUNK_SIZE,tile);
			} else if(chunkRight!=nullptr){
				chunkRight->setTile(row-gameConfig.CHUNK_SIZE,col,tile);
			}
		} else {
			if(col<0&&chunkAbove!=nullptr){
				chunkAbove->setTile(row,col+gameConfig.CHUNK_SIZE,tile);
			} else if(col>=gameConfig.CHUNK_SIZE&&chunkBelow!=nullptr){
				chunkBelow->setTile(row,col-gameConfig.CHUNK_SIZE,tile);
			} else {
				EChunk::setTile(row,col,tile);
			}
		}
	}
	
	void EChunk::generateChunk(){
		
		for(int x=0;x<gameConfig.CHUNK_SIZE;++x){
			for(int y=0;y<gameConfig.CHUNK_SIZE;++y){
				if(y==gameConfig.CHUNK_SIZE-1){
					EChunk::setTile(y,x,std::make_shared<Rock>());
				} else {
					if((rand() % 4) == SAND){
						EChunk::setTile(y,x,std::make_shared<Sand>());
					}
					if((rand() % 5) == WATER){
						EChunk::setTile(y,x,std::make_shared<Water>());
					}
				}
			}
		}
	}
	
	void EChunk::swapTiles(int y1, int x1, int y2, int x2){
		//Get which chunk is needed
		int tdata2=EChunk::getTileDataAt(y2,x2);
		if(tdata2==NONE||y1<0||x1<0||x1>gameConfig.CHUNK_SIZE||y1>gameConfig.CHUNK_SIZE){
			return;
		}
		EChunk* ch2 = EChunk::getChunkRelative(y2,x2);
		if(ch2==nullptr){
			return;
		}
		
		//int temp_type=chunk_data[y1*gameConfig.CHUNK_SIZE+x1].getType();
		int temp_updateCycle=chunk_data[y1*gameConfig.CHUNK_SIZE+x1]->getCycle();
		
		//std::cout << chunk_data[y1*gameConfig.CHUNK_SIZE+x1]->getType() << std::endl;
		std::swap(chunk_data[y1*gameConfig.CHUNK_SIZE+x1], ch2->chunk_data[y2*gameConfig.CHUNK_SIZE+x2]);
		
		//setTileAt(y1,x1,getTileDataAt(y2,x2));
		//setTileAt(y2,x2,temp_type);
		
		
		//chunk_data[y1*gameConfig.CHUNK_SIZE+x1].setType(chunk_data[y2*gameConfig.CHUNK_SIZE+x2].getType());
		//chunk_data[y2*gameConfig.CHUNK_SIZE+x2].setType(temp_type);
		
		/*auto tile1 = chunk_data[y1 * gameConfig.CHUNK_SIZE + x1];
		auto tile2 = ch2->chunk_data[y2 * gameConfig.CHUNK_SIZE + x2];
		
		ch2->chunk_data[y2 * gameConfig.CHUNK_SIZE + x2]=tile1;
		chunk_data[y1 * gameConfig.CHUNK_SIZE + x1]=tile2;*/

		// Manually swap their values (this avoids std::swap)
		//!auto temp_tile = std::make_shared<Tile>(*tile1); // Create a copy of tile1
		//!*tile1 = *tile2;                                // Overwrite tile1 with tile2's data
		//!*tile2 = *temp_tile;                            // Overwrite tile2 with the temp copy of tile1
		
		//std::cout << "Swapped: (" << x1 << ", " << y1 << ") with (" << x2 << ", " << y2 << ")\n";
		//std::cout << "Tile1: " << tile1->getType() << ", Cycle: " << tile1->getCycle() << "\n";
		//std::cout << "Tile2: " << tile2->getType() << ", Cycle: " << tile2->getCycle() << "\n";
		
		EChunk::setCycleAt(y1,x1,temp_updateCycle); //If fail, then x2,y2
	}
	
	void EChunk::updateTile(int y, int x){ //y,x
		chunk_data[y*gameConfig.CHUNK_SIZE+x]->processCycle();
		chunk_data[y*gameConfig.CHUNK_SIZE+x]->update(*this, x, y);
	}
	
	void EChunk::updateChunk(){
		for(int x=0;x<gameConfig.CHUNK_SIZE;++x){
			
			for(int y=0;y<gameConfig.CHUNK_SIZE;++y){
				if(chunk_data[y*gameConfig.CHUNK_SIZE+x]->getCycle()==chunkUpdateCycle){
					EChunk::updateTile(y,x);
				}
			}
		}
		chunkUpdateCycle++;
	}
	
	void EChunk::drawChunk(Renderer& renderer){ //, const sf::View& view
		sf::VertexArray walls(sf::Quads);
		
		walls.clear();
		walls.resize(gameConfig.CHUNK_SIZE * gameConfig.CHUNK_SIZE * 4);
		
		/*sf::FloatRect viewBounds(
			view.getCenter() - view.getSize() / 2.f,
			view.getSize()
		);*/
	
		for(int x=0;x<gameConfig.CHUNK_SIZE;++x){
			/*loat xPos = x * VERT_SIZE;

			// Skip columns outside the view bounds
			if (xPos + VERT_SIZE < viewBounds.left || xPos > viewBounds.left + viewBounds.width) {
				continue;
			}*/

			for(int y=0;y<gameConfig.CHUNK_SIZE;++y){
				/*float yPos = y * VERT_SIZE;

				// Skip rows outside the view bounds
				if (yPos + VERT_SIZE < viewBounds.top || yPos > viewBounds.top + viewBounds.height) {
					continue;
				}*/
				if(chunk_data[y*gameConfig.CHUNK_SIZE+x]->getType()!=AIR){
					//if(chunk_data[y*gameConfig.CHUNK_SIZE+x]->getType()==SAND){
					//	std::cout << chunk_data[y*gameConfig.CHUNK_SIZE+x]->getType() << " " << x << " " << y << std::endl;
					//}
					
					
					sf::Color tclr=chunk_data[y*gameConfig.CHUNK_SIZE+x]->getColor();
					sf::Vector2f topLeft(offset_x+x * VERT_SIZE, offset_y+ y*VERT_SIZE);
					sf::Vector2f topRight(offset_x+x * VERT_SIZE + VERT_SIZE,offset_y+ y*VERT_SIZE);
					sf::Vector2f bottomLeft(offset_x+x * VERT_SIZE,offset_y+ y*VERT_SIZE+VERT_SIZE);
					sf::Vector2f bottomRight(offset_x+x * VERT_SIZE + VERT_SIZE,offset_y+ y*VERT_SIZE+VERT_SIZE);

					walls.append(sf::Vertex(topLeft, tclr));
					walls.append(sf::Vertex(topRight, tclr));
					walls.append(sf::Vertex(bottomRight, tclr));
					walls.append(sf::Vertex(bottomLeft, tclr));
					
				}
				
			}
		}
		
		renderer.window.draw(walls);
	}
	
	void EChunk::checkDuplicates(){
		for (size_t i = 0; i < chunk_data.size(); ++i) {
			for (size_t j = i + 1; j < chunk_data.size(); ++j) {
				if (chunk_data[i] == chunk_data[j]) {
					
					int row1 = i / gameConfig.CHUNK_SIZE;
					int col1 = i % gameConfig.CHUNK_SIZE;
					
					int row2 = j / gameConfig.CHUNK_SIZE;
					int col2 = j % gameConfig.CHUNK_SIZE;
					
					std::cout << "Duplicate Tile objects detected at: X1: " << col1 << " Y1: "<<row1 << " X2: " << col2 << " Y2: " << row2 << " (Type: "<< chunk_data[i]->getType() << ")" << std::endl;
					return;
				}
			}
		}
	}
	
	void EChunk::testFor(int material){
		for(int x=0;x<gameConfig.CHUNK_SIZE;++x){
			for(int y=0;y<gameConfig.CHUNK_SIZE;++y){
				if(chunk_data[y*gameConfig.CHUNK_SIZE+x]->getType()==material){
					std::cout << "Found " << material << " at X: " << x << " Y: " << y << std::endl;
				}
			}
		}
	}
	
	void EChunk::checkSame(int y1,int x1,int y2,int x2){
		if(chunk_data[y1*gameConfig.CHUNK_SIZE+x1]==chunk_data[y2*gameConfig.CHUNK_SIZE+x2]){
			std::cout << "Duplicate Tile objects detected at: X1: " << x1 << " Y1: "<<y1 << " X2: " << x2 << " Y2: " << y2 << " (Type: "<< chunk_data[y1*gameConfig.CHUNK_SIZE+x1]->getType() << ")" << std::endl;
		} else {
			std::cout << "No duplicate Tile objects detected at: X1: " << x1 << " Y1: "<<y1 << " X2: " << x2 << " Y2: " << y2 << std::endl;
		}
	}
}