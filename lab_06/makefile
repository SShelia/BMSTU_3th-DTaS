# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Wextra -Wpedantic -Iinc
UNIT_CFLAGS := $(CFLAGS) -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/data_input.o ./out/all_commands.o ./out/main.o ./out/hash.o ./out/usual_tree.o ./out/avl_tree.o ./out/time_measurement.o 
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

./out/all_commands.o : ./src/all_commands.c
	$(CC) $(CFLAGS) -c $< -o ./out/all_commands.o

./out/hash.o : ./src/hash.c
	$(CC) $(CFLAGS) -c $< -o ./out/hash.o

./out/usual_tree.o : ./src/usual_tree.c
	$(CC) $(CFLAGS) -c $< -o ./out/usual_tree.o

./out/avl_tree.o : ./src/avl_tree.c
	$(CC) $(CFLAGS) -c $< -o ./out/avl_tree.o

./out/time_measurement.o : ./src/time_measurement.c
	$(CC) $(CFLAGS) -c $< -o ./out/time_measurement.o

.PHONY : clean
clean :
	$(RM) ./out/*.o *.exe
