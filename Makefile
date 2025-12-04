CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: Snake.out

Snake.out: Apple.o Map.o Direction.o Engine.o CmdListener.o Renderer.o Position.o Player.o main.o
	$(CXX) -o Snake.out Apple.o Map.o Direction.o Engine.o CmdListener.o Renderer.o Position.o Player.o main.o

Apple.o: Apple.cpp
	$(CXX) $(CXXFLAGS) -c Apple.cpp

Map.o: Map.cpp
	$(CXX) $(CXXFLAGS) -c Map.cpp

Direction.o: Direction.cpp
	$(CXX) $(CXXFLAGS) -c Direction.cpp

Engine.o: Engine.cpp
	$(CXX) $(CXXFLAGS) -c Engine.cpp

CmdListener.o: CmdListener.cpp
	$(CXX) $(CXXFLAGS) -c CmdListener.cpp

Renderer.o: Renderer.cpp
	$(CXX) $(CXXFLAGS) -c Renderer.cpp

Position.o: Position.cpp
	$(CXX) $(CXXFLAGS) -c Position.cpp

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o Snake.out

.PHONY: all clean
