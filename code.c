#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert string from given base to integer
long long decode_value(const char *value, int base) {
    long long result = 0;
    while (*value) {
        char digit = *value++;
        int num;
        if (digit >= '0' && digit <= '9') {
            num = digit - '0';
        } else if (digit >= 'A' && digit <= 'Z') {
            num = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'z') {
            num = digit - 'a' + 10;
        } else {
            fprintf(stderr, "Invalid character in value.\n");
            exit(1);
        }
        if (num >= base) {
            fprintf(stderr, "Digit out of range for base.\n");
            exit(1);
        }
        result = result * base + num;
    }
    return result;
}

// Function to compute Lagrange interpolation
double lagrange_interpolation(int x[], long long y[], int k, int target_x) {
    double result = 0.0;

    for (int i = 0; i < k; i++) {
        double term = y[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term *= (double)(target_x - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n, k;

    // Read number of roots and required minimum roots
    printf("Enter the number of roots (n): ");
    scanf("%d", &n);
    printf("Enter the minimum number of roots (k): ");
    scanf("%d", &k);

    // Read x values
    int x[n];
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%d", &x[i]);
    }

    // Read y values and their bases
    char y_encoded[n][256];
    int bases[n];
    printf("Enter the y values and their bases:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d] (encoded value): ", i + 1);
        scanf("%s", y_encoded[i]);
        printf("base[%d]: ", i + 1);
        scanf("%d", &bases[i]);
    }

    // Decode y values
    long long y[n];
    for (int i = 0; i < n; i++) {
        y[i] = decode_value(y_encoded[i], bases[i]);
    }

    // Find constant term (c) using the first k values
    double secret = lagrange_interpolation(x, y, k, 0);

    // Output the result
    printf("The constant term (c) of the polynomial is: %.0f\n", secret);

    return 0;
}
