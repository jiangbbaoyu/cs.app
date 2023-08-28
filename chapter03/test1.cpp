//
// Created by root on 23-8-19.
//
#include <stdio.h>

struct S2{
    short i;
    short j;
    float k;
};

struct S3{
    short i;
    float j;
    short k;
};

int var_ele(int n, int arr[n+10],int j){
    return arr[j];
}

int main(){
    int a1[3];
    int *a2;
//    printf("size of a1 %d\n",sizeof(a1));
//    printf("%d\n",a1[0]); // init randomly
//    printf("%d\n",a1[1]);
//
//    printf("size of a2 %d\n",sizeof(a2));
//    printf("%d\n",a2);
////    printf("%d\n",*a2);
//
//
//
//
//    printf("size of s2: %u \n",sizeof (S2));
//    printf("size of s3:s3 %u \n",sizeof (S3));
    S3 s;

    printf("%p\n",&a1[2]);
    printf("%p\n",a1);

    printf("%d\n",&a1[2]-a1);
    int n=10;
    int a4[n];
    var_ele(10,a4,1);
}
