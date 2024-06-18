#include<iostream>
#include<random>
#include<ctime>
#include<chrono>

int Partition(int* a, int low, int high){
    int pi = a[low];
    int i = low;
    int j = high + 1;
    while (true) {
        while (a[++i] < pi) {
            if (i == high) break;
        }
        
        while (a[--j] > pi) {
            if (j == low) break;
        }
        
        if (i >= j) break;
        
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    //Swap low with j
    int temp2 = a[low];
    a[low] = a[j];
    a[j] = temp2;

    return j;
}

void QuickSort(int* a, int low, int high){
    if(low < high){
        int pivot = Partition(a, low, high);
        QuickSort(a, low, pivot-1);
        QuickSort(a, pivot+1, high);
    }
}

int main(){
    int n;
    std::cout<<"Enter size of list: ";
    std::cin>>n;
    int arr[n], arr2[n];

    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dis(0, 999);

    srand(time(NULL));

    for(int i = 0; i < n; i++)
        {arr[i] = rand();
        // std::cout<< arr[i] <<", ";
        }

    auto start = std::chrono::high_resolution_clock::now();

    QuickSort(arr, 0, n-1);

    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;
    std::cout<<"Execution Time for average case is: "<< elapsed.count()<<std::endl;

    for(int i = 0; i < n; i++){
        arr2[i] = n - i;
    }

    auto start2 = std::chrono::high_resolution_clock::now();

    QuickSort(arr2, 0, n-1);

    auto finish2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed2 = finish2 - start2;
    std::cout<<"Execution Time for worst case is: "<< elapsed2.count();    
}