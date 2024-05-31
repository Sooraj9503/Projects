#include<iostream>
#include<math.h>
#include<cstdlib>
#include<omp.h>
using namespace std;
#define rows 20
#define cols 20

int main()
{
    int arr1[rows][cols];
    int arr2[rows][cols];
    int arr3[rows][cols];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr1[i][j] = rand() % 10;
            arr2[i][j] = rand() % 100;
        }
    }

    #pragma omp parallel for collapse(2)
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr3[i][j] = arr1[i][j] * arr2[i][j];
        }
    }

    printf("Result:\n");
     for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
           cout << arr3[i][j] << "   ";
        }
        cout << endl;
    }
    
    
    return 0;
}