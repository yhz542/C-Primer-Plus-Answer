#include<stdio.h>//第八章习题答案
#include<ctype.h>
#include<stdbool.h>
#include<stdlib.h>
int main(void)
{
        char ch;
        int count_big=0,count_small=0;
        while((ch=getchar())!=EOF)
        {
                if(islower(ch))
                {
                        count_small++;
                }
                else if(isupper(ch))
                        count_big++;
        }
        printf("there are %d %s and %d %s",count_small,(count_small==0||count_small==1)?"lowercase":"lowercases",count_big,
        (count_big==0||count_big==1)?"uppercase":"uppercases");
        return 0;
}
//http://blog.csdn.net/luhuisicnu/article/details/45725221
int main(void)
{
        char ch;
        int count_big=0,count_small=0;
        while((ch=getchar())!=EOF)
        {
                if(ch>='a'&&ch<='z')
                        count_small++;
                else if(ch>='A'&&ch<'Z')
                        count_big++;
        }
        printf("there are %d %s and %d %s",count_small,(count_small==0||count_small==1)?"lowercase":"lowercases",count_big,
        (count_big==0||count_big==1)?"uppercase":"uppercases");
        return 0;
}
int main(void)//两种思路 第一种设置在单词内的布尔逻辑数作为状态 第二种设置前一个字符，将当前字符输入和前一个字符输入做比较
{
        int n_word=0,n_ch=0,count=0;
        char ch;
        bool inword=false;
        while((ch=getchar())!=EOF)
        {
                if((isalnum(ch)))
                {
                        if(!inword)
                        {
                                inword=true;
                                n_word++;
                                n_ch++;
                        }
                        else
                                n_ch++;
                }
                else if(inword)
                {
                        inword=false;
                }
        }
        printf("the number of words is %d and the number of character is %d",n_word,n_ch);
        printf("the average of character of per words is %f",(float)n_ch/n_word);
        return 0;
}
#define MAX 100
#define MIN 1
int get_num(void);
char get_answer(void);
void binary_search(int num,char answer);
int main(void)
{
        int number;
        char answer;
        while(1)
        {
                number=get_num();
                answer=get_answer();
                binary_search(number,answer);
                printf("oh,I'm the best!\n");
        }

        return 0;
}
int get_num(void)
{
        int number;
        char isq;
        while(1)
        {
                printf("please input a number:(q to quit)\n");
                if(scanf("%d",&number)!=1)
                {
                        if((isq=getchar())=='q'||isq=='Q')
                        {
                                printf("Good bye!\n");
                                exit(0);
                        }
                        else
                                printf("error input!please input again!\n");
                }
                else if(number<=MAX&&number>=MIN)
                {
                        while(getchar()!='\n');
                        break;
                }
                else
                        printf("The number should be limited 1 to 100.\n");
                while(getchar()!='\n');
        }
        return number;
}
char get_answer(void)
{
        char answer;
        while(1)
        {
                printf("Is the number bigger smaller or yes?\n");
                printf("please reply by using B,S or Y.\n");
                answer=getchar();
                if(answer=='Y'||answer=='y'||answer=='B'||answer=='b'||answer=='s'||answer=='S')
                {
                        while(getchar()!='\n');
                        break;
                }
                else if(answer=='q'||answer=='Q')
                {
                        printf("Good bye!\n");
                        exit(0);
                }
                else
                        printf("input error!please input again.\n");
                while(getchar()!='\n');
        }
        return answer;
}
void binary_search(int num,char answer)
{
        int upper_limit=MAX,lower_limit=MIN;
        while(answer!='Y'&&answer!='y')
        {
                if(answer=='B'||answer=='b')
                        upper_limit=num;
                else
                        lower_limit=num;
                num=(upper_limit+lower_limit)/2;
                printf("The number is %d?\n",num);
                answer=get_answer();
        }

}
char get_first(void);
int main(void)
{
        return 0;
}
char get_first(void)
{
        char ch;
        while(1)
        {
                ch=getchar();
                if(isspace(ch))
                        continue;
                else
                {
                        while(getchar()!='\n');
                        break;
                }
        }
        return ch;
}
void display(void);
char get_first(void);
int main(void)
{
        char option;
        display();
        while(1)
        {
        option=get_first();
        printf("%c\n",option);
        }
        return 0;
}
void display(void)
{
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n");
        printf("a)$8.75/hr                      b)$9.33/hr\n");
        printf("c)$10.00/hr                     d)$11.20/hr\n");
        printf("q)quit\n");
        printf("*****************************************************************\n");
}
char get_first(void)
{
        char option;
        while(1)
        {
                option=getchar();                switch(option)
                {
                        case 'a':
                                while(getchar()!='\n');
                                return option;
                        case 'b':
                                while(getchar()!='\n');
                                return option;
                        case 'c':
                                while(getchar()!='\n');
                                return option;                        case 'd':
                                while(getchar()!='\n');
                                return option;
                        case 'q':
                                exit(0);
                }
        }
}
void display(void);
char getletter(void);
float get_num(void);
float calculate(float a,float b,char symbol);
int main(void)//第8题
{
        char symbol;
        float a,b,end;
        display();
        symbol=getletter();
        while(1)
        {
                printf("Enter first number:");
                a=get_num();
                printf("Enter second number:");
                b=get_num();
                end=calculate(a,b,symbol);
                printf("result is %f",end);
        }
        return 0;
}
void display(void)
{
        printf("Enter the operation of your choice:\n");
        printf("a.add           s.subtract\n");
        printf("m.multiply      d.divide\n");
        printf("q.quit\n");
}
char getletter(void)//获取字母
{
        char ch;
        while((ch=getchar())!='q'||ch!='Q')//按Q退出输入程序，如过必须获得输入改为while(1)
        {
                while(getchar()!='\n');
                if(ch=='a'||ch=='s'||ch=='m'||ch=='d')
                {
                        return ch;
                }
                else
                {
                        printf("Input error!Please input again!\n");
                        continue;
                }
        }
        printf("Goof bye!\n");
        exit(0);
}
float get_num(void)
{
     float num;
     char ch;
     while(1)
     {
                if(scanf("%f",&num))
                {
                        while(getchar()!='\n');
                        break;
                }
                else
                {
                        while((ch=getchar())!='\n')
                                putchar(ch);
                        printf(" is not an number.");
                }
     }
     return num;
}
float calculate(float a,float b,char symbol)
{
        float end;
        switch(symbol)
        {
                case 'a':
                        end=a+b;
                        break;
                case 's':
                        end=a-b;
                        break;
                case 'm':
                        end=a*b;
                        break;
                case 'd':
                        end=a/b;
        }
        return end;
}
