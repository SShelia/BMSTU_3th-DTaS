# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Iinc
UNIT_CFLAGS := $(CFLAGS) -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/data_input.o ./out/time_measurement.o ./out/find_cities.o ./out/graph_adjacency.o ./out/graph_matrix.o ./out/output.o ./out/main.o
# Путь к хэдерам
H:= ./inc/

# Путь к си файлам
C:= ./src/

# Путь к объектным файлам
O:= ./out/

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
app.exe : $(OBJS) 
	$(CC) -o app.exe $(OBJS)

./out/main.o : ./src/main.c 
	$(CC) $(CFLAGS) -c $< -o ./out/main.o

./out/data_input.o : ./src/data_input.c
	$(CC) $(CFLAGS) -c $< -o ./out/data_input.o

./out/time_measurement.o : ./src/time_measurement.c
	$(CC) $(CFLAGS) -c $< -o ./out/time_measurement.o

./out/find_cities.o : ./src/find_cities.c
	$(CC) $(CFLAGS) -c $< -o ./out/find_cities.o

./out/graph_adjacency.o : ./src/graph_adjacency.c
	$(CC) $(CFLAGS) -c $< -o ./out/graph_adjacency.o

./out/graph_matrix.o : ./src/graph_matrix.c
	$(CC) $(CFLAGS) -c $< -o ./out/graph_matrix.o

./out/output.o : ./src/output.c
	$(CC) $(CFLAGS) -c $< -o ./out/output.o

.PHONY : clean
clean :
	$(RM) ./out/*.o *.exe
