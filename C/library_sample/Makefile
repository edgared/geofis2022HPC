#gcc flags:
# -c ensamblar pero no enlazar (archivo objeto)
# -o salida
# rm borra archivos
#
#CC=gcc
#$(CC)

CFLAGS=-Wall -Werror
LIBS=-L. -lmy_shared


all: main.o libmy_static.a libmy_shared.so
	gcc -o my_app main.o libmy_static.a $(CFLAGS) $(LIBS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

libmy_static.a: libmy_static_a.o libmy_static_b.o
	ar -rsv libmy_static.a libmy_static_a.o libmy_static_b.o

libmy_static_a.o: libmy_static_a.c
	gcc -c libmy_static_a.c -o libmy_static_a.o $(CFLAGS)

libmy_static_b.o: libmy_static_b.c
	gcc -c libmy_static_b.c -o libmy_static_b.o $(CFLAGS)

libmy_shared.so: libmy_shared.o
	gcc -shared -o libmy_shared.so libmy_shared.o

libmy_shared.o: libmy_shared.c
	gcc -c -fPIC libmy_shared.c -o libmy_shared.o


#.PHONY: clean
clean:
	rm *.o *.a *.so my_app
