#include <iostream>
#include <random>

using namespace std;

int InsertionSort(int a[], int size)
{

    for (int j = 1; j <= size - 1; j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i])
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter size of list:"<<endl;
    cin >> n;
    int a[n];

    // Using Mersenne Twister
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 999);

    cout << "Using MT:\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = dis(gen);
    }
    int size = sizeof(a) / sizeof(a[0]);

    InsertionSort(a, size);

    cout << "Sorted List";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}