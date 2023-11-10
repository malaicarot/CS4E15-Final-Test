#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

bool isPrime(int n);
bool isSuperPrime(int n);
vector<int> superPrimeArr(int n);

int main()
{
    // cout << isPrime(239);
    // cout << isSuperPrime(2);
    int n;
    cin >> n;
    vector<int> result = superPrimeArr(n);
    for(int i = 0; i <result.size(); i++){
        cout << result[i] << " ";
    }

    return 0;
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool isSuperPrime(int n)
{
    if (!isPrime(n))
        return false;
    while ((n / 10) > 0)
    {
        n /= 10;
        if (!isPrime(n))
            return false;
    }

    return true;
}
vector<int> superPrimeArr(int n)
{
    queue<int> superPrimeQueue;
    vector<int> superPrimeArr;
    superPrimeQueue.push(2);
    superPrimeQueue.push(3);
    superPrimeQueue.push(5);
    superPrimeQueue.push(7);

    while (!superPrimeQueue.empty())
    {
        int x = superPrimeQueue.front();
        superPrimeQueue.pop();
        if (isSuperPrime(x) && x <= n)
        {
            superPrimeArr.push_back(x);
        }

        for (int i = 1; i <= 9; i += 2)
        {
            int y = x * 10 + i;
            if (isSuperPrime(y))
            {
                superPrimeQueue.push(y);
            }
        }
    }
    return superPrimeArr;
}