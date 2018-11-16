all : forkin.c
	gcc -o forkin forkin.c

run : 
	./forkin

clean : 
	rm ./forkin


