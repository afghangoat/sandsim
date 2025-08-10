#include "SpriteEntityBase.hpp"

namespace alives{
	
	SpriteEntity::SpriteEntity(sf::Vector2f new_pos, sf::Vector2f new_size,int mhealth): Entity(new_pos, new_size, mhealth) {
		sprite_loaded=false;
	}
	void SpriteEntity::load_sprite(std::string path){
		if (!entity_texture.loadFromFile(path)) {
			perror("Couldn't load texture for entity!");
			return;
		} else {
			sprite.setTexture(entity_texture);
			sprite_loaded=true;
		}
	}

	bool SpriteEntity::colliding() {
		return true;
	}
	void SpriteEntity::draw_self(Renderer& renderer) {
		if(sprite_loaded==true){
			sprite.setPosition(static_cast<int>(position.x), static_cast<int>(position.y));
			renderer.window.draw(sprite);
		}
	}
	
	void SpriteEntity::set_animation_config(int a_frames, double a_speed, int m_frames, int t_width, int t_height){
		animation_frames=a_frames;
		texture_width=t_width;
		texture_height=t_height;
		animation_speed=a_speed;
		max_frames=m_frames;
	}
}