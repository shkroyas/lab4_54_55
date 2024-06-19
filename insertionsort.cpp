#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void InsertionSort(int a[], int size) {
    for (int j = 1; j < size; j++) {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

void GenerateRandomArray(int arr[], int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 999);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
}

int main() {
    ofstream outfile("insertion_sort_times.csv");
    outfile << "Input Size,Insertion Sort Time (microseconds)\n";
    
    const int startSize = 5000;
    const int endSize = 300000;
    const int interval = 5000;
    const int numSizes = (endSize - startSize) / interval + 1;

    int sizes[numSizes];
    for (int i = 0; i < numSizes; i++) {
        sizes[i] = startSize + i * interval;
    }

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int* arr = new int[size];
        
        GenerateRandomArray(arr, size);
        
        auto start = high_resolution_clock::now();
        InsertionSort(arr, size);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Insertion Sort for size " << size << " took " << duration << " microseconds." << endl;
        outfile << size << "," << duration << "\n";
        
        delete[] arr;
    }
    
    outfile.close();
    return 0;
}