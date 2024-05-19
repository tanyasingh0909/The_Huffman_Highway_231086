#include <iostream>

void printPattern(int n) {
    for (int i = 1; i <= n; ++i) {
        // Part 1: Ascending sequence from 1 to i
        for (int j = 1; j <= i; ++j) {
            std::cout << j;
        }
        
        std::cout << " ";

         // Part 2: Descending from i to 1 followed by ascending from 1 to i
        for (int j = i; j >= 1; --j) {
            std::cout << j;
        }
        for (int j = 1; j <= i; ++j) {
            std::cout << j;
        }
        
       std::cout << " ";

        // Part 3: Part 2 repeated
        for (int j = i; j >= 1; --j) {
            std::cout << j;
        }
        for (int j = 1; j <= i; ++j) {
            std::cout << j;
        }

       // Move to the next line
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    printPattern(n);

    return 0;
}