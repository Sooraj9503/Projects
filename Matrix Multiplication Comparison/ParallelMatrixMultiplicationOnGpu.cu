%%writefile matrixMul.cu

#include<iostream>
#include<cstdlib>
#include<math.h>
#include<iomanip>
#include<chrono>
#include<cuda_runtime.h>
#define rows 5
#define cols 5
using namespace std;

__global__ void gpuMultiplication(int *arr1, int *arr2, int *arr3)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if(tid < rows * cols)
    {
        arr3[tid] = arr1[tid] * arr2[tid];
    }
}

int main()
{
    int *harr1, *harr2, *harr3, *darr1, *darr2, *darr3;
    size_t size = rows * cols * sizeof(int);

    harr1 = (int*)malloc(size);
    harr2 = (int*)malloc(size);
    harr3 = (int*)malloc(size);

    cudaMalloc(&darr1, size);
    cudaMalloc(&darr2, size);
    cudaMalloc(&darr3, size);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j <cols; j++)
        {
            harr1[i * cols + j] = rand() % 5;
            harr2[i * cols + j] = rand() % 5;
        }
    }

    cudaMemcpy(darr1, harr1, size, cudaMemcpyHostToDevice);
    cudaMemcpy(darr2, harr2, size, cudaMemcpyHostToDevice);

    int threadPerBlock = 256;
    int blocks = (rows * cols + threadPerBlock - 1) / threadPerBlock;

    auto start = chrono::high_resolution_clock::now();

    gpuMultiplication<<<blocks, threadPerBlock>>>(darr1, darr2, darr3);
    cudaDeviceSynchronize();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cudaMemcpy(harr3, darr3, size, cudaMemcpyDeviceToHost);

    cout<<"Time taken by GPU with parallel execution is "<<duration.count()<<" milliseconds."<<endl;

    cudaFree(darr1);
    cudaFree(darr2);
    cudaFree(darr3);
    free(harr1);
    free(harr2);
    free(harr3);

    return 0;
}