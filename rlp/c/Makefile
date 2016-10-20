#CFILE=binascii.c pybinascii.c
CFLAG = -c -fPIC
INCLUDE= -I/usr/include/python2.7 -I./
COMMON_OBJS = binascii.o pycrlp.o

lib:
	gcc $(INCLUDE) $(CFLAG) binascii.c -o binascii.o
	gcc $(INCLUDE) $(CFLAG) pycrlp.c -o pycrlp.o
	gcc -shared $(COMMON_OBJS) -o pycrlp.so -lpython2.7

#binascii.o : binascii.c binascii.h

#pybinascii.o : binascii.o pybinascii.c $(INCLUDE)

clean:
	rm *\.so *\.o
