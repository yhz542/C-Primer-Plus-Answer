#include <stdio.h>
int min(int,int);
int main(void)//question one
{
        int a,b;
        printf("Please enter two number to compare the smaller one.\n");
        scanf("%d%d",&a,&b);
        printf("the smaller one is %d",exchange(a,b));
        return 0;
}
int min(int a,int b)
{
        return a>b?b:a;
}
void chline(char,int,int);//question two
int main(void)
{
        int i,j;
        char ch;
        scanf("%d%d\n%c",&i,&j,&ch);
        chline(ch,i,j);
        return 0;
}
void chline(char ch,int i,int j)
{
        for(int k=1;k<=i;k++)
        {
                putchar(' ');
        }
        while(i<=j)
        {
                putchar(ch);
                i++;
        }
}
void function(char,int,int);//question three
int main(void)//question three
{
        char ch;
        int a,b;
        printf("please enter the character you want to output and the number of row output,the number of output per row:\n");
        scanf("%d %d\n%c",&a,&b,&ch);
        function(ch,a,b);
        return 0;
}
void function(char ch,int a,int b)
{
        for(int i=1;i<=b;i++)
        {
                for(int j=1;j<=a;j++)
                        putchar(ch);
                putchar('\n');
        }
}
double calculate(double,double);
int main(void)//question four
{
        double a,b;
        scanf("%lf",&a);
        scanf("%lf",&b);
        printf("a=%f,b=%f\n",a,b);
        printf("%f",calculate(a,b));
        return 0;
}
double calculate(double a,double b)
{
        double average;
        printf("1/a=%f 1/b=%f and sum=%f\n",1/a,1/b,1/a+1/b);
        average=((1/a)+(1/b))/2;
        average=1/average;
        return average;
}

//question five
void larger_of(int *x,int *y);
int main(void)
{
        int x,y;
        scanf("%d%d",&x,&y);
        larger_of(&x,&y);
        printf("%d %d",x,y);
        return 0;
}
void larger_of(int *x,int *y)
{
        if(*x>=*y)
                *y=*x;
        else
                *x=*y;
        return;
}
//question six
#include<ctype.h>
int main(void)
{
        char ch;
        while((ch=getchar())!=EOF)
        {
                if(isalpha(ch))
                        printf("the position of alphabet %c is in %d\n",ch,ch<='Z'?ch-'A'+1:ch-'a'+1);
        }
        return 0;
}
//question seven
double power(double n,int p);
int main(void)
{
        double x,xpow;
        int exp;
        printf("Enter a number and the positive integer power");
        printf("to which\n the number will be raised.Enter q");
        printf("to quit.\n");
        while(scanf("%lf%d",&x,&exp)==2)
        {
                xpow=power(x,exp);
                printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
                printf("Enter next pair of numbers or q to quit.\n");
        }
        printf("Hope you enjoyed this power trip -- bye!\n");
        return 0;
}
double power(double n,int p)
{
        double result=1;
        if(n==0)
                result=0;
        else if(p==0)
                result= 1;
        else if(p<0)
        {
                p=-p;
                for(int i=1;i<=p;i++)
                        result*=n;
                result=1/result;
        }
        else
                for(int i=1;i<=p;i++)
                        result*=n;
        return result;
}
//recursiom solution
double power(double n,int p);
int main(void)
{
        double result,n;
        int p;
        printf("please enter a number and its power.\n");
        scanf("%lf %d",&n,&p);
        result=power(n,p);
        printf("the result is %f.\n",result);
        return 0;
}
double power(double n,int p)
{
        printf("%d\n",p);
        return p==1?n:power(n,p-1)*n;
}

//question eight
double power(double n,int p);
int main(void)
{
        double x,result;
        int p;
        printf("Enter a number and the positive integer power");
        printf("to which the number will be raised.Enter q");
        printf(" to quit.\n");
        while(scanf("%lf%d",&x,&p)==2)
        {
                result=power(x,p);
                printf("%.3g to the power %d is %.5g\n",x,p,result);
                printf("Enter next pair of numbers or q to quit.\n");
        }
        printf("Hope you enjoyed this power trip -- bye!\n");
        return 0;
}
double power(double n,int p)
{
        if(n!=0&&p!=0)
                if(p>0)
                        return p==1?n:power(n,p-1)*n;
                else
                        return p==-1?(1/n):power(n,p+1)*(1/n);
        else if(n==0)
                return 0;
        else
                return 1;
}
//question nine
void to_binary(unsigned long n,unsigned p);
int main(void)
{
        unsigned long number;
        unsigned p;
        printf("Enter an integer(q to quit):\n");
        while(scanf("%lu %u",&number,&p)==2)
        {
                printf("Binary equivalent:");
                to_binary(number,p);
                putchar('\n');
                printf("Enter an integer(q to quit):\n");
        }
        printf("Done.\n");
        return 0;
}
void to_binary(unsigned long n,unsigned p)
{
        unsigned r;
        r=n%p;
        if(n>=p)
                to_binary(n/p,p);
        printf("%u",r);
        return;
}
//question ten
long Fibonacci(int n);
int main(void)
{
        int n,result;
        printf("Please enter a number to calculate Fibonacci:\n");
        scanf("%d",&n);
        result=Fibonacci(n);
        printf("%d\n",result);
        return 0;
}
long Fibonacci(int n)
{
        int former=1,latter=1,result;
        if(n<=2)
                result=1;
        else
                for(int j=3;j<=n;j++)
                {
                        result=former+latter;
                        former=latter;
                        latter=result;
                }
        return result;
}
