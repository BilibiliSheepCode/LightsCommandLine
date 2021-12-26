#include"Main.h"
int main(void){
    String *string = new(String),*string1 = new(String);
    string = String_Set(string,"en?");
    String_Output(string);
    printf("\n按任意键退出");
    Pause();
    return 0;
}