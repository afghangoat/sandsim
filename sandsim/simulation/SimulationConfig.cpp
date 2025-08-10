#include "SimulationConfig.hpp"

namespace sandsim{
	//GameConfig(int exp_rad, int fire_spread, int p_growth, int petal_growth, int new_grav, int chunk_s, int brush_s, int u_frames);
		/*
	#define UPDATE_FRAMES 2
	#define BRUSH_SIZE 3
	#define explosion_radius 4
	#define fire_spread_rate 3
	#define plant_growth_rate 16
	#define plant_petal_rate 3
	#define global_gravity 1
	#define CHUNK_SIZE 256
	*/
	void GameConfig::calcGravityModifier(){
		if(GameConfig::global_gravity==-1){
			GameConfig::gravity_modifier=1;
		} else {
			GameConfig::gravity_modifier=0;
		}
		
	}
	
	GameConfig gameConfig(
		4, //explosion_radius
		3, //fire_spread_rate
		16, //plant_growth_rate
		3, //plant_petal_rate
		1, //global_gravity DEF: 1
		256, //CHUNK_SIZE
		3, //BRUSH_SIZE
		2 //UPDATE_FRAMES
	);
}