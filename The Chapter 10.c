#include<stdio.h>
#define MONTHS 12 question one
#define YEARS 5
int main(void)
{
        const float rain[YEARS][MONTHS]={{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
                                        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
                                        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
                                        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
                                        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}};
        int year,month;
        float subtot,total;
        const float (*pointer)[MONTHS];
        pointer=rain;
        printf("YEAR  RAINFALL(inches)\n");
        for(year=0,total=0;year<YEARS;year++)
        {
                for(subtot=0,month=0;month<MONTHS;month++)
                {
                        subtot+=pointer[year][month];
                }
                printf("%5d%15.1f\n",2000+year,subtot);
                total+=subtot;
        }
        printf("The yearly average is %.1f inches.\n\n",total/YEARS);
        printf("MONTHLY AVERAGES:\n\n");
        printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
        printf(" Nov Dec\n");
        for(month=0;month<MONTHS;month++)
        {
                for(year=0,subtot=0;year<YEARS;year++)
                        subtot+=*(*(pointer+year)+month);
                printf("%.1f ",subtot/YEARS);
        }
        printf("\n");
        return 0;
}
//question two
void copy_arr(double [],double [],int length);
void copy_ptr(double [],double [],int length);
int main(void)
{
        double source[5]={1.1,2.2,3.3,4.4,5.5};
        double target1[5],target2[5];
        copy_arr(source,target1,5);
        copy_ptr(source,target2,5);
        for(int i=0;i<5;i++)
                printf("%.1f %.1f %.1f\n",*(source+i),target1[i],target2[i]);
        return 0;
}
void copy_arr(double source[],double copy[],int length)
{
        for(int i=0;i<length;i++)
                copy[i]=source[i];
}
void copy_ptr(double source[],double *copy,int length)
{
        for(int i=0;i<length;i++)
                *(copy+i)=*(source+i);
}
//question three
int contrast(int [],int);
int main(void)
{
        int array[10]={1,2,3,4,5,6,7,8,9,10};
        int max=contrast(array,10);
        printf("The max is %d",max);
        return 0;
}
int contrast(int array[],int length)
{
        int max=array[0];
        for(int i=0;i<length;i++)
                if(max<array[i])
                        max=array[i];
        return max;
}
//question four
int index(double [],int);
int main(void)
{
        double array[5]={1.2,9.3,0.1,5.5,6.6};
        printf("the max's index is %d",index(array,5));
        return 0;
}
int index(double array[],int length)
{
        int index_max=0;
        double max=array[0];
        for(int i=0;i<length;i++)
                if(max<array[i])
                {
                        max=array[i];
                        index_max=i;
                }
        return index_max;
}
//question five
double difference(double [],int length);
int main(void)
{
        double array[10]={2,5,1,8,9,10,111,3,90};
        printf("the difference between the max and the min is %g.\n",difference(array,10));
        return 0;
}
double difference(double array[],int length)
{
        double max=array[0],min=array[0];
        for(int i=0;i<length;i++)
        {
                if(array[i]>max)
                        max=array[i];
                else if(array[i]<min)
                        min=array[i];
                printf("the max is %g,and the min is %g\n",max,min);
        }

        return max-min;
}
//question six
void copy_arr(double [][3],double [][3],int);
int main(void)
{
        double two_d[3][3]={{1.1,2.2,3.3},{0.1,0.2,0.3},{11.1,11.2,11.}};
        double copy[3][3];

        copy_arr(two_d,copy,3);
        for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                        printf("array[%d][%d]=%g and %g\n",i,j,two_d[i][j],*(*(copy+i)+j));
        return 0;
}
void copy_arr(double source[][3],double copy[][3],int length)
{
        for(int i=0;i<length;i++)
                for(int j=0;j<3;j++)
                        copy[i][j]=source[i][j];
        return;
}
//question seven
void copy_arr(double [],double [],int length);
void copy_ptr(double [],double [],int length);
int main(void)
{
        double source[7]={1.1,2.2,3.3,4.4,5.5,6.6,7.7};
        double target1[3],target2[3];
        copy_arr(source+2,target1,3);
        copy_ptr(source+2,target2,3);
        for(int i=0;i<3;i++)
                printf("%.1f %.1f %.1f\n",*(source+i),target1[i],target2[i]);
        return 0;
}
void copy_arr(double source[],double copy[],int length)
{
        for(int i=0;i<length;i++)
                copy[i]=source[i];
}
void copy_ptr(double source[],double *copy,int length)
{
        for(int i=0;i<length;i++)
                *(copy+i)=*(source+i);
}
//question eight
void copy(int rows,int cols,double [rows][cols],double [rows][cols]);
void display(int rows,int cols,double [][cols]);
int main(void)
{
        double array[3][5]={{1,2,3,4,5},{6,7,8,9,0},{0,8,6,4,2}};
        double faker[3][5];
        copy(3,5,array,faker);
        display(3,5,array);
        display(3,5,faker);
        return 0;
}
void copy(int rows,int cols,double array[rows][cols],double faker[rows][cols])
{
        for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                        faker[i][j]=array[i][j];
        return;
}
void display(int rows,int cols,double array[][cols])
{
        for(int i=0;i<rows;i++)
        {
                for(int j=0;j<cols;j++)
                {
                        printf("%g ",*(*(array+i)+j));
                }
                putchar('\n');
        }
        return;
}

