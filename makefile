build:stack_list.o stack.o list.o main.c main.h
	gcc stack_list.o stack.o list.o main.c -o build

stack_list.o:./stack_list_of_numbers/stack_list.c ./stack_list_of_numbers/stack_list.h
	gcc -c ./stack_list_of_numbers/stack_list.c 

stack.o:./stack/stack.c ./stack/stack.h
	gcc -c ./stack/stack.c

list.o:./list/list.c ./list/list.h
	gcc -c ./list/list.c 
