#ifndef SL_SLINT_H
#define SL_SLINT_H
//Include
#include"SLBasics.h"
//Define

//Typedef
typedef struct _BInt{
    int num;
    struct _BInt *ahead,*next;
} BInt;
//Functions
void BInt_Delete(BInt *bint){
    free(bint);
}
BInt *BInt_Build(){
    BInt *Return = regmem(BInt);
    Return->ahead = NULL;
    Return->next = NULL;
    Return->num = 0;
    return Return;
}
BInt *BInt_Get_Head(BInt *bint){
    while(bint->ahead!=NULL){
        bint = bint->ahead;
    }
    return bint;
}
BInt *BInt_Get_End(BInt *bint){
    while(bint->next!=NULL){
        bint = bint->next;
    }
    return bint;
}
BInt *BInt_Add(BInt *bint1,BInt *bint2){
    Int temp = 0;
    BInt *BIZero = new(BInt),*BIOne = new(BInt),*Temp;
    BIZero->num = 0x0;
    BIOne->num = 0x1;
    while(bint1!=NULL && bint2!=NULL){
        temp = bint1->num + bint2->num;
        if(temp >= 0xFFFF){
            temp -= 0xFFFF;
            bint1->num = (int) temp-1;
            if(bint1->next==NULL){
                bint1->next = new(BInt);
                bint1->next->ahead = bint1;
            }
            BInt_Add(bint1->next,BIOne);
            bint1 = bint1->next;
            bint2 = bint2->next;  
        }else{
            bint1->num = bint1->num+bint2->num;
            if(bint1->next==NULL){
                bint1->next = new(BInt);
                bint1->next->ahead = bint1;
            }
            bint1 = bint1->next;
            bint2 = bint2->next;
        }
    }
    return bint1;
}  
#endif