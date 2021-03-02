# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Iinc
UNIT_CFLAGS := -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/data_input.o ./out/print_stack.o ./out/stack_as_linked_list.o ./out/stack_as_static_array.o ./out/task_execution.o ./out/time_measurement.o

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

./out/data_input.o : ./src/data_input.c
	$(CC) $(CFLAGS) -c $< -o ./out/data_input.o

./out/print_stack.o : ./src/print_stack.c
	$(CC) $(CFLAGS) -c $< -o ./out/print_stack.o

./out/stack_as_linked_list.o : ./src/stack_as_linked_list.c
	$(CC) $(CFLAGS) -c $< -o ./out/stack_as_linked_list.o

./out/stack_as_static_array.o : ./src/stack_as_static_array.c
	$(CC) $(CFLAGS) -c $< -o ./out/stack_as_static_array.o

./out/task_execution.o : ./src/task_execution.c
	$(CC) $(CFLAGS) -c $< -o ./out/task_execution.o

./out/time_measurement.o : ./src/time_measurement.c
	$(CC) $(CFLAGS) -c $< -o ./out/time_measurement.o

.PHONY : clean
clean :
	$(RM) *.o *.exe
