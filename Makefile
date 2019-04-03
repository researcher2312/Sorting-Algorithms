./pamsi: main.o sort.o utils.o config.h
	g++ -Wall -pedantic -std=c++14  main.o sort.o utils.o -o pamsi

main.o: ./src/main.cpp ./inc/sort.h ./inc/utils.h
	g++ -c -Wall -pedantic -std=c++14 -I ./inc ./src/main.cpp

sort.o: ./src/sort.cpp ./inc/sort.h
	g++ -c -Wall -pedantic -std=c++14 -I ./inc ./src/sort.cpp

utils.o: ./src/utils.cpp ./inc/utils.h
	g++ -c -Wall -pedantic -std=c++14 -I ./inc ./src/utils.cpp

config.h: ./inc/config.h
