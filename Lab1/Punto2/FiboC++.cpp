#include<stdlib.h>
#include<stdio.h>

int fiboInt(int n){

    int a=0,b=1,fibonacci;
    do{
        fibonacci=a+b;
        a=b;
        b=fibonacci;
        n--;
    }while(n>1);
    return fibonacci;
}

short fiboShort(int n){

    short a=0,b=1,fibonacci;
    do{
        fibonacci=a+b;
        a=b;
        b=fibonacci;
        n--;
    }while(n>1);
    return fibonacci;
  //Overflow produced at 24th value
}

long fiboLong(int n){

    long a=0,b=1,fibonacci;
    do{
        fibonacci=a+b;
        a=b;
        b=fibonacci;
        n--;
    }while(n>1);
    return fibonacci;
  //Overflow produced at 93th value
}

long long fiboLongLong(int n){

    long long a=0,b=1,fibonacci;
    do{
        fibonacci=a+b;
        a=b;
        b=fibonacci;
        n--;
    }while(n>1);
    return fibonacci;
  //Overflow produced at 93th value (Very strangely, at the same value as long)
}

int main(){

  for(int i=0;i<100;i++){
    printf("%d %lld\n",i ,fiboLongLong(i));
  }
}
