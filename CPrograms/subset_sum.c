#include <stdio.h>

#define N 4

int issafe(int b[][], int row, int col)
{
    
}

int solve4q(int b[][], int col)
{
    int row;
    if (col >= N)
    {
        return 1;
    }
    else
    {
        for (row=0; row< N; row++)
        {
            if issafe(b, row, col)
            {
                b[row][col] = 1;
                if (solve4q(b, col+1))
                    return 1;
                b[row][col] = 0;
            }
        }    
        return 0;
    }
}


int main()
{
    int b[4][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} }; 
    solve4q(b, 0); 
}




