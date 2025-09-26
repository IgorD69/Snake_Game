all: SnakeGame

SnakeGame: Apple.o Map.o Direction.o Engine.o Renderer.o Position.o Player.o main.o
	g++ -o Player.out Apple.o Map.o Direction.o Engine.o Renderer.o Position.o Player.o main.o

Apple.o:
	g++ Apple.cpp -o Apple.o -c

Map.o:
	g++ Map.cpp -o Map.o -c

Direction.o:
	g++ Direction.cpp -o Direction.o -c

Engine.o:
	g++ Engine.cpp -o Engine.o -c

Renderer.o:
	g++ Renderer.cpp -o Renderer.o -c

Position.o:
	g++ Position.cpp -o Position.o -c

Player.o:
	g++ Player.cpp -o Player.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.out
