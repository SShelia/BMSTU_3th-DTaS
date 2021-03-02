# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -Iinc
UNIT_CFLAGS := -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/addition_of_matrices.o ./out/filling_matrix.o ./out/input_size_and_command.o ./out/memory_allocation_for_matrix.o ./out/output.o

# Очистка
RM:= rm

.PHONY: release debug unit
release: CFLAGS += -DNDEBUG -g0
debug: CFLAGS += -g3

release: app.exe
debug: app.exe
all: app.exe
unit: unit_tests.exe
	./unit_tests.exe


#Запуск самой программы
app.exe : $(OBJS) ./out/main.o
	$(CC) -o app.exe $(OBJS) ./out/main.o

./out/main.o : ./src/main.c 
	$(CC) $(CFLAGS) -c $< -o ./out/main.o

./out/addition_of_matrices.o : ./src/addition_of_matrices.c
	$(CC) $(CFLAGS) -c $< -o ./out/addition_of_matrices.o

./out/filling_matrix.o : ./src/filling_matrix.c
	$(CC) $(CFLAGS) -c $< -o ./out/filling_matrix.o

./out/input_size_and_command.o : ./src/input_size_and_command.c
	$(CC) $(CFLAGS) -c $< -o ./out/input_size_and_command.o

./out/output.o : ./src/output.c
	$(CC) $(CFLAGS) -c $< -o ./out/output.o 

./out/memory_allocation_for_matrix.o : ./src/memory_allocation_for_matrix.c
	$(CC) $(CFLAGS) -c $< -o ./out/memory_allocation_for_matrix.o


.PHONY : clean
clean :
	$(RM) *.o *.exe
