CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Wno-vla
CXXFLAGS += -Weffc++
CXXFLAGS += -std=c++17

all: clflush_func
	g++ -c scoped_chrono_priv.cpp -o scoped_chrono_priv.o -O3 -m64 ${CXXFLAGS}
	g++ -c scoped_chrono.cpp -o scoped_chrono.o -O3 -m64 ${CXXFLAGS}
	g++ -c main.cpp -o main.o -O3 -m64 ${CXXFLAGS}
	g++ main.o clflush_func.o scoped_chrono_priv.o scoped_chrono.o -o clflush.exe -O3 -m64 ${CXXFLAGS}

clflush_func:
	as clflush_func.s -o ${OBJDIR}/clflush_func.o --64
