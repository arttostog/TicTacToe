TARGET = TicTacToe
SOURCE_FILES = ./src/main.c ./src/output.c ./src/logic.c ./src/input.c

ifeq ($(OS), Windows_NT)
	CLEAN_COMMAND = del $(TARGET).exe
else
	CLEAN_COMMAND = rm $(TARGET)
endif

$(TARGET): $(SOURCE_FILES)
	gcc $(SOURCE_FILES) -o $(TARGET)

clean:
	$(CLEAN_COMMAND)