all: SnakeGame

SnakeGame: Apple.o Map.o Direction.o Engine.o CmdListener.o Renderer.o Position.o Player.o main.o
	g++ -o Snake.exe Apple.o Map.o Direction.o Engine.o CmdListener.o Renderer.o Position.o Player.o main.o

Apple.o: Apple.cpp
	g++ Apple.cpp -o Apple.o -c

Map.o: Map.cpp
	g++ Map.cpp -o Map.o -c

Direction.o: Direction.cpp
	g++ Direction.cpp -o Direction.o -c

Engine.o: Engine.cpp
	g++ Engine.cpp -o Engine.o -c

CmdListener.o: CmdListener.cpp
	g++ CmdListener.cpp -o CmdListener.o -c

Renderer.o: Renderer.cpp
	g++ Renderer.cpp -o Renderer.o -c

Position.o: Position.cpp
	g++ Position.cpp -o Position.o -c

Player.o: Player.cpp
	g++ Player.cpp -o Player.o -c

main.o: main.cpp
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.out
