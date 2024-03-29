TARGET = TicTacToe

SRC_FOLDER = ./src/
BUILD_FOLDER = ./build/
BIN_FOLDER = $(BUILD_FOLDER)bin/

$(BIN_FOLDER)$(TARGET): $(BUILD_FOLDER) $(BUILD_FOLDER)main.o $(BUILD_FOLDER)output.o $(BUILD_FOLDER)logic.o $(BUILD_FOLDER)input.o
	gcc $(BUILD_FOLDER)main.o $(BUILD_FOLDER)output.o $(BUILD_FOLDER)logic.o $(BUILD_FOLDER)input.o -o $(BIN_FOLDER)$(TARGET)

$(BUILD_FOLDER):
	if not exist "$(BIN_FOLDER)" (mkdir "$(BIN_FOLDER)")

$(BUILD_FOLDER)main.o: $(SRC_FOLDER)main.c
	gcc -c $(SRC_FOLDER)main.c -o $(BUILD_FOLDER)main.o

$(BUILD_FOLDER)output.o: $(SRC_FOLDER)output.c
	gcc -c $(SRC_FOLDER)output.c -o $(BUILD_FOLDER)output.o

$(BUILD_FOLDER)logic.o: $(SRC_FOLDER)logic.c
	gcc -c $(SRC_FOLDER)logic.c -o $(BUILD_FOLDER)logic.o

$(BUILD_FOLDER)input.o: $(SRC_FOLDER)input.c
	gcc -c $(SRC_FOLDER)input.c -o $(BUILD_FOLDER)input.o

clean:
	if exist "$(BUILD_FOLDER)" (rmdir /s /q "$(BUILD_FOLDER)")