# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror -pedantic -Iinc
UNIT_CFLAGS := -ggdb -lcheck

# Общие объектные файлы
OBJS := ./out/adding_number_to_structere.o ./out/division.o ./out/number_normalization.o 

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

./out/adding_number_to_structere.o : ./src/adding_number_to_structere.c
	$(CC) $(CFLAGS) -c $< -o ./out/adding_number_to_structere.o

./out/division.o : ./src/division.c
	$(CC) $(CFLAGS) -c $< -o ./out/division.o

./out/number_normalization.o : ./src/number_normalization.c
	$(CC) $(CFLAGS) -c $< -o ./out/number_normalization.o 



.PHONY : clean
clean :
	$(RM) *.o *.exe
