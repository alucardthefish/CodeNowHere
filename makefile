cnh: Main.o src/CodeNowHere.o
	g++ Main.o src/CodeNowHere.o -o build/cnh.out

Main.o: Main.cpp
	g++ -c Main.cpp

CodeNowHere.o: src/CodeNowHere.cpp
	g++ -c src/CodeNowHere.cpp

clean:
	rm *.o src/*.o build/cnh.out

install:
	cp build/cnh.out ~/.local/bin
	mv ~/.local/bin/cnh.out ~/.local/bin/cnh
	