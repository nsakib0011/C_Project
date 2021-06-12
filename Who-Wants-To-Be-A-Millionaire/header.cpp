///A project by Junaid Mahmud (154403) and Nazmus Sakib (154421)
#include<bits/stdc++.h>

using namespace std;

void delay(double sec)
{

    clock_t start,current;

    start = clock();
    current = clock();

    while((double)(current-start)/CLOCKS_PER_SEC < sec)
    {
        current = clock();
    }
}
 void border1()
{
    printf("\n -------------------------------------------------------------------------");
}
void border()
{
    printf("\n\t\t|");
    for(int i=0; i<40; i++)
    {
        printf("*");
    }
    printf("|");
    }
    void over()
    {
                    border1();
                    border();
                    printf("\n\n\n\n\t\t\t    Thank you for playing :) :)\n\n\n\n");
                    border();
                    border1();
                    printf("\n\n\n\n\n\n");
                    exit(1);
    }
void instruction()
{
    printf("\n\t1. You'll be given ten questions\n");
    printf("\n\t2. For each question, you have 30 seconds to answer\n");
    printf("\n\t3. 100k Taka prize for each question");
    printf("\n\t4. 3 life lines will be given");
    printf("\n\t5. 50-50: 2 options will be disappear.");
    printf("\n\t6. Jump-it: You can skip the prevalent question.");
    printf("\n\t7. Expedia:  It refers hints directly or undirectly about the question.");
    printf("\n\t8. If wrong answer or time exceeding, will result in game over");
    printf("\n\n\t\tBest of luck!");
}
