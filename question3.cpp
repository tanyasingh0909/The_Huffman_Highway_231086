#include <iostream>
#include <climits> // for INT_MAX and INT_MIN

int main() {
    const int SIZE = 10;
    int examScores[SIZE];
    
    // Prompt user to input exam scores
    std::cout << "Enter 10 exam scores: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> examScores[i];
    }

    // Calculate average score
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += examScores[i];
    }
    double average = static_cast<double>(sum) / SIZE;

    // Find highest and lowest scores
    int highest = INT_MIN;
    int lowest = INT_MAX;
    for (int i = 0; i < SIZE; ++i) {
        if (examScores[i] > highest) {
            highest = examScores[i];
        }
        if (examScores[i] < lowest) {
            lowest = examScores[i];
        }
    }

    // Count scores above and below average
    int aboveAverageCount = 0;
    int belowAverageCount = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (examScores[i] > average) {
            aboveAverageCount++;
        } else if (examScores[i] < average) {
            belowAverageCount++;
        }
    }

    // Display the statistics

    std::cout << "Average exam score: " << average << std::endl;
    std::cout << "Highest exam score: " << highest << std::endl;
    std::cout << "Lowest exam score: " << lowest << std::endl;
    std::cout << "Number of exam scores above the average: " << aboveAverageCount << std::endl;
    std::cout << "Number of exam scores below the average: " << belowAverageCount << std::endl;

    return 0;
}