#include "main.h"
int buf[100];
int buf_num = -1;

enum LastInp{
    START, NUMBER, OPERATOR, INVALID
};

list str;

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
            return 10;
        case '*':
        case '/':
            return 20;
        default:
            return 0;
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

//this function will input the number and store in the gloabal list 
void get_number()
{
    while(1)
    {
        list num;
        list_init(num);
        char c = getch();
        if(prec(c))
        {
            ungetch(c);
            break;
        }

        if(c == ' ')
            break ;

        if(isDigit(c))
        {
            list_add_data(&num, c - '0');      
        }
    }
}

void evaluate(char c)
{

}
int main(){
    list_init(& str);
    while(1){
        char c;
        scanf("%c", &c);
        if(c == EOF || c == '\n')
            break;
    }
    printf("%d", isDigit('9')); 
}
