#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#include <string.h>

struct user
{
    char name[20];
    int score;

}p1,p2;


int toss()
{
    srand ( time(NULL) );
    char c;
    int m,ts,k,b,ct;
    printf("\nChoose ----- ODD OR EVEN (O/E) :  ");
    scanf("%s",&c);
    printf("\nPlay your move  : ");
    scanf("%d",&m);
    ts=rand() % 6 + 1;
    printf("Computer's move : %d",ts);
    getch();
    k=ts+m;
    if(c=='E'||c=='e')
    {
        if(k%2==0)
            {
                printf("\n\nYOU WON THE TOSS\n\n");
                getch();
                printf("WHAT WOULD YOU LIKE TO CHOOSE ---- BAT (1) or BOWL (2)  : ");
                scanf("%d",&b);
                if(b==1)
                    return 1;
                else
                    return 2;
            }
        else
            {
                printf("\n\nYOU LOST THE TOSS\n\n");
                srand(time(NULL));
                ct=rand() % 2 + 1;
                if(ct==2)
                    {
                        printf("COMPUTER WOULD LIKE TO BAT FIRST\n");
                        getch();
                        return 2;
                    }
                else
                    {
                        printf("COMPUTER WOULD LIKE TO BOWL FIRST\n");
                        getch();
                        return 1;
                    }
            }
    }
    else if(c=='O'||c=='o')
    {
        if(k%2!=0)
            {
                printf("\n\nYOU WON THE TOSS\n\n");
                getch();
                printf("WHAT WOULD YOU LIKE TO CHOOSE ---- BAT (1) or BOWL (2)  : ");
                scanf("%d",&b);
                if(b==1)
                    return 1;
                else
                    return 2;
                return 1;
            }
        else
            {
                printf("\n\nYOU LOST THE TOSS\n\n");
                srand(time(NULL));
                ct=rand() % 2 + 1;
                if(ct==2)
                    {
                        printf("COMPUTER WOULD LIKE TO BAT FIRST\n");
                        getch();
                        return 2;
                    }
                else
                    {
                        printf("COMPUTER WOULD LIKE TO BOWL FIRST\n");
                        getch();
                        return 1;
                    }
            }
    }
}

