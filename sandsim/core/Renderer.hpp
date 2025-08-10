#ifndef CED2_HPP
#define CED2_HPP

#include <SFML/Graphics.hpp>
#include "Utils.hpp"
//#include "SimulationConfig.hpp"

class Renderer {
	private:
		sf::Texture sky;
		sf::Sprite sky_sprite;
	public:
		sf::RenderWindow& window;

		// Constructor to initialize with an existing window
		Renderer(sf::RenderWindow& win);

		void init();
		
		void draw_sky();
		void set_sky_scale(double x);
};

#endif