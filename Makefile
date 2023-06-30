TARGET = DVS.out
COMP = g++
LIBS = -lSDL2 -lSDL2_mixer -lSDL2_ttf
PREF_SRC = ./source/
PREF_OBJ = ./objects/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET): $(OBJ)
	$(COMP) $(OBJ) -g -o $(TARGET) $(LIBS)

$(PREF_OBJ)%.o: $(PREF_SRC)%.cpp
	$(COMP) -g -c $< -o $@

clean:
	rm $(PREF_OBJ)*.o $(TARGET)
