CCFLAGS = -Wall -Werror -g
LDFLAGS = -lm

build:stack_list.o stack.o list.o main.c main.h
	gcc $(CCFLAGS) stack_list.o stack.o list.o main.c -o build

stack_list.o:./stack_list_of_numbers/stack_list.c ./stack_list_of_numbers/stack_list.h
	gcc -c $(CCFLAGS) ./stack_list_of_numbers/stack_list.c 

stack.o:./stack/stack.c ./stack/stack.h
	gcc -c $(CCFLAGS) ./stack/stack.c

list.o:./list/list.c ./list/list.h
	gcc -c $(CCFLAGS) ./list/list.c 
