#include "AutomationEntityBase.hpp"

namespace alives{
			
	AutomatonEntity::AutomatonEntity(sf::Vector2f new_pos, sf::Vector2f new_size, sf::Vector2f heart_pos,int mhealth): Entity(new_pos, new_size,mhealth), body(new_size.x*new_size.y,0), heartPosition(heart_pos) {
	}

	bool AutomatonEntity::colliding() {
		//Uhh???
		return true;
	}
}