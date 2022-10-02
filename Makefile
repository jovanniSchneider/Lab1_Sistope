CC=gcc
cflags= -Wall -lm
out=lab1
interf=intermedio.txt
#  pruebas 
#	./lab1 datos_juegos_1000.csv -o salida1.txt -d 1990 -p 0
#	./lab1 datos_juegos_2000.csv -o salida2.txt -d 1990 -p 0
#	./lab1 datos_juegos_3000.csv -o salida3.txt -d 1990 -p 0
#
all:
	$(CC) lab1.c -o $(out) $(cflags)
clean:
	rm $(out)
fullclean:
	rm -f $(out) $(interf)
