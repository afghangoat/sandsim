#ifndef SIM_CONF_HPP
#define SIM_CONF_HPP

namespace sandsim{
	
	struct GameConfig {
		
        int explosion_radius;
        int fire_spread_rate;
		
        int plant_growth_rate;
        int plant_petal_rate; //The less is the more are the petals
		
        int global_gravity;
		
        int CHUNK_SIZE;
		int BRUSH_SIZE;
		
		int UPDATE_FRAMES;
		
		int gravity_modifier;

		void calcGravityModifier();
		
        GameConfig(int exp_rad, int fire_spread, int p_growth, int petal_growth, int new_grav, int chunk_s, int brush_s, int u_frames):
		explosion_radius(exp_rad),
		fire_spread_rate(fire_spread),
		plant_growth_rate(p_growth),
		plant_petal_rate(petal_growth),
		global_gravity(new_grav),
		CHUNK_SIZE(chunk_s),
		BRUSH_SIZE(brush_s),
		UPDATE_FRAMES(u_frames){
			calcGravityModifier();
		}
		
    };
	
	extern GameConfig gameConfig;
}
#endif