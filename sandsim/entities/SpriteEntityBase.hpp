#ifndef SENTITY_HPP
#define SENTITY_HPP
#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "../core/Renderer.hpp"
#include <string>
#include <iostream>

namespace alives{

	//Entity consists of an animated sprite
	class SpriteEntity: public Entity {
		protected:
			
			sf::Texture entity_texture;
			sf::Sprite sprite;
			
			int animation_frames;
			int texture_width;
			int texture_height;
			double animation_speed;
			int max_frames;
			
			bool sprite_loaded;
			
		public:
			SpriteEntity(sf::Vector2f new_pos, sf::Vector2f new_size,int mhealth);
			
			void set_animation_config(int a_frames, double a_speed, int m_frames, int t_width, int t_height);
			
			bool colliding();
			
			void load_sprite(std::string path);

			void draw_self(Renderer& renderer);
	};
}
#endif