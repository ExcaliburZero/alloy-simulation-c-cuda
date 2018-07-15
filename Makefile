CC = gcc
CFLAGS = -Wall -g
OBJS = main.o alloy.o cpu.o writepng.o
HDRS = 
DOCS_DIRS = html latex
EXEC = main

.SUFFIXES: .cpp
.cpp.o:
	$(CC) -c $(CFLAGS) $*.cpp

default: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -lpng -lm

$(OBJS): $(HDRS)

clean: clean_docs
	rm -rf $(EXEC) $(OBJS)

clean_docs:
	rm -Rfd $(DOCS_DIRS)

lint:
	cpplint *.h *.cpp

gpu:
	nvcc -g main.cu alloy.cu gpu.cu -lpng -lm

cpu:
	gcc -g main.c alloy.c cpu.c writepng.c -o main -lpng -lm -fopenmp

multicore:
	#g++ -g main.c alloy.c multicore.c -o main -lm -fopenmp
	g++ -Ofast main.c alloy.c multicore.c -o main -lm -fopenmp

rename_gpu:
	rename 's/c$$/cu/' *.c

rename_cpu:
	rename 's/cu$$/c/' *.cu

profile_gpu:
	valgrind --tool=callgrind ./a.out

profile_cpu:
	valgrind --tool=callgrind ./main
