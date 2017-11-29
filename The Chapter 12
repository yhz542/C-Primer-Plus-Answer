//problem one

#include<stdio.h>
int critic(int);
int main(void)
{
        int units=0;
        printf("How many pounds to a firkin of butter?\n");
        scanf("%d",&units);
        while(units!=56)
                units=critic(units);
        printf("You must have looked it up!\n");
        return 0;
}
int critic(int units)
{
        printf("No luck,chummy,Try again.\n");
        scanf("%d",&units);
        return units;
}

//problem two
#include<stdio.h>
#include"pe12-2a.h"
int main(void)
{
        int mode;
        printf("Enter 0 for metric mode,1 for US mode:");
        scanf("%d",&mode);
        while(mode>=0)
        {
                set_mode(mode);
                get_info();
                show_into();
                printf("Enter 0 for metric mode,1 for US mode");
                printf("(-1 to quit):");
                scanf("%d",&mode);
        }
        printf("Done.\n");
        return 0;
}
#include<stdio.h>
#include<stdlib.h>
static int mode;
static int distance;
static float fuel;
void set_mode(int source_mode)
{
        mode=source_mode;
        return;
}
void get_info(void)
{
        switch(mode)
        {
                case 0:
                        printf("Enter distance traveled in kilometers:");
                        scanf("%d",&distance);
                        printf("Enter fuel consumed in liters:");
                        scanf("%f",&fuel);
                        break;
                case 1:
                        printf("Enter distance traveled in miles:");
                        scanf("%d",&distance);
                        printf("Enter fuel consumed in gallon:");
                        scanf("%f",&fuel);
                        break;
                case -1:
                        puts("Done.");
                        exit(0);
                        break;
                default:
                        puts("Invalid mode specified.Mode 1(US)");
                        if(mode>1)
                                mode=1;
                        else
                                mode=0;
                        get_info();
        }
}
void show_into(void)
{
        switch(mode)
        {
                case 0:
                        printf("Fuel consumption is %.2f liters per 100km.\n",fuel/distance*100);
                        break;
                case 1:
                        printf("Fuel consumption is %.1f miles per gallon.\n",distance/fuel);
                        break;
        }
}//头文件
void get_info(void);
void show_info(void);
void set_mode(int);

//problem three
#include<stdio.h>
#include<stdlib.h>
void get_info(int *,int *,float *);
void show_into(const int,const int *,const float *);
int main(void)
{
        int mode;
        int distance;
        float fuel;
        printf("Enter 0 for metric mode,1 for US mode:");
        scanf("%d",&mode);
        while(mode>=0)
        {
                get_info(&mode,&distance,&fuel);
                show_into(mode,&distance,&fuel);
                printf("Enter 0 for metric mode,1 for US mode");
                printf("(-1 to quit):");
                scanf("%d",&mode);
        }
        printf("Done.\n");
        return 0;
}
void get_info(int *mode,int *distance,float *fuel)
{
        switch(*mode)
        {
                case 0:
                        printf("Enter distance traveled in kilometers:");
                        scanf("%d",distance);
                        printf("Enter fuel consumed in liters:");
                        scanf("%f",fuel);
                        break;
                case 1:
                        printf("Enter distance traveled in miles:");
                        scanf("%d",distance);
                        printf("Enter fuel consumed in gallon:");
                        scanf("%f",fuel);
                        break;
                case -1:
                        puts("Done.");
                        exit(0);
                        break;
                default:
                        puts("Invalid mode specified.Mode 1(US)");
                        if(*mode>1)
                                *mode=1;
                        else
                                *mode=0;
                        get_info(mode,distance,fuel);
        }
}
void show_into(const int mode,const int *distance,const float *fuel)
{
        switch(mode)
        {
                case 0:
                        printf("Fuel consumption is %.2f liters per 100km.\n",*fuel/(*distance)*100);
                        break;
                case 1:
                        printf("Fuel consumption is %.1f miles per gallon.\n",*distance/(*fuel));
                        break;
        }
        return;
}

