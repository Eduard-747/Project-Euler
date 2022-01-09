// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//     1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
// By considering the terms in the Fibonacci sequence whose values do not exceed n , find the sum of the even-valued terms.

#include <iostream>

void fib(const int& n , int& sum)
{
    int a = 0, b = 1, c ;

    for(int i = 2; ; i++)
    {
        c = a + b;
        a = b;
        b = c;
        if(b > n) { 
            break ; 
        } else if(b % 2 == 0) {
            sum += b ;
        }
    }
}

int main()
{
    int n ;
    int sum {} ;
    std::cout << "Eneter n: " ;
    std::cin >> n ;
    fib(n,sum) ;
    std::cout << "sum even-valued term: " << sum ;
    return 0;
}