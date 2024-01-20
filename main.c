#include "main.h"
#define ADD_SUB 10
#define MUL_DIV 20
#define INVALID 0
#define VALID 1

int buf[100];
int buf_num = -1;


enum InpState{
    START, NUMBER, OPERATOR,  NEGATIVE_SIGN
};

stack operators;
stack_list numbers;

int isDigit(char a)
{
    if(a >='0' && a<='9')
        return 1;
    return 0;
}

int prec(char a)
{
    switch (a) {
        case '+':
        case '-':
            return ADD_SUB;
        case '*':
        case '/':
            return MUL_DIV;
        default:
            return INVALID;
    }
}

int getch(){

    if(buf_num == -1){
        int a = getchar();
        return a;
    }
    return buf[buf_num--];
}

int ungetch(int a)
{
    if(buf_num <= 99)
    {
        buf[++buf_num] = a;
        return 1;
    }
    return 0;
}

//this function will add the number to existing number on top of stack if  value of prev is 1 else create a new number that will go on top of stack 
void get_number(int n, int prev)
{
    if(prev)
    {
        list l = stack_list_pop(&numbers);
        list_add_data(&l, n);
        stack_list_push(&numbers, l);
        return ;
    }
    list l;
    list_init(&l);
    list_add_data(&l, n);
    stack_list_push(&numbers, l);
}
//this function proccesses the string that has no space values
int string(char c)
{
    static enum InpState prev_state = START;
    int Prec ;
    if(c == ' ')
        return  VALID;
    switch(prev_state)
    {
        case START:
            Prec= prec(c);
            if(isDigit(c ))
            {
                prev_state = NUMBER;
                get_number(c - '0', 0);
                return 1;
            }
            else if(Prec)
            {
                switch (c) {
                    case '*':
                    case '/':
                    case '+':
                        prev_state = INVALID;
                        return INVALID;
                    break;
                    case '-':
                        prev_state = NEGATIVE_SIGN;
                        return VALID;
                    break;
                    default:
                        printf("BIG ERROR\n");
                }
            }
            else {
                prev_state = INVALID;
                return INVALID;
            }
            
        break;
        case OPERATOR:
            Prec= prec(c);
            if(isDigit(c ))
            {
                prev_state = NUMBER;
                get_number(c - '0', 0);
                return 1;
            }
            else if(prec(c))
            {
                prev_state = START;
                return INVALID;
            }
            else
            {
                return INVALID;
            }
        break;
                 
        case NUMBER:
            Prec= prec(c);
            if(isDigit(c ))
            {
                prev_state = NUMBER;
                get_number(c - '0', 1);
                return 1;
            }
            else if(Prec) 
            {
                 //push the operator related to prec 
                list l = stack_list_pop(&numbers);
                list_reverse(&l);
                stack_list_push(&numbers, l);
                prev_state = OPERATOR;
                stack_push(&operators, c);
                printf("reversed");
                return 1;
            }
            else {
                list l = stack_list_pop(&numbers);
                list_reverse(&l);
                stack_list_push(&numbers, l);
                return INVALID;   
            }
        break;
                    
        case NEGATIVE_SIGN:
            Prec= prec(c);
            if(isDigit(c))
            {
                prev_state = NUMBER;
                get_number(c - '0', 0);
                stack_list_change_sign(&numbers); 
                return  VALID;
            }
            else if(prec(c))
            {
                prev_state = START; 
                return INVALID;
            }
            else {
                return INVALID; 
            }
        break;
        default:
            return INVALID; 
    }
    return  VALID;
}
int main(){
    stack_list_init(&numbers);
    stack_init(&operators, 10000);
    char c;
    while(1){
        c = getch();
        if(!string(c)){
            printf("character you entered is invalid\n");
            break;
        }
    }
    stack_print(operators);
    stack_list_display(numbers);
}
