#include <iostream>
#include <string>
#include <stack>

using namespace std;

string encodeString();

int main()
{
    cout << encodeString();

    return 0;
}

/*Dinh Nghia*/
string encodeString()
{
    stack<char> duplicatedStack;
    string ipString;
    string opString = "";
    getline(cin, ipString);
    int count = 0;
    for (int i = 0; i < ipString.length(); i++)
    {
        char c = ipString[i];
        if (c >= 97 && c <= 122)
        {
            if (duplicatedStack.empty())
            {
                duplicatedStack.push(c);
            }
            else
            {
                if (duplicatedStack.top() == c)
                {
                    duplicatedStack.push(c);
                }
                else
                {
                    opString += duplicatedStack.top();
                    while (!duplicatedStack.empty())
                    {
                        duplicatedStack.pop();
                        count++;
                    }
                    opString += to_string(count);
                    count = 0;
                    duplicatedStack.push(c);
                }
            }
        }
    }

    if (!duplicatedStack.empty())
    {
        opString += duplicatedStack.top();
        while (!duplicatedStack.empty())
        {
            duplicatedStack.pop();
            count++;
        }
        opString += to_string(count);
    }

    return opString;
}