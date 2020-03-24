CXX := g++
DIR := out

OBJECTS := $(DIR)/hello.o $(DIR)/here.o $(DIR)/bye.o
LIBNAME := $(DIR)/mylib.a

all: $(DIR)/test_make

$(DIR)/test_make: $(DIR)/main.o $(LIBNAME)
	$(CXX) -o $@ $^

$(DIR)/%.o: %.cpp
	mkdir -p $(DIR)
	$(CXX) -c -o $@ $<

$(LIBNAME): $(OBJECTS)
	ar -r $@ $^

.PHONY: clean
clean:
	rm -rf $(DIR)
