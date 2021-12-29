#ifndef SL_BASICS_H
#define SL_BASICS_H

//Include
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Define
#define new(C) C ## _Build()
#define delete(C,A) C ## _Delete(A)
#define regmem(C) (C*)malloc(sizeof(C))
#define delmem(P) free(P)
//Typedef
typedef char Char;
typedef long long int Int;
typedef double Float;
//Functions
void Pause(void){
    getch();
    return;
}
#endif