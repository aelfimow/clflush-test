WARNINGS += -Wall
WARNINGS += -Wextra
WARNINGS += -pedantic
WARNINGS += -Wno-vla
WARNINGS += -Weffc++
WARNINGS += -std=c++11

OBJDIR = obj

all: clflush_func
	g++ -c main.cpp -o ${OBJDIR}/main.o -O3 -m64 ${WARNINGS}
	g++ ${OBJDIR}/main.o ${OBJDIR}/clflush_func.o -o clflush.exe -O3 -m64 ${WARNINGS}

clflush_func:
	as clflush_func.s -o ${OBJDIR}/clflush_func.o --64

clean:
	rm -f ${OBJDIR}/*.o *.exe

