#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//problem 1
int main(void)
{
        int ch;
        char file[20];
        FILE *fp;
        long count=0;
        gets(file);
        if((fp=fopen(file,"r"))==NULL)
        {
                printf("Can't open %s\n");
                exit(1);
        }
        while((ch=getc(fp))!=EOF)
        {
                putc(ch,stdout);
                count++;
        }
        fclose(fp);
        printf("File %s has %ld characters\n",file,count);
        return 0;

//problem two

int main(int argc,char *argv[])
{
        FILE *in,*out;
        char c;
        if((in=fopen(argv[1],"rb"))==NULL)
        {

                fprintf(stderr,"Can't open %s\n",argv[1]);
                exit(1);
        }
        if((out=fopen(argv[2],"wb"))==NULL)
        {
                fprintf(stderr,"Can't open %s\n",argv[2]);
                exit(2);
        }
        while((c=getc(in))!=EOF)
                putc(c,out);
        fclose(in);
        fclose(out);
        return 0;
}

//problem three
#include<ctype.h>
int main(void)
{
        FILE *in,*out;
        char fsr[20],fop[20];
        char c;
        fprintf(stdout,"please enter the name of source file:\n");
        gets(fsr);
        while((in=fopen(fsr,"r"))==NULL)
        {
                fprintf(stdout,"Can't open the %s\nplease enter again.\n",fsr);
                gets(fsr);
        }
        while(gets(fop)!=NULL&&fop[0]!='\n')
        {
                if((out=fopen(fop,"w"))==NULL)
                        printf("Can't open the file.\n");
                else
                        break;
        }
        while((c=getc(in))!=EOF)
        {
                c=toupper(c);
                putc(c,out);
        }
        fclose(in);
        fclose(out);
        return 0;
}

//problem four
int main(int argc,char *argv[])
{
        int i;
        for(i=1;i<=argc-1;i++)
        {
                fprintf(stdout,"%s\n",argv[i]);
        }
        return 0;
}

//problem five
#include<string.h>
#define BUFSIZE 1024
void append(FILE *,FILE *);
int main(int argc,char *argv[])
{
        FILE *fa,*fs;
        puts("Enter name of destination file:");
        if((fa=fopen(argv[1],"a"))==NULL)
        {
                fprintf(stderr,"Can't open %s\n",argv[1]);
                exit(2);
        }
        if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
        {
                fputs("Can't create output buffer\n",stderr);
                exit(3);
        }
        puts("Enter name of first source file(empty line to quit):");
        if(strcmp(argv[1],argv[2])==0)
                fputs("Can't append file to itself\n",stderr);
        else if((fs=fopen(argv[2],"r"))==NULL)
                fprintf(stderr,"Can't open %s\n",argv[2]);
        else
        {
                if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
                {
                        fputs("Can't create input buffer\n",stderr);
                }
                append(fs,fa);
                if(ferror(fs)!=0)
                        fprintf(stderr,"Error in reading file %s.\n",argv[2]);
                if(ferror(fa)!=0)
                        fprintf(stderr,"Error in writing file %s.\n",argv[1]);
                fclose(fs);
        }

        printf("Done.%d files appended.\n",argc-1);
        fclose(fa);
        return 0;
}
void append(FILE *source,FILE *dest)
{
        size_t bytes;
        static char temp[BUFSIZE];
        while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
                fwrite(temp,sizeof(char),bytes,dest);
}

//problem six
#include<string.h>
#define LEN 40
int main(void)
{
        FILE *in,*out;
        int ch;
        char name[LEN],store[LEN];
        int count=0;
        while(1)
        {
                printf("Usage:enter the filename\n");
                if(gets(name)&&name[0]!='\0')
                {
                        if((in=fopen(name,"r"))==NULL)
                        {
                                printf("I couldn't open the file \"%s\"\n",name);
                        }
                        else
                                break;
                }
        }
        strcpy(store,name);
        strcat(store,".txt");
        if((out=fopen(store,"w"))==NULL)
        {
                fprintf(stderr,"Can't create output file.\n");
                exit(3);
        }
        while((ch=getc(in))!=EOF)
                if(count++%3==0)
                putc(ch,out);
        if(fclose(in)!=0||fclose(out)!=0)
                fprintf(stderr,"Error in closing files\n");
        return 0;
}

//problem seven
int main(int argc,char *argv[])
{
        FILE *fp1,*fp2;
        char string1[50];
        char string2[50];
        char *a,*b;
        if(argc!=3)
        {
                fprintf(stderr,"enter error!");
                exit(EXIT_FAILURE);
        }
        if((fp1=fopen(argv[1],"r"))==NULL)
        {
                fprintf(stderr,"Can't open the file.\n");
                EXIT_FAILURE;
        }
        if((fp2=fopen(argv[2],"r"))==NULL)
        {
                fprintf(stderr,"Can't open this file.\n");
                exit(EXIT_FAILURE);
        }
        for(a=fgets(string1,50,fp1),b=fgets(string2,50,fp2);a!=NULL||b!=NULL;)
        {
                if(a!=NULL)
                        fputs(string1,stdout);
                if(b!=NULL)
                        fputs(string2,stdout);
                a=fgets(string1,50,fp1);
                b=fgets(string2,50,fp2);
        }
        return 0;
}
void deal(char *);
int main(int argc,char *argv[])
{
        FILE *fp1,*fp2;
        char string1[50];
        char string2[50];
        char *a,*b;
        fp1=fopen(argv[1],"r");
        fp2=fopen(argv[2],"r");
        for(a=fgets(string1,50,fp1),b=fgets(string2,50,fp2);a!=NULL||b!=NULL;)
        {
                if(a!=NULL)
                {
                        deal(string1);
                        fputs(string1,stdout);
                }
                if(b!=NULL)
                {
                        deal(string2);
                        fputs(string2,stdout);
                }
                putchar('\n');
                a=fgets(string1,50,fp1);
                b=fgets(string2,50,fp2);
        }
        return 0;
}
void deal(char *string)
{
        char *find;
        find=strchr(string,'\n');
        if(find)
                *find='\0';
}
//problem eight
int main(int argc,char *argv[])
{
        FILE *fp;
        char c;
        int number;
        if(argc==1)
        {
                printf("enter error!");
                exit(EXIT_FAILURE);
        }
        if(argc==2)
                fp=stdin;
        else
        {
                for(int i=2;i<argc;i++)
                {
                        if(!(fp=fopen(argv[i],"r")))
                        {
                                fprintf(stderr,"Can't open the %s file",argv[i]);
                                continue;
                        }
                        number=0;
                        while((c=getc(fp))!=EOF)
                        {
                                if(c==argv[1][0])
                                        number++;
                        }
                        printf("the %s have %d %c\n",argv[i],number,argv[1][0]);
                        fclose(fp);
                }
        }

        return 0;
}
//problem nine
#define MAX 40
int main(void)
{
        FILE *fp;
        int n=0;
        char c;
        char words[MAX];
        if((fp=fopen("words.txt","a+"))==NULL)
        {
                printf("Can't open \"words\" file.\n");
                exit(EXIT_FAILURE);
        }
        puts("Enter words to add to the file:press the Enter");
        puts("key at the beginning of a line to terminate.");
        while((c=getc(fp))!=EOF)
                if(c=='\n')
                {
                        n++;
                }
        while(scanf("%s",words)==1&&words[0]!='\0')
        {
                n++;
                fprintf(fp,"%d:%s\n",n,words);
        }
        puts("File contents:");
        rewind(fp);
        while(fscanf(fp,"%s",words)==1)
                puts(words);
        if(fclose(fp)!=0)
                fprintf(stderr,"Error closing file\n");
        return 0;
}
//problem ten
int main(void)
{
        FILE *fp;
        long add;
        char file[20];
        char c;
        scanf("%s",file);
        fp=fopen(file,"r");
        while(scanf("%d",&add)==1)
        {
                fseek(fp,add,SEEK_SET);
                while((c=getc(fp))!='\n'&&c!=EOF)
                        putchar(c);
                putchar('\n');
        }
        fclose(fp);
        return 0;
}
//problem eleven
int main(int argc,char *argv[])
{
        char string[50];
        FILE *fp;
        fp=fopen(argv[2],"r");
        if(argc!=3)
                printf("Error!");
        while(fgets(string,50,fp))
        {
                if(strstr(string,argv[1]))
                        fprintf(stdout,"%s",string);
        }
        fclose(fp);
        return 0;
}
//problem twelve
char shift(int);
int main(void)
{
        int array[20][30];
        int number;
        FILE *fp1,*fp2;
        if((fp1=fopen("word.txt","r"))==NULL)
        {
                printf("Openning error!");
                exit(EXIT_FAILURE);
        }
        if((fp2=fopen("write.txt","w"))==NULL)
        {
                printf("Openning error!2");
                exit(EXIT_FAILURE);
        }
        for(int i=0;i<20;i++)
        {
                for(int j=0;j<30;j++)
                {
                        fscanf(fp1,"%d",&array[i][j]);
                        number=array[i][j];
                        fprintf(fp2,"%c",shift(number));
                        printf("%c",shift(number));
                }
                printf("\n");
                fprintf(fp2,"\n");
        }
        fclose(fp1);
        fclose(fp2);
        return 0;
}
char shift(int number)
{
        char string[10]=" .':~*=!%#";
        return string[number];
}
//problem thirteen
int main(void)
{
        int array[20][30];
        int number;
        FILE *fp1;
        if((fp1=fopen("word.txt","r"))==NULL)
        {
                printf("Openning error!");
                exit(EXIT_FAILURE);
        }
        for(int i=0;i<20;i++)
        {
                for(int j=0;j<30;j++)
                {
                        fscanf(fp1,"%d",&array[i][j]);
                }
        }
        if(array[0][0]!=array[0][1]&&array[0][0]!=array[1][0])
                array[0][0]=(double)(array[0][1]+array[1][0])/2.;
        for(int i=1;i<29;i++)
        {
                if(array[0][i]!=array[0][i-1]&&array[0][i]!=array[0][i+1]&&array[0][i]!=array[1][i])
                        array[0][i]=(double)(array[0][i-1]+array[0][i+1]+array[1][i])/3.;
        }
        if(array[0][29]!=array[0][29]&&array[0][29]!=array[1][29])
        {
                array[0][29]=(double)(array[0][28]+array[1][29])/2.;
        }
        for(int i=1;i<19;i++)
                for(int j=0;j<30;j++)
                {
                        if(j==0)
                                if(array[i][j]!=array[i-1][j]&&array[i][j]!=array[i][j+1]&&array[i][j]!=array[i+1][j])
                                        array[i][j]=(double)(array[i-1][j]+array[i][j+1]+array[i+1][j])/3.;
                        else if(j==29)
                                if(array[i][j]!=array[i][j-1]&&array[i][j]!=array[i-1][j]&&array[i][j]!=array[i+1][j])
                                        array[i][j]=(double)(array[i-1][j]+array[i][j-1]+array[i+1][j])/3.;
                        else
                                if(array[i][j]!=array[i-1][j]&&array[i][j]!=array[i][j+1]&&array[i][j]!=array[i+1][j]&&array[i][j]!=array[i][j-1])
                                        array[i][j]=(double)(array[i-1][j]+array[i][j-1]+array[i+1][j]+array[i][j+1])/4.;
                }
        if(array[19][0]!=array[19][1]&&array[19][0]!=array[18][0])
                array[19][0]=(double)(array[19][1]+array[18][0])/2.;
        for(int i=1;i<29;i++)
        {
                if(array[19][i]!=array[19][i-1]&&array[19][i]!=array[19][i+1]&&array[19][i]!=array[18][i])
                        array[19][i]=(double)(array[19][i-1]+array[19][i+1]+array[18][i])/3.;
        }
        if(array[19][29]!=array[18][29]&&array[19][29]!=array[19][28])
        {
                array[19][29]=(double)(array[18][29]+array[19][28])/2.;
        }
        for(int i=0;i<20;i++)
        {
                for(int j=0;j<30;j++)
                        printf("%d ",array[i][j]);
                putchar('\n');
        }
        return 0;
}
