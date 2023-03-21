CC=gcc
CFLAGS=-c -Wall -Wextra -Werror
LFLAGS=-Wall -Wextra -Werror

all: main
main: main_executable_module.o decision.o data_io.o data_stat.o data_process.o
	$(CC) $(LFLAGS) main_executable_module.o data_io.o data_stat.o decision.o data_process.o -o ../../build/Quest3
main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) main_executable_module.c
decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) ../yet_another_decision_module/decision.c
data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) ../data_libs/data_io.c
data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) ../data_libs/data_stat.c
data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) ../data_module/data_process.c
clean: 
	rm -rf *.o main
rebuild:
	clean all
