#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

namespace alives{
	
	class Entity{
		protected:
			sf::Vector2f position;
			sf::Vector2f hitsize;
			int max_health;
			int health;
			
			int entity_id;
			//Todo speed, 
		public:
			Entity(sf::Vector2f new_pos, sf::Vector2f new_size,int mhealth);
			virtual bool colliding();
			
			void set_health_to_max();
			
			void set_id(int new_id);
			
			int get_id() const;
			
			virtual void update_self()=0;
			
			virtual ~Entity();
	};
}
#endif