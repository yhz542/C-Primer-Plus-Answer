#include<stdio.h>
#include<string.h>
#define SIZE 20
//problem one
void transfer(int,char *);
int main(void)
{
        int n;
        printf("How many characters do you want to input?\n");
        scanf("%d",&n);
        while(getchar()!='\n');
        puts("Please input characters:");
        char string[n+1];
        transfer(n,string);
        puts(string);
        return 0;
}
void transfer(int n,char *string)
{
        //for(int i=0;i<n;i++)
        //{
      //          *(string+i)=getchar();
      //  }
        fgets(string,n+1,stdin);
        return;
}
//problem two
void transfer(int n,char *string)
{
        char c;
        fgets(string,n+1,stdin);
        while((c=getchar())!=' '&&c!='\t'&&c!='\n')
        {
                string[n++]=c;
        }
        string[n]='\0';
        return;
}
//problem three
void read(char *);
int main(void)
{
        char p[10];
        read(p);
        puts(p);
        return 0;
}
void read(char p[])
{
        char c;
        while((c=getchar())==' '||c=='\n'||c=='\t');
        p[0]=c;
        while((c=getchar())!=' '&&c!='\n'&&c!='\t')
                *(++p)=c;
        return;
}
//problem four
char *search(const char *,char);
int main(void)
{
        char *p;
        p=search("abcdefg",'a');
        printf("%p %c %s",p,*p,p);
        return 0;
}
char *search(const char *p,char c)
{
        while(*p!=c&&*p!='\0')
        {
                p++;
        }
        if(*p=='\0')
                return NULL;
        else
                return p;
}
//problem five
int is_within(char,const char *);
int main(void)
{
        int a;
        a=is_within('h',"abcdefg");
        printf("%d",a);
        return 0;
}
int is_within(char c,const char *p)
{
        while(1)
        {
                if(c==*p)
                        return 1;
                else if(*p=='\0')
                        return 0;
                p++;
        }

}
//problem six
#define SIZE 30
char *knockoff(char *,const char*,int);
int main(void)
{
        char target[SIZE];
        char source[SIZE];
        while(1)
        {
                gets(source);
                knockoff(target,source,8);
                puts(target);
        }
        return 0;
}
char *knockoff(char *target,const char *source,int n)
{
        target[n-1]='\0';
        //for(int i=0;source[i]!='\0'&&i<n;i++)
              //  target[i]=source[i];
        for(int i=0;i<n;i++)
        {
                target[i]=source[i];
                if(source[i]=='\0')
                        break;
        }
        return target;
}
//problem seven
#define SIZE 30
char *string_in(const char *,const char *);
int main(void)
{
        char a[SIZE];
        char b[SIZE];
        char *c;
        while(1)
        {
                puts("Please input first string.");
                gets(a);
                puts("Enter second string.");
                gets(b);
                c=string_in(a,b);
                if(c==0)
                        printf("enter error");
                else
                        puts(c);
        }
        return 0;
}
char *string_in(const char *f,const char *s)
{
        char *c;
        int i=0;
        if(*f=='\0'&&*s=='\0')
                return f;
        while(*f!='\0')
        {
                if(*f==*(s+i))
                {
                        f++;
                        i++;
                }
                else
                {
                        f++;
                        i=0;
                }
                if(*(s+i)=='\0')
                        return f-i;
        }
        return NULL;
}
//problem eight
void converse(char *);
int main(void)
{
        char a[30];
        while(1)
        {
                gets(a);
                converse(a);
                puts(a);
        }
        return 0;
}
void converse(char *a)
{
        char c;
        int i=strlen(a)-1;
        int j=0;
        while(i!=j&&(j-i)!=1)
        {
                c=a[j];
                a[j]=a[i];
                a[i]=c;
                j++;
                i--;
        }
        return;
}
//problem nine
void deleteblank(char *);
int main(void)
{
        char a[30];
        while(*(gets(a))!='\n')
        {
                deleteblank(a);
        }
        return 0;
}
void deleteblank(char *s)
{
        char string[30];
        int i=0;
        while(*s!='\0')
        {
                if(*s!=' ')
                {
                        string[i]=*s;
                        i++;
                }
                s++;
        }
        string[i]='\0';
        puts(string);
}
// problem ten
#include<ctype.h>
void display(void);
void print(char (*)[20],int);
void asc2(char [][20],int);
void lengthsort(char [][20],int);
void firstword(char [][20],int);
int length_fword(char *string);
int main(void)
{
        int i;
        int j;
        char string[10][20];
        for(j=0;j<10&&gets(string[j]);j++);
        display();
        while(1)
        {
                printf("请输入序号(1-5):\n");
                scanf("%d",&i);
                switch(i)
                {
                        case 1:
                                print(string,j);
                                break;
                        case 2:
                                asc2(string,j);
                                break;
                        case 3:
                                lengthsort(string,j);
                                break;
                        case 4:
                                firstword(string,j);
                                break;
                        case 5:
                                puts("Bye bye!");
                                return 0;
                        default:
                                puts("Enter error!.");
                }
        }
        return 0;
}
void display(void)
{
        puts("1.输出初始字符串列表.");
        puts("2.按ASCII顺序输出字符串.");
        puts("3.按长度递增顺序输出字符串.");
        puts("4.按字符串中第一个单词的长度输出字符串.");
        puts("5.退出");
}
void print(char (*string)[20],int j)
{
        for(int i=0;i<j;i++)
                puts(string[i]);
        return;
}
void asc2(char string[][20],int j)
{
        char *p;
        char *ptr[j-1];
        for(int i=0;i<j;i++)
                ptr[i]=string[i];
        for(int i=0;i<j;i++)
        {
                for(int k=i+1;k<j;k++)
                        if(strcmp(ptr[i],ptr[k])>0)
                        {
                                p=ptr[i];
                                ptr[i]=ptr[k];
                                ptr[k]=p;
                        }
        }
        for(int i=0;i<j;i++)
                puts(ptr[i]);
}
void lengthsort(char string[][20],int j)
{
        char *p;
        char *ptr[j-1];
        for(int i=0;i<j;i++)
                ptr[i]=string[i];
        for(int i=0;i<j;i++)
        {
                for(int k=i+1;k<j;k++)
                        if(strlen(ptr[i])>strlen(ptr[k]))
                {
                        p=ptr[i];
                        ptr[i]=ptr[k];
                        ptr[k]=p;
                }
        }
        for(int i=0;i<j;i++)
                puts(ptr[i]);
}
void firstword(char string[][20],int j)
{
        char *ptr[j-1];
        char *p;
        int array[j-1];
        for(int i=0;i<j;i++)
                ptr[i]=string[i];
        for(int i=0;i<j;i++)
                array[i]=length_fword(ptr[i]);
        for(int i=0;i<j;i++)
        {
                for(int k=i+1;k<j;k++)
                        if(array[i]>array[k])
                {
                        p=ptr[i];
                        ptr[i]=ptr[k];
                        ptr[k]=p;
                }
        }
        for(int i=0;i<j;i++)
                puts(ptr[i]);
}
int length_fword(char *string)
{
        int i=0;
        while(isblank(*string))
                string++;
        for(int j=0;!isblank(*string)&&*string++!='\0';j++)
                i++;
        return i;
}
//problem eleven
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
        int lowercase=0,capital=0,words=0,punctuation=0,number=0;
        bool inword=false;
        char c;
        puts("Please enter a string:");
        while((c=getchar())!=EOF)
        {
                if(isalpha(c))
                {

                        if(islower(c))
                                lowercase++;
                        else
                                capital++;
                }
                else if(ispunct(c))
                        punctuation++;
                else if(isdigit(c))
                        number++;
                if(!inword&&isalpha(c))
                {
                        words++;
                        inword=true;
                }
                else if(inword&&(isspace(c)||ispunct(c)))//或者吸收所有空格和标点符号while(isspace(c)||ispunct(c))
                        inword=false;
        }
        printf("This string has %d words:\n",words);
        printf("In which,it has %d lowercase and %d capital.\n",lowercase,capital);
        printf("And the punctuation is %d,the digital is %d.\n",punctuation,number);
}
//problem twelve
#include<stdlib.h>
char *search(char *,char *,char);
int main(void)
{
        char a[50]="see you later";
        char *start,*end;
        end=&a[strlen(a)-1];
        int i;
        start=search(a,end,' ');
        start++;
        for(int i=0;start+i<=end;i++)
        {
                putchar(*(start+i));
        }
        end=start-1;
        while(start=search(a,end,' '))
        {
                for(int i=0;start+i<=end;i++)
                {
                        putchar(*(start+i));
                }
                end=start;
        }
        for(int i=0;a+i<=end;i++)
                putchar(a[i]);
        return 0;
}
char *search(char *start,char *end,char c)
{
        while(*end==' ')
                end--;
        for(int i=0;end-i>=start;i++)
        {
                if((*(end-i))==c)
                        return end-i;
        }
        return NULL;
}
//problem twelve
int main(int argc,char *argv[])//无法区分标点符号
{
        for(int i=argc-1;i>0;i--)
                printf("%s ",argv[i]);
        return 0;
}
//problem thirteen
#include<stdlib.h>
int main(int argc,char *argv[])
{
        int second;
        double first;
        char *end;
        first=strtod(argv[1],&end);
        second=strtol(argv[2],&end,10);
        for(int i=1;i<second;i++)
                first*=first;
        printf("As a result:the end is %g",first);
        return 0;
}
//answer fourteen
#include<ctype.h>
#include<math.h>
int atoi_f(const char *);
int main(void)
{
        char number[10];
        int integer;
        scanf("%s",number);
        integer=atoi_f(number);
        printf("%d",integer);
        return 0;
}
int atoi_f(const char *number)
{
        int n=0,i,j=0;
        for(i=0;number[i]!='\0'&&isdigit(number[i]);i++);
        for(i--;i>=0;i--)
        {
                n+=((number[i]-48)*(int)pow(10,j));
                j++;
        }
        return n;
}
//problem fifteen

#include <stdlib.h>
#define SIZE 81
int main(int argc,char *argv[]){
    char f = argv[1][0];   //读取参数
    printf("%s",argv[1]);
    printf("f = %c ",f);
    char ch;
    while((ch = getchar()) != EOF)
    {
        if(f=='p')
                putchar(ch);
        else if(f=='u')
                putchar(toupper(ch));
        else if(f=='l')
                putchar(tolower(ch));
    }
    return 0;
}

