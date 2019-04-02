mergesort: obj main.o mergealg.o
	g++ -Wall -o mergesort main.o mergealg.o
obj: 

mergealg.o: mergealg.cpp
	g++ -c -g -o mergealg.o mergealg.cpp

main.o: main.cpp 
	g++ -c -g -o main.o main.cpp

clean:
	rm -f *.o mergesort
