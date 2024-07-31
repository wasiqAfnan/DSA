#include <stdio.h>

int main() {
    int degree;

    // Asking the user for the degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    // Array to store the coefficients
    int poly[degree + 1];

    // Asking the user to input the coefficients
    printf("Enter the coefficients starting from the constant term:\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }

    // Printing the polynomial
    printf("The polynomial is: ");
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) { // Only print terms with non-zero coefficients
            printf("%dx^%d", poly[i], i);
            if (i > 0 && poly[i - 1] != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");

    return 0;
}
/*
### Explanation

1. **User Input for Degree**:
   - The program first asks the user for the degree of the polynomial, 
   which is the highest exponent in the polynomial.

2. **Array to Store Coefficients**:
   - An array `poly[]` of size `degree + 1` is created to store the coefficients. 
   The size is `degree + 1` because the polynomial includes terms from 
   (x^0) to (x^{degree)

3. **User Input for Coefficients**:
   - The program then prompts the user to input the coefficients starting from the 
   constant term (coefficient of (x^0)) up to the term with the highest degree.

4. **Printing the Polynomial**:
   - The program prints the polynomial in a readable form by iterating from the 
   highest degree down to the constant term.
   - It skips any term where the coefficient is zero.
   - It ensures that a `+` sign is printed only between terms that actually 
   exist (i.e., have a non-zero coefficient).

### Example Execution

Suppose the user enters the following input:

- Degree: `3`
- Coefficients: `7`, `0`, `3`, `2`

The output will be:

```OUTPUT
The polynomial is: 2x^3 + 3x^2 + 7x^0
```

*/