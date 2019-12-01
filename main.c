#include <stdio.h>
#include <stdlib.h>
int check_win(int x[9]){
    if (x[0]==x[1] && x[1]==x[2] && x[2]==x[0] && x[0]!=0)
        return 1;
    if (x[3]==x[4] && x[3]==x[5] && x[4]==x[5] && x[3]!=0)
        return 1;
    if (x[6]==x[7] && x[6]==x[8] && x[6]==x[8] && x[6]!=0)
        return 1;
    if (x[0]==x[3] && x[0]==x[6] && x[6]==x[3] && x[0]!=0)
        return 1;
    if (x[1]==x[4] && x[1]==x[7] && x[4]==x[7] && x[1]!=0)
        return 1;
    if (x[2]==x[5] && x[2]==x[8] && x[5]==x[8] && x[2]!=0)
        return 1;
    if (x[0]==x[4] && x[0]==x[8] && x[4]==x[8] && x[4]!=0)
        return 1;
    if (x[2]==x[4] && x[2]==x[6] && x[6]==x[4] && x[6]!=0)
        return 1;
    return 0;

}

void draw_game(int x[9]){
    for (int i=0; i<9; i++){
        if (x[i]==2)
            printf("X");
        if (x[i]==1)
            printf("O");
        if (x[i]==0)
            printf(" ");
        if (((i+1) % 3) == 0)
            printf("\n");
        else
            printf("|");


    }


}


int main()
{
    int x[9] = {0} , i = 1, done = 0 , n;
    while (!done){
        if(i % 2 == 0)
            printf("O\n");
        else printf("X\n");
        draw_game(x);
        scanf("%d" , &n);
        if (x[n-1]!=0)
        {
            printf("voroodi eshtebah\n");
            continue;
        }
        if(i % 2 == 0){
            x[n-1] = 1;
        }
        else
            x[n-1] = 2;

        if (check_win(x) && i%2 == 1){
            draw_game(x);
            printf("player 1 wins");
            return 0;
        }


        if (check_win(x) && i%2 == 1)
        {
            draw_game(x);
            printf("player 2 wins");
            return 0;
        }

        if (i==9){
            draw_game(x);
            printf("draw");
            return 0;
        }

        i++;

    }
}
