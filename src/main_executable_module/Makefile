CC=gcc
CFLAGS=-Wall -Wextra -Werror


allbuild: main
main: decision.o data_io.o data_stat.o main_executable_module.o data_process.o 
	$(CC) $(CFLAG) main_executable_module.o data_io.o data_stat.o decision.o  data_process.o -o ../../build/Quest_3
build_with_macro: decision.o data_stat.o main_executable_module_macro.o data_process.o 
	$(CC) $(CFLAG) main_executable_module.o data_stat.o decision.o  data_process.o -o ../../build/Quest_4
build_with_static: decision.o data_io.o libdata_stat.a main_executable_module.o data_process.o 
	$(CC) $(CFLAG) main_executable_module.o data_io.o decision.o  data_process.o -o ../../build/Quest_5 -L../data_libs/ -ldata_stat
build_with_dynamic: decision.o data_io.o main_executable_module.o libdata_process.so 
	$(CC) $(CFLAG) main_executable_module.o data_io.o decision.o  -o ../../build/Quest_6 -L../data_libs/ -ldata_process -Wl,-rpath,../data_libs/
libdata_process.so: ../data_module/data_process.c ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c -fPIC ../data_module/data_process.c
	$(CC) $(CFLAGS) -c -fPIC ../data_libs/data_stat.c
	$(CC) -shared -o ../data_libs/libdata_process.so data_process.o data_stat.o
libdata_stat.a: data_stat.o
	ar r ../data_libs/libdata_stat.a data_stat.o
main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c
main_executable_module_macro.o: main_executable_module.c
	$(CC) $(CFLAGS) -c -DMACROS main_executable_module.c
decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c
data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	$(CC) $(CFLAGS) -c ../data_module/data_process.c
data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c
data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c
clean:
	rm -rf *.o ../../build/Quest_3 ../../build/Quest_4 ../../build/Quest_5 ../../build/Quest_6 ../data_libs/*.a ../data_libs/*.so
rebuild: 
	clean build