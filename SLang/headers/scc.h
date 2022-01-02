#ifndef _SCC_H_
#define _SCC_H_
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include"../../SLECH/SLString.h"
#include"../../SLECH/SLInt.h"
typedef enum _Status {SLERROR = -1,SLSUCCESS = 0,SLOVERFLOW = 1} Status;
//Fuctions
Status GetDefine(String *Code){
    String *temp;
    Status status = SLSUCCESS;
    Int index,range1=0,range2=0,tempindex,rn;
    Char chars[64],replacement[128];
//Get define args and replace it
    while(Code->next!=NULL){
        index = String_IndexEOf(Code,'$');
        if(index==-1){
            return status;
        }
        if(String_GetByEIndex(Code,index+1)=='d'&&String_GetByEIndex(Code,index+2)=='e'&&String_GetByEIndex(Code,index+3)=='f'&&String_GetByEIndex(Code,index+4)=='i'&&String_GetByEIndex(Code,index+5)=='n'&&String_GetByEIndex(Code,index+6)=='e'){
            index+=7;
            while(String_GetByEIndex(Code,index)!=' '){
                chars[range1] = String_GetByEIndex(Code,index);
                range1++;
                index++;
                if(range1 >= 65){
                    status = SLERROR;
                    return status;
                }
            }
            index++;
            while(String_GetByEIndex(Code,index)!='\n'){
                replacement[range2] = String_GetByEIndex(Code,index);
                range2++;
                index++;
                if(range2 >= 129){
                    status = SLERROR;
                    return status;
                }
            }
            Code = String_GetOByEIndex(Code,index);
        }else{
            Code = Code->next->next;
        }
        range1 = 0;
        range2 = 0;
    }

    return status;
}
#endif