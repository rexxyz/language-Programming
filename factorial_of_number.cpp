#include <iostream>
using namespace std;

// create a function
int factorial(int n)
{
    // check the condition
    if (n <= 1)
    {
        return 1;
    }

    // otherwise
    else
    {
        return n * factorial(n - 1);
    }
}

// driver code
int main()
{
    int n;
    cout << "Enter a number for factorial :" << endl;
    cin >> n;

    // call the function
    cout << "The Factorial of " << n << " is " << factorial(n) << endl;

    return 0;
    // Pull by Mabizarnovaris
}
