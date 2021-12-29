#include"headers/scc.h"
int main(void){
    BInt *bint1 = new(BInt),*bint2 = new(BInt);
    bint1->num = 0xFFFF;
    bint2->num = 0xFFFF;
    BInt_Add(bint1,bint2);
    printf("%x%x%x",bint1->num,bint1->next->num,bint2->num);
    getchar();
    return 0;
}