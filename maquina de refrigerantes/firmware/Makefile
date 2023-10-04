TARGET=machine


CXX=~/Downloads/Leon3/sparc-elf-4.4.2/bin/sparc-elf-g++
CFLAGS=-I. -msoft-float -w

.PHONY: all
all: 
	$(CXX) $(CFLAGS) ./*.cpp -o $(TARGET)

.PHONY: clean
clean:
	rm ./$(TARGET)