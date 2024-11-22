TARGET = TicTacToe
GCC_FLAGS = -I./include

ifeq ($(OS), Windows_NT)
	CLEAN_COMMAND = del $(TARGET).exe
else
	CLEAN_COMMAND = rm $(TARGET)
endif

$(TARGET): $(SOURCE_FILES)
	gcc $(GCC_FLAGS) $(wildcard ./src/*.c) -o $(TARGET)

clean:
	$(CLEAN_COMMAND)