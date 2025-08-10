CXX = g++
CXXFLAGS = -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = main
SRC = main.cpp simulation/MaterialRegistry.cpp simulation/ChunkStream.cpp simulation/ExtendedChunk.cpp simulation/SimulationConfig.cpp simulation/TileUtils.cpp $(wildcard core/*.cpp) $(wildcard entities/*.cpp) $(wildcard simulation/materials/*.cpp)
#Add all the cpp files: simulation/materials/*.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)