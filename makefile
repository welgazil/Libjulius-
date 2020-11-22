
all : test_direct test_statique test_dynamique

test_direct : cesar cipher cipher_file

test_statique : libs cesar_S cipher_S cipher_file_S

test_dynamique : libs cesar_D cipher_D cipher_file_D



libs : libjulius.a libjulius.so

CFLAGS=-I./include
#option -I <=> chemin des fichiers d'entetes inclus avec #include <>

LDFLAGS=-L./lib
#option -L <=> chemin des librairies non standards

#production directe 

cesar : ./examples/cesar.c ./src/libjulius.c
	gcc $(CFLAGS) ./examples/cesar.c ./src/libjulius.c -o ./build/cesar

cipher : ./examples/cipher.c ./src/libjulius.c
	gcc $(CFLAGS) ./examples/cipher.c ./src/libjulius.c -o ./build/cipher

cipher_file : ./examples/cipher_file.c ./src/libjulius.c
	gcc $(CFLAGS) ./examples/cipher_file.c ./src/libjulius.c -o ./build/cipher_file

#compilation séparée

libjulius.o : ./src/libjulius.c
	gcc -c ./src/libjulius.c -o ./src/libjulius.o

#production lirairie "libjulius"
#lib statique libjulius.a 

libjulius.a : ./src/libjulius.o
	ar qvs ./lib/libjulius.a ./src/libjulius.o

#lib dyn. libjulius.so 

libjulius_fpic.o : ./src/libjulius.c
	gcc -fPIC -c ./src/libjulius.c -o ./src/libjulius_fpic.o

libjulius.so : libjulius_fpic.o
	gcc -shared ./src/libjulius_fpic.o -o ./lib/libjulius.so 


# demander une édition de liens statique avec la lib println : -l<NOM>

cesar_S : libjulius.a
	gcc -static $(CFLAGS) $(LDFLAGS)  ./examples/cesar.c -o ./build/cesar_S -ljulius

cipher_S : ./examples/cipher.c 
	gcc $(CFLAGS) $(LDFLAGS) -static ./examples/cipher.c -o ./build/cipher_S -ljulius

cipher_file_S : ./examples/cipher_file.c
	gcc $(CFLAGS) $(LDFLAGS) -static ./examples/cipher_file.c -o ./build/cipher_file_S -ljulius

#demander une édition de liens dynamique avec la lib println : -l<NOM>

cesar_D : ./examples/cesar.c
	gcc $(CFLAGS) $(LDFLAGS) ./examples/cesar.c -o ./build/cesar_D -ljulius

cipher_D : ./examples/cipher.c 
	gcc $(CFLAGS) $(LDFLAGS) ./examples/cipher.c -o ./build/cipher_D -ljulius

cipher_file_D : ./examples/cipher_file.c
	gcc $(CFLAGS) $(LDFLAGS) ./examples/cipher_file.c -o ./build/cipher_file_D -ljulius




clean : 
	rm -rf ./build/cesar ./build/cipher ./build/cipher_file ./build/cesar_S ./build/cipher_S ./build/cipher_file_S ./build/cesar_D ./build/cipher_D ./build/cipher_file_D libjulius.a libjulius.so






