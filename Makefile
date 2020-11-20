all: ./dll/dll.c 
	gcc -g -Wall -o run_dll ./dll/dll.c

clean: 
	$(RM) run_dll
