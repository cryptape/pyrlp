#CFILE=binascii.c pybinascii.c
CFLAG = -c -fPIC
INCLUDE= -I/usr/include/python2.7 -I./
COMMON_OBJS = binascii.o pybinascii.o

lib:
	gcc $(INCLUDE) $(CFLAG) binascii.c -o binascii.o
	gcc $(INCLUDE) $(CFLAG) pybinascii.c -o pybinascii.o
	gcc -shared $(COMMON_OBJS) -o pybinascii.so -lpython2.7

#binascii.o : binascii.c binascii.h

#pybinascii.o : binascii.o pybinascii.c $(INCLUDE)

clean:
	rm *\.so *\.o
