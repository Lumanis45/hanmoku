all:
	rm -rf translator
	gcc trans.c -o translator
	./translator	
build:
	rm -rf translator
	gcc trans.c -o translator
run:
	./translator