//question nine
void calculate(int [],int [],int [],int);
void display(int *,int);
int main(void)
{
        int a[5]={1,2,3,4,5};
        int b[5]={6,7,8,9,0};
        int c[5];
        calculate(a,b,c,5);
        display(c,5);
        return 0;
}
void calculate(int a[],int b[],int c[],int length)
{
        for(int i=0;i<length;i++)
                c[i]=b[i]+a[i];
        return;
}
void display(int *a,int length)
{
        for(int i=0;i<length;i++)
                printf("%d ",*(a+i));
        return;
}
//question ten
void display(int [][5],int);
void square(int [][5],int);
int main(void)
{
        int a[3][5]={{1,2,3,4,5},{2,4,6,8,0},{1,3,5,7,9}};
        display(a,3);
        square(a,3);
        display(a,3);
        return 0;
}
void display(int array[][5],int length)
{
        for(int i=0;i<length;i++)
        {
                for(int j=0;j<5;j++)
                        printf("%d ",array[i][j]);
                putchar('\n');
        }
        return;
}
void square(int array[][5],int length)
{
        for(int i=0;i<length;i++)
                for(int j=0;j<5;j++)
                        array[i][j]=array[i][j]*array[i][j];
        return;
}
//question eleven
#define MONTHS 12
#define YEARS 5
void all(const float [][MONTHS]);
void suball(const float [][MONTHS]);
int main(void)
{
        const float rain[YEARS][MONTHS]={{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
                                        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
                                        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
                                        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
                                        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}};
        all(rain);
        suball(rain);
        return 0;
}
void all(const float array[][MONTHS])
{
        int year,month;
        float subtot,total;
        printf("YEAR  RAINFALL(inches)\n");
        for(year=0,total=0;year<YEARS;year++)
        {
                for(subtot=0,month=0;month<MONTHS;month++)
                {
                        subtot+=array[year][month];
                }
                printf("%5d%15.1f\n",2000+year,subtot);
                total+=subtot;
        }
        printf("The yearly average is %.1f inches.\n\n",total/YEARS);
}
void suball(const float array[][MONTHS])
{
        int year,month;
        float subtot;
        printf("MONTHLY AVERAGES:\n\n");
        printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct");
        printf(" Nov Dec\n");
        for(month=0;month<MONTHS;month++)
        {
                for(year=0,subtot=0;year<YEARS;year++)
                        subtot+=*(*(array+year)+month);
                printf("%.1f ",subtot/YEARS);
        }
        printf("\n");
}
//question twelve
void store(double [],double [],double [],double [][5],int rows);
double aver_per(double [],int length);
double aver_all(double [][5],int rows);
double max_search(double [][5],int rows);
void display(double [][5],double [],double,double);
int main(void)
{
        double a[5],b[5],c[5],aver_p[3];
        double array[3][5];
        double aver_a,max;
        printf("Please enter 3 number sets(every set contains 5 number):\n");
        printf("The first set:\n");
        for(int i=0;i<5;i++)
                scanf("%lf",a+i);
        for(int i=0;i<5;i++)
                scanf("%lf",b+i);
        for(int i=0;i<5;i++)
                scanf("%lf",c+i);
        store(a,b,c,array,3);
        for(int i=0;i<3;i++)
        {
                aver_p[i]=aver_per(array[i],5);
        }
        aver_a=aver_all(array,3);
        max=max_search(array,3);
        display(array,aver_p,aver_a,max);
        return 0;
}
void store(double a[],double b[],double c[],double array[][5],int rows)
{
        for(int i=0;i<5;i++)
                array[0][i]=a[i];
        for(int i=0;i<5;i++)
                array[1][i]=b[i];
        for(int i=0;i<5;i++)
                array[2][i]=c[i];
        return;
}
double aver_per(double array[],int length)
{
        double total=0;
        for(int i=0;i<length;i++)
                total+=array[i];
        return total/length;
}
double aver_all(double array[][5],int rows)
{
        double total=0;
        for(int i=0;i<rows;i++)
                for(int j=0;j<5;j++)
                        total+=array[i][j];
        return total/15;
}
double max_search(double array[][5],int rows)
{
        double max=array[0][0];
        for(int i=0;i<rows;i++)
                for(int j=0;j<5;j++)
                {
                        if(max<array[i][j])
                                max=array[i][j];
                }
        return max;
}
void display(double array[][5],double aver[],double aver_all,double max)
{
        for(int i=0;i<3;i++)
        {
                for(int j=0;j<5;j++)
                        printf("%g ",array[i][j]);
                putchar('\n');
        }
        for(int i=0;i<3;i++)
                printf("the average of %d set is %f.\n",i,aver[i]);
        printf("the average of all number is %f\n",aver_all);
        printf("and the max is %f",max);
        return;
}

