all: compile link

compile:
	g++ -Isrc/include -c main.cpp game.cpp converter.cpp display.cpp diagonalLeft.cpp diagonalRight.cpp horizontal.cpp vertical.cpp game_2.cpp draw.cpp

link:
	g++ main.o game.o converter.o display.o diagonalLeft.o diagonalRight.o horizontal.o vertical.o game_2.o draw.o -o bin/main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system