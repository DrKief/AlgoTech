#include "tp.h"

//-------------------------//
// SEUL FICHIER À MODIFIER //
//-------------------------//

// Global variable for Karatsuba sign propagation.
int sign = 1;

// Returns the number of significant digits by scanning from highest index down.
int number_length(number *X) {
  if (!X || !X->digit) return 0;
  for (int i = X->n - 1; i >= 0; i--) {
    if (X->digit[i] != 0) {
      return i + 1;
    }
  }
  return 0;
}

// Compares two integers based on length first, then digits from highest to lowest. Returns -1 (X<Y), 1 (X>Y), or 0.
int number_sign(number *X, number *Y) {
  int lenX = number_length(X);
  int lenY = number_length(Y);
  
  if (lenX < lenY) return -1;
  if (lenX > lenY) return 1;
  
  for (int i = lenX - 1; i >= 0; i--) {
    if (X->digit[i] < Y->digit[i]) return -1;
    if (X->digit[i] > Y->digit[i]) return 1;
  }
  return 0;
}

// Returns a number representing the sum X+Y with carry logic over max length.
number *number_addition(number *X, number *Y) {
  int lenX = number_length(X);
  int lenY = number_length(Y);
  int max_len = max(lenX, lenY);
  
  number *R = number_new(max_len + 1);
  int carry = 0;
  
  for (int i = 0; i < max_len; i++) {
    int dx = (i < lenX) ? X->digit[i] : 0;
    int dy = (i < lenY) ? Y->digit[i] : 0;
    int sum = dx + dy + carry;
    R->digit[i] = sum % BASE;
    carry = sum / BASE;
  }
  
  R->digit[max_len] = carry;
  return R;
}

// Returns a number representing |X-Y|. Adjusts global sign to indicate negative result if X < Y.
number *number_substraction(number *X, number *Y) {
  int cmp = number_sign(X, Y);
  number *A, *B;
  
  if (cmp >= 0) {
    A = X; B = Y;
    sign = 1;
  } else {
    A = Y; B = X;
    sign = -1;
  }
  
  int lenA = number_length(A);
  int lenB = number_length(B);
  number *R = number_new(lenA);
  int borrow = 0;
  
  for (int i = 0; i < lenA; i++) {
    int da = A->digit[i];
    int db = (i < lenB) ? B->digit[i] : 0;
    int diff = da - db - borrow;
    
    if (diff < 0) {
      diff += BASE;
      borrow = 1;
    } else {
      borrow = 0;
    }
    R->digit[i] = diff;
  }
  return R;
}

// Multiplies X by BASE^k. Shifts digits left by k positions.
number *shift(number *X, int k) {
  int len = number_length(X);
  if (len == 0) return number_new(1);
  
  number *R = number_new(len + k);
  for (int i = 0; i < len; i++) {
    R->digit[i + k] = X->digit[i];
  }
  return R;
}

// Returns the m lowest weight digits of X. Clamps to X->n to avoid out-of-bounds.
number *low(number *X, int m) {
  if (m <= 0) return number_new(1);
  int size = min(X->n, m);
  number *R = number_new(m);
  
  for (int i = 0; i < size; i++) {
    R->digit[i] = X->digit[i];
  }
  return R;
}

// Returns the remaining highest weight digits of X starting from index m.
number *high(number *X, int m) {
  if (m >= X->n) return number_new(1);
  int size = X->n - m;
  number *R = number_new(size);
  
  for (int i = 0; i < size; i++) {
    R->digit[i] = X->digit[i + m];
  }
  return R;
}

// Aligns X and Y to have the same array size via reallocation. Fills new space with 0.
void align_numbers(number *X, number *Y) {
  int target = max(X->n, Y->n);
  
  if (X->n < target) {
    X->digit = realloc_wrapper(X->digit, target * sizeof(short));
    for (int i = X->n; i < target; i++) X->digit[i] = 0;
    X->n = target;
  }
  
  if (Y->n < target) {
    Y->digit = realloc_wrapper(Y->digit, target * sizeof(short));
    for (int i = Y->n; i < target; i++) Y->digit[i] = 0;
    Y->n = target;
  }
}

// Naive Recursive Multiplication in O(n^2). Splits numbers in half and computes 4 sub-products.
number *number_multiplication_recursive(number *X, number *Y) {
  align_numbers(X, Y);
  int n = X->n;
  
  if (n == 1) {
    int prod = X->digit[0] * Y->digit[0];
    number *R = number_new(prod >= BASE ? 2 : 1);
    R->digit[0] = prod % BASE;
    if (prod >= BASE) R->digit[1] = prod / BASE;
    return R;
  }
  
  int m = (n + 1) / 2;
  number *x_low = low(X, m);
  number *x_high = high(X, m);
  number *y_low = low(Y, m);
  number *y_high = high(Y, m);

  number *a = number_multiplication_recursive(x_high, y_high);
  number *b = number_multiplication_recursive(x_low, y_high);
  number *c = number_multiplication_recursive(x_high, y_low);
  number *d = number_multiplication_recursive(x_low, y_low);

  number *b_plus_c = number_addition(b, c);
  number *a_shifted = shift(a, 2 * m);
  number *bc_shifted = shift(b_plus_c, m);

  number *t1 = number_addition(a_shifted, bc_shifted);
  number *res = number_addition(t1, d);

  // Free intermediate allocations to prevent memory leaks.
  number_multiple_free(x_low, x_high, y_low, y_high, a, b, c, d, b_plus_c, a_shifted, bc_shifted, t1, NULL);

  return res;
}

// Karatsuba Multiplication in O(n^1.59). Splits numbers in half and computes 3 sub-products.
number *number_multiplication_karatsuba(number *X, number *Y) {
  align_numbers(X, Y);
  int n = X->n;
  
  if (n <= 1) {
    int prod = X->digit[0] * Y->digit[0];
    number *R = number_new(prod >= BASE ? 2 : 1);
    R->digit[0] = prod % BASE;
    if (prod >= BASE) R->digit[1] = prod / BASE;
    return R;
  }
  
  int m = (n + 1) / 2;
  number *x_high = high(X, m);
  number *x_low = low(X, m);
  number *y_high = high(Y, m);
  number *y_low = low(Y, m);

  number *a = number_multiplication_karatsuba(x_high, y_high);
  number *c = number_multiplication_karatsuba(x_low, y_low);

  number *dx = number_substraction(x_high, x_low);
  int sx = sign; 

  number *dy = number_substraction(y_high, y_low);
  int sy = sign;

  number *d = number_multiplication_karatsuba(dx, dy);
  number *a_plus_c = number_addition(a, c);
  
  number *b;
  if (sx == sy) {
    b = number_substraction(a_plus_c, d);
  } else {
    b = number_addition(a_plus_c, d);
  }

  number *a_shifted = shift(a, 2 * m);
  number *b_shifted = shift(b, m);

  number *t1 = number_addition(a_shifted, b_shifted);
  number *res = number_addition(t1, c);

  // Free intermediate allocations to prevent memory leaks.
  number_multiple_free(x_high, x_low, y_high, y_low, a, c, dx, dy, d, a_plus_c, b, a_shifted, b_shifted, t1, NULL);

  return res;
}