//question thirteen
void store(int length,double [],double [],double [],double [][length],int rows);
double aver_per(double [],int length);
double aver_all(int length,double [][length],int rows);
double max_search(int length,double [][length],int rows);
void display(int length,double [][5],double [],double,double);
int main(void)
{
        double a[5],b[5],c[5],aver_p[3];
        double array[3][5];
        double aver_a,max;
        printf("Please enter 3 number sets(every set contains 5 number):\n");
        printf("The first set:\n");
        for(int i=0;i<5;i++)
                scanf("%lf",a+i);
        for(int i=0;i<5;i++)
                scanf("%lf",b+i);
        for(int i=0;i<5;i++)
                scanf("%lf",c+i);
        store(5,a,b,c,array,3);
        for(int i=0;i<3;i++)
        {
                aver_p[i]=aver_per(array[i],5);
        }
        aver_a=aver_all(5,array,3);
        max=max_search(5,array,3);
        display(5,array,aver_p,aver_a,max);
        return 0;
}
void store(int length,double a[],double b[],double c[],double array[][5],int rows)
{
        for(int i=0;i<5;i++)
                array[0][i]=a[i];
        for(int i=0;i<5;i++)
                array[1][i]=b[i];
        for(int i=0;i<5;i++)
                array[2][i]=c[i];
        return;
}
double aver_per(double array[],int length)
{
        double total=0;
        for(int i=0;i<length;i++)
                total+=array[i];
        return total/length;
}
double aver_all(int length,double array[][length],int rows)
{
        double total=0;
        for(int i=0;i<rows;i++)
                for(int j=0;j<5;j++)
                        total+=array[i][j];
        return total/15;
}
double max_search(int length,double array[][length],int rows)
{
        double max=array[0][0];
        for(int i=0;i<rows;i++)
                for(int j=0;j<5;j++)
                {
                        if(max<array[i][j])
                                max=array[i][j];
                }
        return max;
}
void display(int length,double array[][length],double aver[],double aver_all,double max)
{
        for(int i=0;i<3;i++)
        {
                for(int j=0;j<5;j++)
                        printf("%g ",array[i][j]);
                putchar('\n');
        }
        for(int i=0;i<3;i++)
                printf("the average of %d set is %f.\n",i,aver[i]);
        printf("the average of all number is %f\n",aver_all);
        printf("and the max is %f",max);
        return;
}
