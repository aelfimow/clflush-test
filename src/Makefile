CXXFLAGS  = -O3 -m64
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Wno-vla
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

all: clflush_func
	g++ -c *.cpp ${CXXFLAGS}
	g++ *.o -o clflush.exe ${CXXFLAGS}

clflush_func:
	as clflush_func.s -o clflush_func.o --64
