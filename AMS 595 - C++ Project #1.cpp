#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// Question 2
void print_vector(std::vector<int> v) {
    std:cout << "[ ";
    // print out element in each vector with a space
    for (int element : v) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}


// Question 4a
bool isprime(int n) {
    bool result;
    // set result to true
    result = true;
    // change result if value not prime (0 and 1 are not prime)
    if (n == 0 | n == 1) {
        result = false;
    }
    // if the testing value is divisible by a number, it is not prime and breaks the cycle
    for (int i = 2; i <= n/2; ++i) {
        if (n % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}


// Question 4b
std::vector<int> factorize(int n) {
    // store factors into vector
    std::vector<int> answer;
    // if the testing value is divisible by a number, it is a factor and is added to the vector called answer
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            answer.push_back(i);
        }
    }
    return answer;
}


// Question 4c
std::vector<int> prime_factorize(int n) {
    // store factors into vector
    std::vector<int> answer;
    // divide number by 2 until not possible and place into vector called answer
    while (n % 2 == 0) {
        answer.push_back(2);
        n /= 2;
    }
    // divide number by 3 until not possible and then increment factor by one to be placed into vector
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            answer.push_back(i);
            n /= i;
        }
    }
    return answer;
}


// Question 5
void PascalTriangle(int nrow) {
    // iterate over each row
    for (int r = 0; r < nrow; ++r) {
        // first number of each row is 1
        int num = 1;
        // print the numbers in each row and update the next number
        for (int c = 0; c <= r; ++c) {
            std::cout << num << " ";
            num = num * (r - c) / (c + 1);
        }
        // move onto the next row
        std::cout << std::endl;
    }
}


// MAIN FUNCTION
int main() {
    
    // Question 1
    int n;

    cout << "Type a number: ";
    cin >> n;

    switch(n) {
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl;
            break;
        default:
            cout << "other value" << endl;
    }


    // Question 3
    int n1 = 1, n2 = 2, nterm = 0;

    cout << "Fibonacci Sequence: " << n1 << " " << n2;
    nterm = n1 + n2;

    while (nterm <= 4000000) {
        cout << " " << nterm;
        n1 = n2;
        n2 = nterm;
        nterm = n1 + n2;
    }


    // Question 4a test cases
    std::cout << '\n' << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';

    // Question 4b test cases
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));

    // Question 4c test cases
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
    

    // Question 5 test case with user input
    int r;
    std::cout << "Enter number of rows for Pascal's Triangle: ";
    std::cin >> r;

    PascalTriangle(r);
}