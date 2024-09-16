#include "src/calculator.h"

int main() {
 // Addition
    result = calculator(5.0, '+', 5.0);
    assert(result == 10.0);
    printf("Addition OK");

    result = calculator(5.0, '+', -5.0);
    assert(result == 0.0);
    printf("Addition with one negative number OK");

    result = calculator(-5.0, '+', -5.0);
    assert(result == -10.0);
    printf("Addition with two negative numbers OK");

    // Subtraction
    result = calculator(5.0, '-', 2.0);
    assert(result == 3.0);
    printf("Subtraction OK");

    result = calculator(5.0, '-', -10.0);
    assert(result == -5.0);
    printf("Subtraction with one negative number OK");

    result = calculator(-5.0, '+', -5.0);
    assert(result == 5.0);
    printf("Subtraction with two negative numbers OK");

    // Multiplication
    result = calculator(10.0, '*', 5.0);
    assert(result == 50.0);
    printf("Multiplication OK");

    // Division
    result = calculator(10.0, '/', 2.0);
    assert(result == 5.0);
    printf("Division OK");

    result = calculator(10.0, '/', 0.0);
    assert(result == 1); // Expected value for division by zero
    printf("Division by zero (second number) OK");

    // Integer overflow
    result = calculator(2147483647.0, '+', 1.0);
    assert(result != -2147483648.0); // If assert matches, integer overflow'd
    printf("Integer overflow OK");

    // Integer underflow
    result = calculator(-2147483648.0, '-', 1.0);
    assert(result != 2147483647.0); // If assert matches, integer underflow'd
    printf("Integer underflow OK");

    // Unexpected operator
    result = calculator(10.0, 'f', 11.0);
    assert(result == 1.0); // Expected value for invalid operator
    printf("Unexpected operator OK");

    // NULL value
    result = calculator(NULL, "+", 10.0);
    assert(result == 1); // Expected value for invalid operators
    printf("NULL value OK")

    return 0;
}
