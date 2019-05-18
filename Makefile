all: Cards

Cards: main.o 
	g++ -Wall -pedantic -g -o Cards main.cpp war.cpp deck.cpp player.cpp system.cpp

main.o: main.cpp war.h
	g++ -Wall -pedantic -g -c main.cpp

war.o: war.h war.cpp player.h deck.h system.h
	g++ -Wall -pedantic -g -c war.cpp

player.o: player.h player.cpp deck.h
	g++ -Wall -pedantic -g -c player.cpp

deck.o: deck.h deck.cpp
	g++ -Wall -pedantic -g -c deck.cpp

system.o: system.h system.cpp
	g++ -Wall -pedantic -g -c system.cpp
 
clean:
	rm -f Cards Cards.exe main.o war.o deck.o player.o
