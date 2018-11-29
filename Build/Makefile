SOURCE_DIR = ../Source
OUTPUT_DIR = ./build
test: main.o WavFile.o
	rm -rf $(OUTPUT_DIR)
	mkdir $(OUTPUT_DIR)
	g++ -o $(OUTPUT_DIR)/test $(SOURCE_DIR)/main.o $(SOURCE_DIR)/WavFile.o

WavFile.o: $(SOURCE_DIR)/WavFile.cpp $(SOURCE_DIR)/WavFile.hpp
	g++ -c -o $(SOURCE_DIR)/WavFile.o $(SOURCE_DIR)/WavFile.cpp

main.o: $(SOURCE_DIR)/WavFile.hpp
	g++ -c -o $(SOURCE_DIR)/main.o $(SOURCE_DIR)/main.cpp