#include"./headers/scc.h"
int main(int argc,char *argv[]){
    if(argc <= 2){
        printf("No enough args.");
        return -1;
    }
    Status status = SLSUCCESS;
    FILE *scf = fopen(argv[1],"r");
    FILE *opf = fopen(argv[2],"w");
    String *Code = new(String);
    if(scf == NULL){
        status = SLERROR;
        printf("Error:Could not open source file:[%s%s",argv[1],"]");
        return status;
    }else if(opf == NULL){
        status = SLERROR;
        printf("Error:Could not open output file:[%s%s",argv[1],"]");
        return status;
    }else{
        String_FInput(scf,Code);
        Code = String_Get_Head(Code);
        GetDefine(Code);
    }
    String_FOutput(opf,Code);
    fclose(scf);
    fclose(opf);
    return status;
}