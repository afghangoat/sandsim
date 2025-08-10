#ifndef AENTITY_HPP
#define AENTITY_HPP
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

namespace alives{

	//Entity consists of tiles
	class AutomatonEntity: public alives::Entity{ //public Entity or private Entity?
		protected:
			std::vector<int> body;
			sf::Vector2f heartPosition;
			
		public:
			
			AutomatonEntity(sf::Vector2f new_pos, sf::Vector2f new_size, sf::Vector2f heart_pos,int mhealth);
			
			bool colliding();
	};
}

#endif