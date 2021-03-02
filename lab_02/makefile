# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -Iinc
UNIT_CFLAGS := -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/add_new_perfomance.o ./out/delete_perfomance.o ./out/filling_structure_fields.o ./out/output.o ./out/sort.o

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

./out/add_new_perfomance.o : ./src/add_new_perfomance.c
	$(CC) $(CFLAGS) -c $< -o ./out/add_new_perfomance.o

./out/delete_perfomance.o : ./src/delete_perfomance.c
	$(CC) $(CFLAGS) -c $< -o ./out/delete_perfomance.o

./out/filling_structure_fields.o : ./src/filling_structure_fields.c
	$(CC) $(CFLAGS) -c $< -o ./out/filling_structure_fields.o

./out/output.o : ./src/output.c
	$(CC) $(CFLAGS) -c $< -o ./out/output.o 

./out/sort.o : ./src/sort.c
	$(CC) $(CFLAGS) -c $< -o ./out/sort.o 


.PHONY : clean
clean :
	$(RM) *.o *.exe
