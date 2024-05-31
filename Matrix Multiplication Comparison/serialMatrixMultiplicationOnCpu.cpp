#include<iostream>
#include<chrono>
#include<iomanip>
#include<cstdlib>
#include<ctime>

#define rows 500
#define cols 500

using namespace std;

void serialMul(int arr1[rows][cols], int arr2[rows][cols], int arr3[rows][cols])
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr3[i][j] = 0;
            for(int k = 0; k < cols; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main()
{
    int arr1[rows][cols], arr2[rows][cols], arr3[rows][cols];

    srand(time(0));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr1[i][j] = rand() % 100;
            arr2[i][j] = rand() % 100;
        }
    }

    auto start = chrono::high_resolution_clock::now();

    serialMul(arr1, arr2, arr3);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    // cout << "Multiplication of two matrices:" << endl;
    // for(int i = 0; i < rows; i++)
    // {
    //     for(int j = 0; j < cols; j++)
    //     {
    //         cout << setw(6) << arr3[i][j];
    //     }
    //     cout << endl;
    // }

    cout << "Time taken by CPU with serial execution is " << duration.count() << " milliseconds." << endl;

    return 0;
}
