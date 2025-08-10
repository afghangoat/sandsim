#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <cstdlib>
#include <cassert>

//Core
#include "core/Renderer.hpp"
#include "core/Utils.hpp"

//Simulation resources
#include "simulation/SimulationConfig.hpp"
#include "simulation/MaterialRegistry.hpp"
#include "simulation/TileUtils.hpp"
#include "simulation/ExtendedChunk.hpp"
#include "simulation/ChunkStream.hpp"

//Entities
#include "entities/Entity.hpp"
#include "entities/AutomationEntityBase.hpp"
#include "entities/SpriteEntityBase.hpp"
#include "entities/Player.hpp"

//TEMPS:
bool tempsavevar=true;

//TODO 

//TODO IDEAS: snow,ice, steel, nuclear waste (emits), firework (goes up and randomly explodes), explosion, salt, brine, meat, cooked meat, potato, cooked potato,
//wire, active_wire, generator, sawblade (destroy nearby things to smoke), antimatter, lightbulb, active_lightbulb, led_rgb, active_led_rgb, pressureplate (give energy when something on top), snake, BOMB (explodes on electricity),Door = Can be activa-not active (can be walked through, if a door is connected to an inactive one, it becomes inactive)
//creepy liquid

//TODO limiting inheritance LoneChunk (no neighbors, easier to simulate)



//void drawMap2D(Renderer renderer){
				// change the size to 100x100
				//rectangle.setPosition(x*CELL_SIZE,y*CELL_SIZE);
				////renderer.window.draw(rectangle);

int main() {
	std::set_new_handler(outOfMemHandler);
	std::srand(static_cast<unsigned>(std::time(0)));
	sandsim::initializeSimulation();
	
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_NAME);

    // Initialize Renderer
    Renderer renderer(window);
    renderer.init();
	renderer.set_sky_scale(2.0);

    // Create a Player instance
	sf::Vector2f player_pos1(100.0f,100.0f);
	sf::Vector2f player_size(2.0f,1.0f); //In tiles
	
    alives::Player player(player_pos1,player_size, 100,2.0);
	player.load_sprite("img/player.png");

	
	sandsim::EChunk chunk1(0,0); //Temp
	sandsim::EChunk chunk2(1,0);
	
	sandsim::ChunkStream temp_chunk_loader;
	
	temp_chunk_loader.loadChunk(&chunk1,"savedata/chunk1");
	
	chunk1.setChunkRelative(&chunk2,0,1);
	
	chunk2.setChunkRelative(&chunk1,0,-1);
	
	//std::cout << "-----------------\n";
		
	int game_timer=0;
	volatile bool ingame=true;
    // Main loop
    while (ingame==true) {
        sf::Event event;
        while (window.pollEvent(event)==true) {
            if (event.type == sf::Event::Closed) {
				ingame=false;
                window.close();
            }
        }
		
		player.update_self();
		
        //clear or draw sky
        window.clear(sf::Color::Black);
		//renderer.draw_sky();
		
		//renderer.draw_sky();
		
		if( sf::Mouse::isButtonPressed( sf::Mouse::Button::Left ) ){
			//TODO get_chunk boundary
			if(sf::Mouse::getPosition(window).x<sandsim::gameConfig.CHUNK_SIZE*VERT_SIZE&&sf::Mouse::getPosition(window).y<sandsim::gameConfig.CHUNK_SIZE*VERT_SIZE){
				for(int i=static_cast<int>(sf::Mouse::getPosition(window).y/VERT_SIZE)-sandsim::gameConfig.BRUSH_SIZE/2;i<=static_cast<int>(sf::Mouse::getPosition(window).y/VERT_SIZE)+sandsim::gameConfig.BRUSH_SIZE/2;i++){
					for(int j=static_cast<int>(sf::Mouse::getPosition(window).x/VERT_SIZE)-sandsim::gameConfig.BRUSH_SIZE/2;j<=static_cast<int>(sf::Mouse::getPosition(window).x/VERT_SIZE)+sandsim::gameConfig.BRUSH_SIZE/2;j++){
						if(j>0&&i>0&&j<sandsim::gameConfig.CHUNK_SIZE*VERT_SIZE&&i<sandsim::gameConfig.CHUNK_SIZE*VERT_SIZE){
							chunk1.setTile(i,j,sandsim::MaterialRegistry::createMaterialFromId(player.palette_type),true);
						}
					}
				}
				
			}
			//
		}
		
		if(game_timer%sandsim::gameConfig.UPDATE_FRAMES==0&&player.simulationRunning==true){
			//chunk1.checkDuplicates();
			//chunk1.checkSame(16,16,17,16);
			//chunk1.checkSame(17,16,17,17);
			chunk1.updateChunk();
			//chunk1.testFor(sandsim::SAND);
			//chunk1.checkDuplicates();
			chunk2.updateChunk();
		}
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&tempsavevar==true) {
			std::cout << "Saved chunk1.dat" << std::endl;
			temp_chunk_loader.saveChunk(&chunk1,"savedata/chunk1");
			tempsavevar=false;
		}
		
		chunk1.drawChunk(renderer);
		chunk2.drawChunk(renderer);

        // Draw the player
		player.draw_self(renderer);
		
        // Display the window contents
        renderer.window.display();
		
		game_timer++;
		
    }

    return 0;
}
