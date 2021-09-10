all: velha.o testa_velha.cpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs velha.o testa_velha.cpp -o testa_velha.exe

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c velha.cpp

check: 
	cppcheck --enable=warning .

cpplint:
	python ~/.local/lib/python3.9/site-packages/cpplint.py velha.cpp
	python ~/.local/lib/python3.9/site-packages/cpplint.py testa_velha.cpp

doxygen:
	doxygen 

gcov: 
	gcov velha.cpp

valgrind:
	valgrind --leak-check=full ./testa_velha.exe

cleangcov:
	rm -rf *.gc*

clean:
	rm -rf *.o *.exe
