CPP_SRC := $(wildcard source/*.cpp)
CPP_OBJ := $(patsubst %.cpp, %.o, $(CPP_SRC))

CXXFLAGS := -I ./include

.PHONY: run clear

run: program
	clear
	./program

program: $(CPP_OBJ)
	g++ -o program $^ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clear:
	rm -f program $(wildcard source/*.o)
