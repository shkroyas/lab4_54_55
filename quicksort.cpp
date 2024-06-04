#include<iostream>
#include<random>

int Partition(int* a, int low, int high){
    std::cout<<"Partition Called";
    int pi = a[low];
    int i = low;
    int j = high + 1;
    while( i < j ){
        while (i<j && a[j]<pi) { j -= 1; }
        while (i<j && a[i]>pi) { i += 1; }
        if( i < j ){
            int temp1 = a[j];
            a[j] = a[i];
            a[i] = temp1;
        }
    }
    //Swap low with j
    int temp2 = a[low];
    a[low] = a[j];
    a[j] = temp2;

    return j;
}

void QuickSort(int* a, int low, int high){
    std::cout<<"QuickSort called\n";
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
    int arr[n];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999);

    std::cout<<"Using MT:\n";
    for(int i = 0; i < n; i++)
        arr[i] = dis(gen);
    
    std::cout<<"Randomization completed\n";
    QuickSort(arr, 0, n-1);

    std::cout<<"Sorted List: \n";
    for(int i = 0; i < n; i++)
        std::cout<<arr[i]<<", ";
}