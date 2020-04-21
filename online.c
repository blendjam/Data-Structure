#include <stdio.h>
int main()
{
    int arr[3][3] = {
        1,2,3,
        4,5,6,
        3,8,9
    };
    int sumA = 0, sumB = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j)
                sumA += arr[i][j];
            if((2 - i) == j)
                sumB += arr[i][j];
        }
    }
    int diff = sumA - sumB;
    printf("%d",diff);
}
