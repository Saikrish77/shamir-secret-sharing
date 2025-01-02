# shamir-secret-sharing
Implementation of a simplified Shamir's Secret Sharing algorithm to decode polynomial roots and find the constant term c. Handles dynamic user input and supports multiple bases for decoding.
# Shamir's Secret Sharing

This repository contains a C implementation of a simplified version of Shamir's Secret Sharing algorithm. The program decodes polynomial roots from user input, solves for the polynomial coefficients, and finds the constant term `c`. 

The program supports:
- Multiple bases for encoded values.
- Dynamic user input for `x` and `y` values.
- Lagrange interpolation to compute the constant term.

## Features

- Decodes `y` values encoded in various bases (e.g., binary, octal, decimal).
- Computes polynomial coefficients using Lagrange interpolation.
- Accepts dynamic input for number of roots, `x` values, and `y` values.

## Input Format

1. **Number of roots (`n`)**: Total number of roots provided.
2. **Minimum roots (`k`)**: Number of roots required to solve for the polynomial.
3. **`x` values**: The x-coordinates of the roots.
4. **`y` values**: Encoded values of y-coordinates and their respective bases.

## Output

The program computes and prints the constant term (`c`) of the polynomial.
