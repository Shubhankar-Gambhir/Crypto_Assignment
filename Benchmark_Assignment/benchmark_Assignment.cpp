#include <bits/stdc++.h>
#include <benchmark/benchmark.h>

using namespace std;

void Addition(benchmark::State& state){
    int a = rand();
    int b =  rand();
    int sum = a+b;
    for (auto _ : state){
        a + b;
    }
}
BENCHMARK(Addition);

void swap(int* a, int* b)  {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition (int arr[], int low, int high)  {  
    int pivot = arr[high]; 
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  {    
        if (arr[j] < pivot)  {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  {  
    if (low < high)  {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

void QuickSort_10(benchmark::State& state) {
    int a[10];
    for(int i=0;i<10;i++) a[i] = rand();
    for (auto _ : state){
        quickSort(a,0,9);
    }
}
BENCHMARK(QuickSort_10);
void QuickSort_100(benchmark::State& state) {
    int a[100];
    for(int i=0;i<100;i++) a[i] = rand();
    for (auto _ : state){
        quickSort(a,0,99);
    }
}
BENCHMARK(QuickSort_100);
void QuickSort_1000(benchmark::State& state) {
    int a[1000];
    for(int i=0;i<1000;i++) a[i] = rand();
    for (auto _ : state){
        quickSort(a,0,999);
    }
}
BENCHMARK(QuickSort_1000);
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j]; 
    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 

void MergeSort_10(benchmark::State& state) {
    int a[10];
    for(int i=0;i<10;i++) a[i] = rand();
    for (auto _ : state){
        mergeSort(a,0,9);
    }
}
BENCHMARK(MergeSort_10);
void MergeSort_100(benchmark::State& state) {
    int a[100];
    for(int i=0;i<100;i++) a[i] = rand();
    for (auto _ : state){
        mergeSort(a,0,99);
    }
}
BENCHMARK(MergeSort_100);
void MergeSort_1000(benchmark::State& state) {
    int a[1000];
    for(int i=0;i<1000;i++) a[i] = rand();
    for (auto _ : state){
        mergeSort(a,0,999);
    }
}
BENCHMARK(MergeSort_1000);

BENCHMARK_MAIN();