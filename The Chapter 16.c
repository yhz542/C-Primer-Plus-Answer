
//question two
#include<stdio.h>
#define AVG(X,Y) (1/(((1/X)+(1/Y))/2))
int main(void)
{
        double a=1.,b=1.;
        printf("%f",AVG(a,b));
        return 0;
}
//question three
#include<stdio.h>
#include<math.h>
struct vector{
        double length;
        double angle;
};
struct coordinate{
        double x;
        double y;
};
struct coordinate zuobiao(struct vector);
int main(void)
{
        struct vector rough;
        struct coordinate dealed;
        printf("Please enter the length and angle:\n");
        scanf("%lf %lf",&rough.length,&rough.angle);
        dealed=zuobiao(rough);
        printf("The coordinate of x and y are respective %f %f",dealed.x,dealed.y);
        return 0;
}
struct coordinate zuobiao(struct vector rough)
{
        struct coordinate dealed;
        dealed.x=rough.length*cos(rough.angle);
        dealed.y=rough.length*sin(rough.angle);
        return dealed;
};
//question four
#include <stdio.h>
#include <time.h>
void delay(double time);
int main(void)
{
        double time;
        printf("clock per second is %d",CLOCKS_PER_SEC);
        puts("please enter the time of running:");
        scanf("%lf",&time);
        delay(time);
        return 0;
}
void delay(double time)
{
        double start;
        start=clock();
        double num=0;
        while(((double)clock()-start)/CLOCKS_PER_SEC<time);
        return;
}
//question five
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void somefunction(int [],int,int);
int main(void)
{
        int size;
        scanf("%d",&size);
        int array[size];
        int times;
        scanf("%d",&times);
        for(int i=0;i<size;i++)
                array[i]=i;
        srand((unsigned int)time(0));
        somefunction(array,size,times);
        return 0;
}
void somefunction(int array[],int size,int times)
{
        int num;
        while(times--)
        {
                num=rand()%size;

        }
        return;
}
//question six
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 5
struct names{
        char first[40];
        char last[40];
};
void shownames(struct names *,int n);
int comp(const void *p1,const void *p2);
int main(void)
{
        struct names staff[NUM]={
                {       "Hongzhi","Yao"},
                {        "Hou","Ding"},
                {       "Zipeng","Chang"},
                {       "Xianbing","Ke"},
                {       "Zewen","Li"}
        };
        puts("Initial list:");
        shownames(staff,NUM);
`        qsort(staff,NUM,sizeof(struct names),comp);
        puts("\nSorted list:");
        shownames(staff,NUM);
        return 0;
}
void shownames(struct names *ptr,int n)
{
        int index;
        for(index=0;index<n;index++)
        {
                printf("%s %s\n",ptr[index].first,ptr[index].last);
        }
}
int comp(const void *p1,const void *p2)
{
        const struct names *ps1=(const struct names *)p1;
        const struct names *ps2=(const struct names *)p2;
        int res;
        res=strcmp(ps1->last,ps2->last);
        if(res!=0)
                return res;
        else
                return strcmp(ps1->first,ps2->first);
}
//question seven
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
void show_array(const double ar[],int n);
double * new_d_array(int n,...);
int main(void)
{
        double *p1;
        double *p2;
        p1=new_d_array(5,1.2,2.3,3.4,4.5,5.6);
        p2=new_d_array(4,100.0,20.00,8.08,-1890.0);
        show_array(p1,5);
        show_array(p2,4);
        free(p1);
        free(p2);
        return 0;
}
double * new_d_array(int n,...)
{
        va_list all;
        double *ptr;
        ptr=(double *)malloc(n*sizeof(double));
        int i;
        va_start(all,n);
        for(i=0;i<n;i++)
                ptr[i]=va_arg(all,double);
        va_end(all);
        return ptr;
}
void show_array(const double ar[],int n)
{
        for(int i=0;i<n;i++)
                printf("%f ",ar[i]);
        putchar('\n');
        return;
}

