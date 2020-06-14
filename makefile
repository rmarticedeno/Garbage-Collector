run: compile
	./a.out example.map 150
compile: compress
	gcc ./Engine/main.c -ldl ./Engine/engine.a
	rm engine.o
compress: init
	ar -rsc ./Engine/engine.a engine.o
init:
	gcc -c ./Engine/engine.c	
mov:
	gcc -shared -fPIC -o ./Engine/mov.so ./Engine/mov.c
