CPP_FLAG=-std=c++11 -fPIC
TARGET=test
INCLUDE= -I../
LIB= -L../
ALL:
	g++ $(CPP_FLAG) $(INCLUDE) $(LIB) -lrlp test.cpp -o $(TARGET)

clean:
	rm *.so *.o $(TARGET)