int menu()
{
    int c,series;
    printf("\t\t\t\t   WELCOME\n\n\t\t\tCHOOSE FROM THE MENU BELOW : \n\n\t\t\t1.PLAY A SINGLE GAME vs COMPUTER\n\t\t\t2.PLAY A SERIES GAME\n\t\t\t3.EXIT\n\n\t\t\t");
    scanf("%d",&c);
    printf("\n");
    switch(c)
    {
        case 1 : return 1;
        case 2 : printf("HOW MANY MATCHES YOU WANNA PLAY IN THE SERIES (3 OR 5) : ");
                 scanf("%d",&series);
                 break;
        case 3 : system("cls");
                 printf("\nEXITING FROM THE GAME\n");
                 exit(0);
    }
}
void pwc()
{

    int t,m,n,cn,b,cs;
    char ch,name[20];
    printf("\t\t\tEnter your name : ");
    scanf("%s",&p1.name);
    strcpy(name,p1.name);
    do{
    system("cls");
    printf("\t\t\t   WELCOME %s\n\n",toupper(name));
    printf("\t\t\tIT'S TIME FOR THE TOSS\n");
    t=toss();
    p1.score=0;
    cs=0;
    if(t==1)
    {
        system("cls");
        printf("\t\t\t---->ITS YOUR TURN TO BAT<----\n\n");
        m=0;
        do
        {
        printf("\nPlay your Move  : ");
        scanf("%d",&m);
        if(m==0)
            exit(0);
        srand ( time(NULL) );
        n=rand() % 6 + 1;
        printf("Computer's Move : %d\n",n);
        p1.score+=m;
        if(m!=n)
            printf("\t\t\t\tYOUR SCORE : %d\n",p1.score);
        }while(m!=n);
            p1.score-=m;
            printf("\n\t\t\t!!!!!!! OUT !!!!!!!\n\n");
            printf("\n\nYOUR SCORE : %d\n\n",p1.score);
            getch();
            system("cls");
            printf("\t\t\t\tTARGET FOR COMPUTER : %d\n\n",p1.score+1);
            printf("\t\t\t---->Now its Computer's turn to BAT<----\n\n");
            cn=0;
            do{
            printf("Play your Move  : ");
            scanf("%d",&b);
            if(m==0)
            exit(0);
            srand ( time(NULL) );
            cn=rand() % 6 + 1;
            printf("Computer's Move : %d\n",cn);
            cs+=cn;
            if(cn!=b)
                {
                    printf("\t\t\t\tCOMPUTER'S SCORE : %d\n\n",cs);
                    if((p1.score-cs)<=10&&p1.score>cs)
                            printf("\t\t\t\tCOMPUTER NEEDS %d MORE RUNS TO WIN\n",p1.score-cs+1);
                }
            }while((cn!=b)&&(cs<=p1.score));
            if(cn==b)
            {
                cs-=cn;
                printf("\n\n\t\t\t!!!!!!!COMPUTER --- OUT!!!!!!!\n\nCOMPUTER'S SCORE : %d\n\n",cs);
                if(cs<p1.score)
                        printf("\n\t\t\t\t----------\n\t\t\t\t  YOU WON\n\t\t\t\t----------\n");
                else if(cs==p1.score)
                        printf("\nMATCH TIE\n");
                else
                        {
                            printf("\n\t\t\t\t----------\n\t\t\t\t  YOU LOST\n\t\t\t\t----------\n");
                            printf("\n\t\t\t\tCOMPUTER WON BY 1 WICKET\n");
                        }

            }
            else
                   {
                       printf("\n\t\t\t\t----------\n\t\t\t\t  YOU LOST\n\t\t\t\t----------\n");
                       printf("\n\t\t\t\tCOMPUTER WON BY 1 WICKET\n");
                   }
    }
    else if(t==2)
    {
            system("cls");
            printf("\t\t\t---->ITS COMPUTER'S TURN TO BAT<----\n\n");
            cn=0;
            do{
            printf("\nPlay your Move  : ");
            scanf("%d",&b);
            if(b==0)
                exit(0);
            srand ( time(NULL) );
            cn=rand() % 6 + 1;
            printf("Computer's Move : %d\n",cn);
            cs+=cn;
            if(cn!=b)
                printf("\t\t\t\tCOMPUTER'S SCORE : %d\n",cs);
            }while(cn!=b);
                cs-=cn;
                printf("\n\n\t\t\t!!!!!!!COMPUTER --- OUT!!!!!!!\n\nCOMPUTER'S SCORE : %d\n\n",cs);
                getch();
                system("cls");
                printf("\t\t\t\t  TARGET : %d\n\n",cs+1);
                printf("\t\t\t---->Now its Your turn to BAT<----\n\n");
                m=0;
                do
                {
                printf("\nPlay your Move  : ");
                scanf("%d",&m);
                if(m==0)
                    exit(0);
                srand ( time(NULL) );
                n=rand() % 6 + 1;
                printf("Computer's Move : %d\n",n);
                p1.score+=m;
                if(m!=n)
                    {
                        printf("\t\t\t\tYOUR SCORE : %d\n",p1.score);
                        if((cs-p1.score)<=10&&cs>p1.score)
                            printf("\t\t\t\tYOU NEED %d MORE RUNS TO WIN\n",cs-p1.score+1);
                    }
                }while(m!=n&&(cs>=p1.score));
                if(m==n)
                {
                    p1.score-=m;
                    printf("\n\n\t\t\t!!!!!!! OUT !!!!!!!\n\n");
                    printf("\n\nYOUR SCORE : %d\n\n",p1.score);
                    if(cs<p1.score)
                        printf("\n\t\t\t\t----------\n\t\t\t\t  YOU WON\n\t\t\t\t----------\n");
                    else if(cs==p1.score)
                        printf("\nMATCH TIE\n");
                    else
                        {
                            printf("\n\t\t\t\t----------\n\t\t\t\t  YOU LOST\n\t\t\t\t----------\n");
                            printf("\n\t\t\t  COMPUTER WON BY %d RUNS\n",cs-p1.score);
                        }
                }
                else
                    printf("\n\t\t\t\t----------\n\t\t\t\t  YOU WON\n\t\t\t\t----------\n");
    }
            printf("\nWANT TO PLAY AGAIN (Y/N) : ");
            scanf("%s",&ch);
    }while(ch=='y'||ch=='Y');
}

int main()
{
    int men;
    men=menu();
    if(men==1)
        pwc();
    /*else if(m==2)
        p2p();*/

    return 0;
}
