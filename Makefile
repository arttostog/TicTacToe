TARGET = TicTacToe

SRC_FOLDER = src
BUILD_FOLDER = build
BIN_FOLDER = bin

# For windows
CREATE_FOLDER = if not exist "$(BUILD_FOLDER)" (mkdir "$(BUILD_FOLDER)" && mkdir "$(BUILD_FOLDER)/$(BIN_FOLDER)")
REMOVE_FOLDER = if exist "$(BUILD_FOLDER)" (rmdir /s /q "$(BUILD_FOLDER)")

# For linux
#CREATE_FOLDER = if [ ! -d "$(BUILD_FOLDER)" ]; then mkdir $(BUILD_FOLDER) && mkdir $(BUILD_FOLDER)/$(BIN_FOLDER); fi
#REMOVE_FOLDER = if [ -d "$(BUILD_FOLDER)" ]; then rm -r $(BUILD_FOLDER); fi

$(BUILD_FOLDER)/$(BIN_FOLDER)$(TARGET): $(BUILD_FOLDER) $(BUILD_FOLDER)/main.o $(BUILD_FOLDER)/output.o $(BUILD_FOLDER)/logic.o $(BUILD_FOLDER)/input.o
	gcc $(BUILD_FOLDER)/main.o $(BUILD_FOLDER)/output.o $(BUILD_FOLDER)/logic.o $(BUILD_FOLDER)/input.o -o $(BUILD_FOLDER)/$(BIN_FOLDER)/$(TARGET)

$(BUILD_FOLDER):
	$(CREATE_FOLDER)

$(BUILD_FOLDER)/main.o: $(SRC_FOLDER)/main.c
	gcc -c $(SRC_FOLDER)/main.c -o $(BUILD_FOLDER)/main.o

$(BUILD_FOLDER)/output.o: $(SRC_FOLDER)/output.c
	gcc -c $(SRC_FOLDER)/output.c -o $(BUILD_FOLDER)/output.o

$(BUILD_FOLDER)/logic.o: $(SRC_FOLDER)/logic.c
	gcc -c $(SRC_FOLDER)/logic.c -o $(BUILD_FOLDER)/logic.o

$(BUILD_FOLDER)/input.o: $(SRC_FOLDER)/input.c
	gcc -c $(SRC_FOLDER)/input.c -o $(BUILD_FOLDER)/input.o

clean:
	$(REMOVE_FOLDER)