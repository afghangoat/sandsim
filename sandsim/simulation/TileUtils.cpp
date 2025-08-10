#include "TileUtils.hpp"

namespace sandsim{
	sf::Color ColorMap[TILE_COUNT] = {
		sf::Color(0,0,0), //AIR
		sf::Color(255,255,153), //SAND
		sf::Color(102,153,255), //WATER
		sf::Color(110,110,110), //ROCK
		sf::Color(230,230,230), //STEAM
		sf::Color(255,60,30), //LAVA
		sf::Color(204,51,153), //ACID
		sf::Color(170,170,170), //GRAVEL
		sf::Color(204,102,0), //COPPER
		sf::Color(82,82,38), //OIL
		sf::Color(255,110,21), //FIRE
		sf::Color(60,60,60), //SMOKE
		sf::Color(153,76,0), //WOOD
		sf::Color(255,255,153), //GLUE
		sf::Color(113,46,10), //DIRT
		sf::Color(255,153,153), //SEED
		sf::Color(102,153,0), //PLANT
		sf::Color(102,255,255), //PETAL
		sf::Color(100,215,50), //ALGAE
		sf::Color(153, 204, 0), //BAMBOO
		sf::Color(0,51,0), //SAPLING
		sf::Color(0,153,51), //LEAVES
		sf::Color(20,20,20), //COAL
		sf::Color(190,140,140), //ASH
		sf::Color(204,0,0) //THERMITE
	};
	
	Tile::Tile(int base_type, sf::Color base_color): type(base_type), color(base_color) {
		updateCycle=0;
	}
	/*Tile(const Tile& other) : type(other.type), color(other.color), updateCycle(other.updateCycle) {
		
	}*/
	// Constructor to handle shared_ptr<Tile>
	/*Tile(const std::shared_ptr<Tile>& other) : type(other->type), updateCycle(other->updateCycle) { //color(other->color)
		setType(other->type);
	}*/
	
	Tile::~Tile() = default;

	//virtual void update(Chunk& chunk, int y, int x) = 0;
	
	int Tile::getCycle() const {
		return updateCycle;
	}
	void Tile::setCycle(int newCycle){
		updateCycle=newCycle;
	}
	void Tile::processCycle(){
		updateCycle++;
	}
	void Tile::setColor(sf::Color new_color){
		color=new_color;
	}
	sf::Color Tile::getColor() const {
		return color;
	}
	void Tile::set_shading(){
		int rVariation = (rand() % (shadingSize * 2 + 1)) - shadingSize;

		color.r = std::clamp(color.r + rVariation, 0, 255);
		color.g = std::clamp(color.g + rVariation, 0, 255);
		color.b = std::clamp(color.b + rVariation, 0, 255);
	}
	
	int Tile::getType() const {
		return type;
	}
	
	void Tile::update(EChunk& inside_chunk, int x, int y) [[maybe_unused]] {
		(void)inside_chunk;
		(void)x;
		(void)y;
	}
}