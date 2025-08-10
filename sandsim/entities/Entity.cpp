#include "Entity.hpp"

namespace alives{
	
	Entity::Entity(sf::Vector2f new_pos, sf::Vector2f new_size,int mhealth): position(new_pos), hitsize(new_size), max_health(mhealth) {
		//Stub
		Entity::set_health_to_max();
		Entity::set_id(-1);
	}
	void Entity::set_health_to_max(){
		health=max_health;
	}
	bool Entity::colliding(){
		/*if(bottomblock==sandsim::AIR){
			
		}*/
		return false;
	}
	
	Entity::~Entity(){
		
	}
	
	void Entity::set_id(int new_id) {
		entity_id=new_id;
	}
	
	int Entity::get_id() const{
		return entity_id;
	}
}