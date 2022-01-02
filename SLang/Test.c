#include"headers/scc.h"
int main(void){
    String *test = new(String);
    String_Set(test,"en?");
    printf("%ld",String_Compare(test,"en?",3));
    getchar();
    return 0;
}