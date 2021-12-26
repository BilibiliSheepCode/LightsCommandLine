#include"./headers/scc.h"
int main(int argc,char *argv[]){
    Status status = SUCCESS;
    FILE *scf = fopen(argv[1],"r");
    if(scf == NULL){
        status = ERROR;
        printf("Error:Could not open file:[%s%s",argv[1],"]");
        return status;
    }
    return status;
}