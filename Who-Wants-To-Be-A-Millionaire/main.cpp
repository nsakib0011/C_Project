///A project by Junaid Mahmud (154403) and Nazmus Sakib (154421)
#include<stdio.h>
#include<bits/stdc++.h>
#include"header.h"
#include<conio.h>
#include <time.h>
#include <algorithm>
#include<stdlib.h>
using namespace std;
struct info
{
    string ques,o1,o2,o3,o4,ans,hint;
};
struct info questions[25];
int number=25;

void ask()
{
    ifstream file;
    file.open("new.txt");
    int array[30];
    for(int i = 0; i<25; i++)array[i]=i;
    srand(time(NULL));
    int r = rand()%100000;
    while(r--)
    {
        next_permutation(array,array+5);
        next_permutation(array+5,array+10);
        next_permutation(array+10,array+15);
        next_permutation(array+15,array+20);
        next_permutation(array+20,array+25);

    }
    for(int i = 0; i <number; i++)
    {
        getline(file,questions[array[i]].ques);                          //we will get the input of each of the question and options from here
        getline(file,questions[array[i]].o1) ;
        getline(file,questions[array[i]].o2) ;
        getline(file,questions[array[i]].o3) ;
        getline(file,questions[array[i]].o4) ;
        getline(file,questions[array[i]].ans);
        getline(file,questions[array[i]].hint);
        string str;
        getline(file,str);
    }
    file.close();
}


void print(int i )
{
    border();
    border1();

    cout <<"\n\t" << questions[i].ques << "\n";
    cout << "\t" <<  questions[i].o1 << "\n";
    cout <<  "\t"<< questions[i].o2 << "\n";
    cout <<  "\t"<< questions[i].o3 << "\n";
    cout <<  "\t"<< questions[i].o4 << "\n";

    border1();
    border();
    printf("\n\n\n\t\t\tPress L for lifeline\n");
}
int choice, qcoun=1,   flag, lifeline=3, score = 0, life[5], prize=100000;;

char L[ ][10] = {"50 - 50","Jump It", "Ex-pedia"}, ch;

int main()
{
    char k;
    main:

    ask();
    while(1)
    {
        system("cls");
        if(ch==0)
        {
            home:
            border();
            border1();
            printf("\n\t\t\t  WELCOME \n\t\t\tTO THE GAME\n\t\tWHO WANTS TO BE MILLIONAIRE!!!");
            printf("\n\n\n\t\t\tPress S TO START THE GAME\n\n\t\t\tPress X to Exit\n\n\t\t\tPress I for instructions");
            border1();
            border();

            ch =  toupper(getch());
            fflush(stdin);

        }
        else if(ch=='I')
        {
            system("cls");
            instruction();
            printf("\n\n\t\t\tPress H to get back to main menu");

            k = toupper(getch());
            fflush(stdin);
            if(k=='H' || k=='h')
            {
                system("cls");
                goto home;
            }

        }

        else if(ch=='X')
        {
            border1();
            border();
            printf("\n\n\n\n\t\t\t    Thank you :) :)\n");

            border();
            border1();
            exit(1);
        }
        else if(ch=='S')
        {
            flag = 0;
            for(int i = 0 ; i<number; i++)
            {

                if(flag=1)
                {
                    flag=0;
                }

                int timer = 30;

                int answer = 0;


                while(timer>0)
                {
                    system("cls");
                    printf("Time Remaining : %d\t\tPrizemoney of this question is: %d taka\n\n",timer,prize);
                    print(i);
                    printf("\t\tYou've won %d Taka !", score);
                    if(flag)
                    {
                        cout << "Hint : " << questions[i].hint << "\n";



                    }
                    if(kbhit())
                    {
                        char ch = getche();
                        system("cls");
                        printf("Time Remaining : %d\n\n",timer);

                        print(i);

                        if(ch=='l')
                        {
                            if(lifeline==0)printf("No Lifeline Remaining\n");
                            else
                            {
                                system("cls");
                                printf("Time has been stopped\n\n");
                                print(i);

                                printf("\nYou have %d lifeline(s)\n",lifeline);
                                for(int j = 0; j<3; j++)
                                {
                                    if(life[j]==1)
                                    {
                                        printf("%d )\n",j+1);
                                        continue;
                                    }
                                    printf("%d ) %s\n",j+1,L[j]);
                                }
                                ch = getche();
                                int cc = ch - '0';
                                life[cc-1]=1;
                                if(cc==1)                                       // here the 50-50 lifeline will be executed by clearing any two options
                                {
                                    if(questions[i].ans[0]=='A' || questions[i].ans[0]=='C')
                                    {
                                        questions[i].o2.clear();
                                        questions[i].o4.clear();
                                    }
                                    else
                                    {
                                        questions[i].o1.clear();
                                        questions[i].o3.clear();
                                    }
                                }
                                else if(cc==2)
                                {

                                    lifeline--;                                 // this will use the jump it lifeline by skipping the prevailing question

                                         goto out;
                                }
                                else if(cc==3)
                                {
                                    flag = 1;

                                }
                                lifeline--;
                            }
                        }
                        else if(ch>='a' &&  ch<='d')
                        {
                            if(ch==tolower(questions[i].ans[0]))
                            {
                                answer = 1;
                                break;
                            }
                            else
                            {
                                system("cls");
                                printf("\n\n\n\n\t\t\tWrong Answer\n\n");
                                printf("\t\t\tCorrect Ans is  %c", questions[i].ans[0]);       // here the right answer will be shown after making a wrong attempt
                                delay(2);
                                system("cls");
                                printf("\n\n\n\n\t\t\t\nYou've won %d Taka", score);
                                over();

                            }
                        }

                    }

                    delay(1);
                    timer--;
                }
                if(answer==1)
                {
                    system("cls");

                    printf("\n\n\n\n\t\t\tCorrect Answer!!!!\n");
                    score+=prize;

                    printf("\n\n\n\n\t\t\t Congratulation!  You have won %d taka!!\n",score);
                    if(score==1000000)
                    {
                        printf("\n\n\n\n\t\t\t Congratulations! You have become MILIIONAIRE!!!!!");
                        delay(3);
                        system("cls");
                        over();
                    }

                    number++;
                    delay(2);
                }
                else
                {
                    system("cls");


                    printf("\n\n\n\n\t\t\t\tSorry!! Time Up!!\n\n\t\t\t\tGAME OVER\n");
                    delay(3);
                    system("cls");

                    printf("\n\n\n\n\t\t\tCongratulations! You've earned %d taka!\n",score);

                    delay(3);
                    system("cls");
                    over();

                }


out:
                continue;
            }
        }
        else
                        {
                            system("cls");
                            printf("Invalid Input\n");
                            delay(3);
                            system("cls");
                            goto home;

                        }
    }


}
