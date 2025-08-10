#include "Renderer.hpp"
//sf::RenderWindow& window;

// Constructor to initialize with an existing window
Renderer::Renderer(sf::RenderWindow& win) : window(win) {
	
}

void Renderer::init() {
	window.setFramerateLimit(FPS);
	if (!sky.loadFromFile("img/sky.png")) {
		perror("Couldn't load texture \"img/sky.png\"!");
		return;
	} else {
		sky_sprite.setTexture(sky);
		sky_sprite.setPosition(0,0);
	}
	
}

void Renderer::draw_sky(){
	window.draw(sky_sprite);
}
void Renderer::set_sky_scale(double x){
	sky_sprite.setScale(x,x);
}