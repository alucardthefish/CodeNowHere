cnh: Main.o src/CodeNowHere.o
	g++ Main.o src/CodeNowHere.o -o cnh.out

Main.o: Main.cpp
	g++ -c Main.cpp

CodeNowHere.o: src/CodeNowHere.cpp
	g++ -c src/CodeNowHere.cpp

clean:
	rm *.o src/*.o cnh.out