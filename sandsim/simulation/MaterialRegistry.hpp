#ifndef MATERIAL_REGISTRY_HPP
#define MATERIAL_REGISTRY_HPP

#include <iostream>
#include <memory>
#include <functional>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "TileUtils.hpp"

#include "TileRefs.hpp"

namespace sandsim{
	class MaterialRegistry {
		public:
			using MaterialFactory = std::function<std::shared_ptr<Tile>()>;
			
			static void registerMaterial(int aid, MaterialFactory factory);
			
			static std::shared_ptr<Tile> createMaterialFromId(int aid);
			
			static void initialize();
		
		private:
			static std::unordered_map<int, MaterialFactory> material_map;
	};
	
	void initializeSimulation(); //TODO this to other;
}

#endif