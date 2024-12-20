#include <stdio.h>
#include <string.h>

#define MAX 100

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

double calculate(const char* expr) {
    double number = 0;    
    double stack[MAX];    
    int top = -1;
    char last_operator = '+';  
    int expecting_operator = 0;

    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == ' ') {     
            continue;
        } else if (is_digit(expr[i])) {  
            if (expecting_operator == 0) {
                number = 0;
                while (i < strlen(expr) && is_digit(expr[i])) {
                    number = number * 10 + (expr[i] - '0');
                    i++;
                }
                i--;  

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
                expecting_operator = 1; 
            } else {
                printf("Invalid expression\n");
                return 0;
            }
        }
        else if (is_operator(expr[i])) {     
            if (expecting_operator == 0) {
                printf("Invalid expression\n");
                return 0;
            }
            last_operator = expr[i];
            expecting_operator = 0; 
        } else {       
            printf("Invalid expression\n");
            return 0;
        }
    }

    if (expecting_operator == 0) { 
        printf("Invalid expression\n");
        return 0;
    }

    double result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    return result;
}

int main() {
    char expression[MAX];

    printf("Enter the expression: ");
    fgets(expression, MAX, stdin);  

    double result = calculate(expression);

    if (result != 0 || expression[0] == '0') {  
        printf("Result: %.2f\n", result);
    }

    return 0;
}
