#include "MaterialRegistry.hpp"

namespace sandsim{
	
	using MaterialFactory = std::function<std::shared_ptr<Tile>()>;
	
	std::unordered_map<int, MaterialRegistry::MaterialFactory> MaterialRegistry::material_map;

	void MaterialRegistry::registerMaterial(int aid, MaterialFactory factory) {
		material_map[aid] = factory;
	}
	
	std::shared_ptr<Tile> MaterialRegistry::createMaterialFromId(int aid) {
		auto it = material_map.find(aid);
		if (it != material_map.end()) {
			return it->second();
		}

		std::cout << "Invalid material ID: " << aid << ". Defaulting to AIR\n";
		return std::make_shared<Air>();
	}
	
	void MaterialRegistry::initialize(){
		material_map = {
			{AIR, []() { return std::make_shared<Air>(); }},
			{SAND, []() { return std::make_shared<Sand>(); }},
			{WATER, []() { return std::make_shared<Water>(); }},
			{ROCK, []() { return std::make_shared<Rock>(); }},
			{STEAM, []() { return std::make_shared<Steam>(); }},
			{LAVA, []() { return std::make_shared<Lava>(); }},
			{ACID, []() { return std::make_shared<Acid>(); }},
			{GRAVEL, []() { return std::make_shared<Gravel>(); }},
			{COPPER, []() { return std::make_shared<Copper>(); }},
			{OIL, []() { return std::make_shared<Oil>(); }},
			{FIRE, []() { return std::make_shared<Fire>(); }},
			{SMOKE, []() { return std::make_shared<Smoke>(); }},
			{WOOD, []() { return std::make_shared<Wood>(); }},
			{GLUE, []() { return std::make_shared<Glue>(); }},
			{DIRT, []() { return std::make_shared<Dirt>(); }},
			{SEED, []() { return std::make_shared<Seed>(); }},
			{PLANT, []() { return std::make_shared<Plant>(); }},
			{PETAL, []() { return std::make_shared<Petal>(); }},
			{ALGAE, []() { return std::make_shared<Algae>(); }},
			{BAMBOO, []() { return std::make_shared<Bamboo>(); }},
			{SAPLING, []() { return std::make_shared<Sapling>(); }},
			{LEAVES, []() { return std::make_shared<Leaves>(); }},
			{COAL, []() { return std::make_shared<Coal>(); }},
			{ASH, []() { return std::make_shared<Ash>(); }},
			{THERMITE, []() { return std::make_shared<Thremite>(); }},
		};
	}
	
	void initializeSimulation(){
		MaterialRegistry::initialize();
	}
	//Todo function to fill this map up, probably put in gameConfig class
}