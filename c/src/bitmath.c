/*
                       BRIEF LICENCE OVERVIEW
                        (modified GPL V3.0)
This library is created by Rishabh. It is an open source library. Under the
licence of GPL v3.0, you can contribute, modify and re-distribute the library for free
under the same licence. For contributing in this library(repository),
visit this github link:
*/



#include <stdarg.h>

/*
------------------------------------------------------------------------------------------
This is a library for doing basic arithematic operations using logic gates
only. This library shows how can you use logic gates for elliminating the work
of arithematic operators like '+','-',etc.

You can also use it realise half adder, half substracter,etc. like circuits.

To use functions of this library in your project, first copy this file in your project
folder and then write following code in top of your C Source code:
#include "bitmath.c"
-------------------------------------------------------------------------------------------
*/








/*
This is a function that adds two numbers without use of + operator.
This is similar of to half adder except it can add any bit number in range of integer.
*/
int addTwo(int x,int y){
  while(y!=0){
    int carry = x&y;
    x=x^y;      //making x as x(xor)y
    y=carry<<1; //Shfts bits of carry by 1 in left so that carry will be added where it requires to be.
  }
  return x;
}




/*
This is a function that adds any number of numbers without use of + operator.
This is similar of to full adder.
Usage: In this function any number of arguments can be given.
       eg: add(2,3,4)  ,  add(4,3,4,2,2)
       We have to take care that the first argument is the number of arguments
       we are going to give next to the function. So full adder will start
       working from second argument. For correct result first argument must be
       correct.
*/
int add(int num,...){
  register int sum =0;
  register int i=0;
  va_list numbers;
  va_start(numbers,num);
  for(i=0;i<num;i=addTwo(i,1)){
    sum = addTwo(sum,va_arg(numbers,int));
  }
  va_end(numbers);
  return sum;
}





/*
This is function that substract two numbers as: n1-n2 without use of - operator.
This is similar to half substracter except it can substract any bit numbers
that are in range of int.
*/
int substractTwo(int n1,int n2){
  while(n2!=0){
    int borrow = ~n1&n2;
    n1 = n1^n2;
    n2 = borrow<<1;
  }
  return n1;
}





/*
This is a function that substracts any number of numbers without use of - operator.
This is similar of to full substractor.
Its substraction methodolgy is like: n1-n2-n3-n4-n5....
Usage: In this function any number of arguments can be given.
       eg: substract(2,3,4)  ,  substract(4,3,4,2,2)
       We have to take care that the first argument is the number of arguments
       we are going to give next to the function. So full substracter will start
       working from second argument. For correct result first argument must be
       correct.
*/
int substract(int num,...){
  register int sum =0;
  register int i=0;
  va_list numbers;
  va_start(numbers,num);
  for(i=0;i<num;i=addTwo(i,1)){
    if(i==0) sum = substractTwo(va_arg(numbers,int),sum);
    else sum = substractTwo(sum,va_arg(numbers,int));
  }
  va_end(numbers);
  return sum;
}
