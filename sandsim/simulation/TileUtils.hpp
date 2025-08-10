#ifndef TILE_UTILS_HPP
#define TILE_UTILS_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "Extended_C_Def.hpp"

namespace sandsim{
	enum TileTypes {
		NONE=-1,
		AIR=0,
		SAND=1,
		WATER=2,
		ROCK=3,
		STEAM=4,
		LAVA=5,
		ACID=6,
		GRAVEL=7,
		COPPER=8,
		OIL=9,
		FIRE=10,
		SMOKE=11,
		WOOD=12,
		GLUE=13,
		DIRT=14,
		SEED=15,
		PLANT=16,
		PETAL=17,
		ALGAE=18,
		BAMBOO=19,
		SAPLING=20,
		LEAVES=21,
		COAL=22,
		ASH=23,
		THERMITE=24,
		
		TILE_COUNT
		
	};
	
	extern sf::Color ColorMap[TILE_COUNT];
	
	
		
	class Tile{
		protected:
			int type;
			sf::Color color;
			int updateCycle;
			int shadingSize;
			
		public:
			
			explicit Tile(int base_type, sf::Color base_color=sf::Color(0,0,0));
			/*Tile(const Tile& other) : type(other.type), color(other.color), updateCycle(other.updateCycle) {
				
			}*/
			// Constructor to handle shared_ptr<Tile>
			/*Tile(const std::shared_ptr<Tile>& other) : type(other->type), updateCycle(other->updateCycle) { //color(other->color)
				setType(other->type);
			}*/
			
			virtual ~Tile();
			
			int getCycle() const;
			
			void setCycle(int newCycle);
			
			void processCycle();
			
			void setColor(sf::Color new_color);
			
			sf::Color getColor() const;
			void set_shading();
			
			virtual int getType() const;
			
			virtual void update(EChunk& inside_chunk, int x, int y);
	};
}

#endif