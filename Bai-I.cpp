#include <iostream>

using namespace std;

void enterArr(int a[], int n);
void exportSubmultiple(int a[], int n);

int main()
{
    int arr[100], n;
    cin >> n;
    enterArr(arr, n);
    exportSubmultiple(arr, n);
    return 0;
}

/*Dinh Nghia*/
void enterArr(int a[], int n)
{
    int i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }
}
int sumOfSubmultiple(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
void exportSubmultiple(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << sumOfSubmultiple(a[i]) << endl;
    }
}