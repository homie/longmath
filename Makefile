main: longmath.cpp longmath.h main.cpp
	g++ -o main main.cpp longmath.cpp
clean:
	-@rm longmath.o main
