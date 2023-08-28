//
// Created by root on 23-8-27.
//
#include <stdio.h>
#define  BUF_SIZE 10
void good_echo(){
    char buff[BUF_SIZE];
    while(1){
        /*Returns a pointer to the string buffer if successful. Otherwise it returns NULL to indicate failure*/
        char* p = fgets(buff,BUF_SIZE,stdin);
        if (p==NULL){
            break;
        }
        printf("%s",buff);
    }
    return ;
}
int main(){
    good_echo();
}