CXX=g++
CXXFLAGS=
LDFLAGS=-lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor

horror: game.o main.cpp
	$(CXX) game.o main.cpp $(CXXFLAGS) $(LDFLAGS) -o horror

game.o: game.cpp game.hpp
	$(CXX) -c game.cpp $(CXXFLAGS) -o game.o

clean:
	rm *.o horror
