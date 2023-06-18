all:
	g++ --std=c++2a src/*.cpp -o prog -I./include

run:
	@./prog