//problem four
#include<stdio.h>
#include<stdlib.h>
int count;
void iterator(void);
int main(void)
{
        iterator();
        return 0;
}
void iterator(void)
{
        count++;
        puts("count++");
        printf("%d\n",count);
        system("pause");
        iterator();
}

//preoblem five
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
        int array[100];
        int count=0;
        for(int i=0;i<=99;i++)
        {
                array[i]=rand()%10+1;
        }
        for(int i=0;i<100;i++)
                for(int j=i+1;j<100;j++)
                {
                        if(array[j]>array[i])
                        {
                                array[j]+=array[i];
                                array[i]=array[j]-array[i];
                                array[j]-=array[i];
                        }
                }
        for(int i=0;i<100;i++)
        {
                printf("%4d",array[i]);
                count++;
                if(count==10)
                {
                        putchar('\n');
                        count=0;
                }
        }
}

//problem six
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
        int array[1000];
        int number[10]={0};
        for(int i=1;i<11;i++)
        {
                srand(i);
                for(int j=0;j<1000;j++)
                        array[j]=rand()%10+1;
                printf("%d\n",array[0]);
                for(int k=0;k<1000;k++)
                {
                        for(int z=1;z<11;z++)
                        {
                                if(z==array[k])
                                        number[z-1]++;
                        }
                }
                for(int l=0;l<10;l++)
                        printf("%4d",number[l]);
                putchar('\n');
                for(int m=0;m<10;m++)
                        number[m]=0;
        }

        return 0;
}

//problem seven
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int time1(void);
void sides_dice(int *,int *);
int main(void)
{
        int dice=0,total=0,count=0;
        int sides=0;
        int times=0;
        srand((unsigned int)time(0));
        printf("Enter the number of sets:enter q to stop.");
        while(times=time1())
        {
                printf("How many sides and how many dice?\n");
                sides_dice(&sides,&dice);
                printf("Here are %d sets of %d %d-sided throws.\n",times,dice,sides);
                printf("  ");
                for(int i=1;i<=times;i++)
                {
                        count++;
                        if(count%15==0)
                                printf("\n  ");
                        for(int j=1;j<=dice;j++)
                                total+=rand()%sides+1;
                        printf("%3d",total);
                        total=0;
                }
                puts("\nHow many sets?Enter q to stop?");
        }
}
int time1(void)
{
        int status;
        int times;
        while((status=scanf("%d",&times))!=1||times<1)
        {
                if(status!=1)
                {
                        if(getchar()=='q')
                                exit(0);
                        else
                                scanf("%*s");
                }
                printf("Enter error!\n");
        }
        return times;
}
void sides_dice(int *sides,int *dice)
{
        while(scanf("%d %d",sides,dice)!=2||*sides<2||*dice<1)
                printf("Enter error!Please input again.\n");
}

//problem eight
#include<stdio.h>
#include<stdlib.h>
int *make_array(int elem,int val);
void show_array(const int ar[],int n);
int main(void)
{
        int *pa;
        int size;
        int value;
        printf("Enter the number of elements:");
        scanf("%d",&size);
        while(size>0)
        {
                printf("Enter the initialization value:");
                scanf("%d",&value);
                pa=make_array(size,value);
                if(pa)
                {
                        show_array(pa,size);
                        free(pa);
                }
                printf("Enter the number of elements(<1 to quit):");
                scanf("%d",&size);
        }
        printf("Done.\n");
        return 0;
}
int *make_array(int elem,int val)
{
        int *pt;
        pt=(int *)malloc(elem*sizeof(int));
        for(int i=0;i<elem;i++)
                pt[i]=val;
        return pt;
}
void show_array(const int ar[],int n)
{
        int count=0;
        for(int i=0;i<n;i++)
        {
                printf("%d ",ar[i]);
                count++;
                if(count%10==0)
                        putchar('\n');
        }
        return;
}
