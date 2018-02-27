#include <stdio.h>
int foo(int i) {
 return i+1;   
}

int end(int x)
{
    int a,b,c,d,e,f;
   printf("end x=%d\n",x);
   a=b=c=d=e=f=x;
}

int g;
int main()  {
int a=foo(3);
g=foo(a);
printf("function foo() a=%d g=%d\n",a,g);
printf("second line\n");
printf("third line\n");
printf("fourth line\n");
printf("fifth line\n");
printf("Master commit\n");
printf("Develop Branch\n");
printf("Develop Branch1\n");
printf("Develop commit\n");
printf("foo\n");
printf("try to merge\n");
printf("try to merge to master\n");
printf("Master Branch\n");
end(g);
}

