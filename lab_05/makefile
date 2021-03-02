# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -Iinc
UNIT_CFLAGS := -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/data_input.o ./out/queue_as_array.o ./out/task_execution.o ./out/time_measurement.o ./out/queue_as_linked_list.o

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

./out/queue_as_array.o : ./src/queue_as_array.c
	$(CC) $(CFLAGS) -c $< -o ./out/queue_as_array.o

./out/task_execution.o : ./src/task_execution.c
	$(CC) $(CFLAGS) -c $< -o ./out/task_execution.o

./out/time_measurement.o : ./src/time_measurement.c
	$(CC) $(CFLAGS) -c $< -o ./out/time_measurement.o


./out/queue_as_linked_list.o : ./src/queue_as_linked_list.c
	$(CC) $(CFLAGS) -c $< -o ./out/queue_as_linked_list.o

.PHONY : clean
clean :
	$(RM) *.o *.exe
