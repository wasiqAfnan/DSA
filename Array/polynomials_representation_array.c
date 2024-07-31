#include <stdio.h>

int main() {
    // Polynomial: 2x^3 + 3x^2 + 0x + 7
    int poly[] = {7, 0, 3, 2};
    int n = sizeof(poly) / sizeof(poly[0]); // Number of terms in the polynomial

    // Printing the polynomial
    printf("The polynomial is: ");
    for (int i = n - 1; i >= 0; i--) {
        if (poly[i] != 0) { // Only print terms with non-zero coefficients
            printf("%dx^%d", poly[i], i);
            if (i > 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");

    return 0;
}

/*
### Explanation

1. **Array Representation**:
   - The array `poly[] = {7, 0, 3, 2}` represents the polynomial (2x^3 + 3x^2 + 0x + 7).
   - The index of the array represents the degree of the term, and the value at that 
   index represents the coefficient.

2. **Printing the Polynomial**:
   - We iterate through the array from the highest degree to the lowest 
   (i.e., from `n-1` to `0`).
   - We only print terms where the coefficient is not zero. For each term, 
   we print the coefficient followed by the variable `x` raised to the power of the index.
   - We add a `+` between terms to represent addition.

### Example Output

When you run the program, the output will be:

```OUTPUT
The polynomial is: 2x^3 + 3x^2 + 7x^0
```

This output correctly represents the polynomial (2x^3 + 3x^2 + 7). 
The term with (0x) is omitted because its coefficient is zero.
*/

