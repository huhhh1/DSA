// #include<iostream>

// int main() {
//     if (__cplusplus == 202101L) std::cout << "C++23";
//     else if (__cplusplus == 202002L) std::cout << "C++20";
//     else if (__cplusplus == 201703L) std::cout << "C++17";
//     else if (__cplusplus == 201402L) std::cout << "C++14";
//     else if (__cplusplus == 201103L) std::cout << "C++11";
//     else if (__cplusplus == 199711L) std::cout << "C++98";
//     else std::cout << "pre-standard C++." << __cplusplus;
//     std::cout << "\n";
// }
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char choice;
    do
    {
        num = getPositiveInteger();
        printf("Factorial of %d = %d \n", num, factorial(num));
        printf("Do you want to calculate factorial for another number? (y /n)\n");
        scanf("%c", &choice);
        while (getchar() != '\n')
            printf("this is%cgap", choice);
    } while (choice == 'Y' || choice == 'y');
    printf("Exiting progam. Thank You \n");
    return 0;
}