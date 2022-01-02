#ifndef SL_STRING_H
#define SL_STRING_H

//Include
#include"SLBasics.h"
//Define

//Typedef
typedef struct _String{
    Char chr;
    struct _String *ahead,*next;
} String;
//Functions
void String_Delete(String *string){
    delmem(string);
    return;
}
void String_DeleteSonString(String *string){
    while(string!=NULL){
        delmem(string);
    }
    return;
}
Int String_Cut(String *string,Int index1,Int index2){
    String *temp,*temp1,*temp2,*temp3;
    string = String_Get_Head(string);
    if(String_Lenth(string)<index2){
        return -1;
    }else{
        for(Int i = 0;i<=index1;i++){
            string = string->next;
        }
        temp = string;
        temp1 = string->next;
        string = String_Get_Head(string);
        for(Int i = 0;i<=index2;i++){
            string = string->next;
        }
        temp2 = string;
        temp3 = string->ahead;
        temp1->ahead = NULL;
        temp3->next = NULL;
        temp->next = temp2;
        temp2->ahead = temp;
        String_DeleteSonString(temp1);
    }
    return 0;
}
String *String_Build(){
    String *Return = regmem(String);
    Return->ahead = NULL;
    Return->next = NULL;
    Return->chr = ' ';
    return Return;
}
String *String_Get_Head(String *string){
    while(string->ahead!=NULL){
        string = string->ahead;
    }
    return string;
}
String *String_Get_End(String *string){
    while(string->next!=NULL){
        string = string->next;
    }
    return string;
}
String *String_Input(String *string){
    Char temp=getchar();
    while(temp!='\n'){
        string->chr = temp;
        string->next = new(String);
        string->next->ahead = string;
        string = string->next;
        temp = getchar();
    }
    return string;
}
String *String_Output(String *string){
    string = String_Get_Head(string);
    while(string->next!=NULL){
        putchar(string->chr);
        string = string->next;
    }
    return string;
}
String *String_FInput(FILE *stream,String *string){
    Char temp=fgetc(stream);
    while(temp!=EOF){
        string->chr = temp;
        string->next = new(String);
        string->next->ahead = string;
        string = string->next;
        temp = fgetc(stream);
    }
    return string;
}
String *String_FOutput(FILE *stream,String *string){
    string = String_Get_Head(string);
    while(string->next!=NULL){
        fputc(string->chr,stream);
        string = string->next;
    }
    return string;
}
String *String_Set(String *string,Char *chars){
    int range = 0;
    Char temp=chars[range];
    while(chars[range]){
        string->chr = temp;
        string->next = new(String);
        string->next->ahead = string;
        string = string->next;
        range++;
        temp = chars[range];
    }
    return string;
}
String *String_Concat(String *string1,String *string2){
    string1 = String_Get_End(string1);
    string1 = string1->ahead;
    delete(String,string1->next);
    string2 = String_Get_Head(string2);
    string1->next = string2;
    string2->ahead = string1;
    return String_Get_Head(string1);
}

Int String_IndexOf(String *string,Char index){
    Int Index = 0;
    string = String_Get_Head(string);
    while(string->chr!=index){
        if(string->next==NULL){
            return -1;
        }
        string = string->next;
        Index++;
    }
    return Index;
}

Int String_IndexEOf(String *string,Char index){
    Int Index = 0;
    while(string->chr!=index){
        if(string->next==NULL){
            return -1;
        }
        string = string->next;
        Index++;
    }
    return Index;
}

Char String_GetByIndex(String *string,Int index){
    string = String_Get_Head(string);
    for(index;index;--index){
        if(string->next==NULL){
            return -1;
        }
        string = string->next;
    }
    return string->chr;
}

Char String_GetByEIndex(String *string,Int index){
    for(index;index;--index){
        if(string->next==NULL){
            return -1;
        }
        string = string->next;
    }
    return string->chr;
}

String *String_GetOByIndex(String *string,Int index){
    string = String_Get_Head(string);
    for(index;index;--index){
        if(string->next==NULL){
            return -1;
        }
        string = string->next;
    }
    return string;
}

String *String_GetOByEIndex(String *string,Int index){
    for(index;index;--index){
        if(string->next==NULL){
            return -1;
        }
        string = string->next;
    }
    return string;
}

Int String_Lenth(String *string){
    string = String_Get_Head(string);
    Int Range = 0;
    while(string->next!=NULL){
        Range++;
        string = string->next;
    }
    return Range;
}

Int String_Compare(String *string,Char *comparement,Int size){
    Int range = 0;
    string = String_Get_Head(string);
    if(String_Lenth(string)>size){
        return -1;
    }else if(String_Lenth(string)<size){
        return -1;
    }else{
        while(string->next!=NULL){
            if(string->chr==comparement[range]){
                string = string->next;
                range++;
                continue;
            }else{
                return -1;
            }
        }
    }
    return 0;
}
#endif