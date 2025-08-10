#include "Player.hpp"

namespace alives{
	
	/*Player::Player(sf::Vector2f new_pos, sf::Vector2f new_size,int mhealth): SpriteEntityBase(new_pos, new_size, mhealth) {
		//Stub
	}
	void Player::update_self(){
		
	}*/
	/*Player::Player(sf::Vector2f new_pos, sf::Vector2f new_size,int mhealth): Entity(new_pos, new_size, mhealth) {
		
	}

	bool Player::colliding() {
		return true;
	}*/
    Player::Player(sf::Vector2f new_pos, sf::Vector2f new_size, int mhealth, double movement_speed): SpriteEntity(new_pos, new_size, mhealth), velocity(0.f, 0.f), speed(movement_speed) {
		for(int i=0;i<4;i++){
			keys_down[i]=0;
		}
		
		simulationRunning=true;
		
		std::cout << "Player Init!" << "\n";
			
		palette_type=sandsim::ROCK;
	}

    void Player::update_self() {
		//TODO improve this, add velocity
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			keys_down[1]=1;
		} else {
			keys_down[1]=0;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			keys_down[3]=1;
		} else {
			keys_down[3]=0;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			
			keys_down[0]=1;
		} else {
			keys_down[0]=0;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			keys_down[2]=1;
		} else {
			keys_down[2]=0;
		}
		
		if(keys_down[1]==1){
			position.x-=speed;
		}
		
		if(keys_down[3]==1){
			position.x+=speed;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			simulationRunning=true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			simulationRunning=false;
		}
		
		if(keys_down[0]==1){
			position.y-=speed;
		}
		
		if(keys_down[2]==1){
			position.y+=speed;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
			palette_type=sandsim::AIR;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
			palette_type=sandsim::DIRT;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
			palette_type=sandsim::WATER;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
			palette_type=sandsim::ROCK;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
			palette_type=sandsim::SMOKE;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
			palette_type=sandsim::FIRE;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
			palette_type=sandsim::SEED;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
			palette_type=sandsim::GRAVEL;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
			palette_type=sandsim::ALGAE;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
			palette_type=sandsim::THERMITE;
		}
		
        //position += velocity;
		
		//TODO get global material at to add
		//position.y+=gameConfig.global_position;
    }

	bool Player::colliding() {
		return true;
	}
}