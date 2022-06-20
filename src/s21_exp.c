#include "s21_math.h"

long double s21_exp(double x) {
  long double answ = 1;

  if (x != x) {
    answ = x;
  } else if (x == S21_INF) {
    answ = S21_INF;
  } else if (x - x != 0) {
    answ = 0;
  } else {
    int sign = x < 0 ? -1 : 1;
    x = s21_fabs(x);
    for (int i = 1; i < 100; i++) {
      answ += s21_pow_int(x, i) / s21_factorial(i);
    }
    if (sign == -1) {
      answ = 1 / answ;
    }
    if (answ > DBL_MAX) {
      answ = S21_INF;
    }
  }
  return answ;
}
