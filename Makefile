./pamsi: main.o sort.o utils.o
	g++ -Wall -pedantic -std=c++11  main.o sort.o utils.o -o pamsi

main.o: ./src/main.cpp ./inc/sort.h ./inc/utils.h
	g++ -c -Wall -pedantic -std=c++11 -I ./inc ./src/main.cpp

sort.o: ./src/sort.cpp ./inc/sort.h
	g++ -c -Wall -pedantic -std=c++11 -I ./inc ./src/sort.cpp

utils.o: ./src/utils.cpp ./inc/utils.h
	g++ -c -Wall -pedantic -std=c++11 -I ./inc ./src/utils.cpp
