CXX = g++
LIBS =
CXXFLAGS = -Wall -std=c++11
OBJECTS = main.o
HFILES = singlelist.hpp
TARGET = main.out

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LIBS)

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core