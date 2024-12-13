#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Complete structure of the code is explained in comments

// Checks if the character is an operator
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Calculate the expression
double calculate(const char* expr) {
    double number = 0;    // Stores the number read from the expression
    double stack[MAX];    
    int top = -1;
    char last_operator = '+';  // Stores the previous operator

    for (int i = 0; i < strlen(expr); i++) {
        if (isspace(expr[i])) {     // Check if the character is a space
            continue;
        } else if (isdigit(expr[i])) {  // Check if the character is a digit (number)
            number = 0;
            while (i < strlen(expr) && isdigit(expr[i])) {
                number = number * 10 + (expr[i] - '0');
                i++;
            }
            i--;  // Adjust the index after reading the number

            // Does the calculation based on the previous operator
            if (last_operator == '*') {
                stack[top] = stack[top] * number;
            } else if (last_operator == '/') {
                if (number == 0) {
                    printf("Error: Division by zero.\n");
                    return 0;
                }
                stack[top] = stack[top] / number;
            } else {
                stack[++top] = (last_operator == '+') ? number : -number;
            }
        }
        else if (is_operator(expr[i])) {     // Check if the character is an operator
            last_operator = expr[i];
        } else {       // If none of the above conditions are met, the character is invalid
            printf("Error: Invalid character in the expression\n");
            return 0;
        }
    }

    double result = 0;

    // Calculate the final result by adding all the elements in the stack
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    char expression[MAX];

    printf("Enter the expression: ");
    fgets(expression, MAX, stdin);  // Reading a string of characters with a maximum size of 100

    double result = calculate(expression);

    // If the result is an integer, print as an integer; otherwise, print as a decimal
    if ((int)result == result) {
        printf("Result: %.0f\n", result);
    } else {
        printf("Result: %.2f\n", result);
    }

    return 0;
}