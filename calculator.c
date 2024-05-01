#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


int main(int argc,string argv[]) {
    if (argc > 1000000000 || argc % 2 != 0) {
        printf("Usage: %s <num1> <op1> <num2> [<op2> <num3> ...]\n", argv[0]);
        return 1; // Refer Readme.
    }

    double result = atof(argv[1]); // Initialize result with the first number

    for (int i = 2; i < argc - 1; i += 2) {
        char operator = argv[i][0];
        double operand = atof(argv[i + 1]);

        switch (operator) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case 'x':
                result *= operand;
                break;
            case '/':
                if (operand != 0) {
                    result /= operand;
                } else {
                    printf("Error: Division by zero\n");
                    return 2; // Refer Readme.
                }
                break;
            default:
                printf("Error: Invalid operator '%c'\n", operator);
                return 3; // Refer Readme.
        }
    }

    printf("Result: %.2lf\n", result);

    return 0;
}
