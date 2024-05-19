 //Write a code to make a fully functional calculator which can perform addition, subtraction, multiplication, division, mod, remainder, trigonometric and exponential calculations (like lnX + SinX, as provided by user).
//Note: You must have to make functions for dierent operators.
//Example: Input - Operators = ln,+,sin (There can be ‘n’ number of operators)
//Values = 1 (X=1) (There can be ‘n’ number of values)
//Output - Output should be the final value of given expression.


#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <functional>
#include <map>



// Function definitions


double add_func(double a, double b) //Add function
{
     return a + b;
      }


double subtract_func(double a, double b) //Subtraction function
{
     return a - b; 
}


double multiply_func(double a, double b) //Multiplicaion Function
{ 
    return a * b; 
    }


double divide_func(double a, double b) //Division Function
{
    if (b == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return a / b;
}


int mod_func(int a, int b) //Mod Function
{ 
    return a % b; 
    }


double remainder_func(double a, double b) //Remainder Function
{ 
    return std::remainder(a, b);
 }


double sin_Func(double x) //Sine function
{
     return std::sin(x); 
     }


double cos_Func(double x) //Cosine function
{
     return std::cos(x); 
}


double tan_Func(double x) //tan function
{ 
    return std::tan(x); 
}


double exp_Func(double x) //Exponentation Function
{
     return std::exp(x);
      }


double ln_Func(double x) //Logaritmic Function
 {
    if (x <= 0) {
        std::cerr << "Error: Logarithm of non-positive number!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::log(x);
}




int main() {
    std::map<std::string, std::function<double(double)>> unaryOperations = {
        {"sin", sin_Func},
        {"cos", cos_Func},
        {"tan", tan_Func},
        {"exp", exp_Func},
        {"ln", ln_Func}
    };

    std::map<std::string, std::function<double(double, double)>> binaryOperations = {
        {"+", add_func},
        {"-", subtract_func},
        {"*", multiply_func},
        {"/", divide_func},
        {"mod", [](double a, double b) { return static_cast<double>(mod_func(static_cast<int>(a), static_cast<int>(b))); }},
        {"rem", remainder}
    };

    std::string operatorsInput, valuesInput;
    std::cout << "Enter operators (space-separated, e.g., + sin ln): ";
    std::getline(std::cin, operatorsInput);
    std::cout << "Enter values (space-separated, e.g., 1 2): ";
    std::getline(std::cin, valuesInput);

    std::istringstream opStream(operatorsInput);
    std::istringstream valStream(valuesInput);

    std::vector<std::string> operators;
    std::vector<double> values;

    std::string op;
    double val;

    while (opStream >> op) {
        operators.push_back(op);
    }

    while (valStream >> val) {
        values.push_back(val);
    }

    if (values.empty()) {
        std::cerr << "No values provided!" << std::endl;
        return 1;
    }

    double result = values[0];
    size_t valIndex = 1;

    for (const auto& oper : operators) {
        if (unaryOperations.find(oper) != unaryOperations.end()) {
            result = unaryOperations[oper](result);
        } else if (binaryOperations.find(oper) != binaryOperations.end()) {
            if (valIndex >= values.size()) {
                std::cerr << "Not enough values for binary operation!" << std::endl;
                return 1;
            }
            result = binaryOperations[oper](result, values[valIndex++]);
        } else {
            std::cerr << "Unknown operator: " << oper << std::endl;
            return 1;
        }
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}

