#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SpriteEntityBase.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "../simulation/SimulationConfig.hpp"
#include "../simulation/TileUtils.hpp"

namespace alives {

    class Player: public SpriteEntity {
    private:
        sf::Vector2f velocity;
		
		int keys_down[4]; //WASD
		double speed;
        
    public:
		int palette_type;
		bool simulationRunning;
        Player(sf::Vector2f new_pos, sf::Vector2f new_size, int mhealth, double movement_speed);

        void update_self() override;
		
		bool colliding();
    };

}

#endif