//
// Created by root on 23-7-15.
//
#include <stdio.h>

int main(){

      int tx=-8 ,ty=10;
      unsigned int ux,uy;
      ux = tx;
      uy = ty;
      printf("%u\n",ux); // 4294967288
      printf("%u\n",uy);
//
//
//      unsigned int a =6;
//      int b = -20;
//      (a+b)>6 ? printf(">6\n"): printf("<6\n"); // >6


//      unsigned int i = 3;
//      printf("%d\n",i* -1);
//      printf("%u\n",i* -1);
//      int j = i* -1;
//      printf("%d\n",j);
//      printf("%d\n",i* -1);

//      unsigned i ;
//      int n =10;
//
//      for(i=n-1;i>=0;i--){
//              printf("%u\n",i);
//              sleep(1);
//      }

    unsigned a = 10;
    int  b =20;
    long c =10;
    char d ='a';
    short e =3;
    printf("%ld\n",a|b|c|d|e);


//    int lval =0xfedcba98 << 32;
//    int aval =0xfedcba98 >>  36;
//    unsigned uval =0xfedcba98 >>  40;
//
//    printf("%d\n",lval);
//    printf("%d\n",aval);
//    printf("%u\n",uval);
//
//
//    long l = ~0;   // 0000..000 to 1111..11
//    printf("%ld\n",l);


    printf("%d \n", -12340>>1);
    printf("%d \n", -12340>>4);
    printf("%d \n", -12340>>8);


    printf("%d \n", (-12340+ (1<<4-1))>>4);
    printf("%d \n", (-12340+ (1<<8-1))>>8);




    return 0;
}
