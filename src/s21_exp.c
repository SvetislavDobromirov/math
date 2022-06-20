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


long double s21_exp_orig(double x) {
  long double res = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(res) > S21_EPS) {
    res *= x / i;
    i += 1;
    temp += res;
    if (temp > DBL_MAX) {
      temp = S21_INF;
      break;
    }
  }
  if (flag == 1) {
    if (temp > DBL_MAX) {
      temp = 0;
    } else {
      temp = 1. / temp;
    }
  }
  if (temp > DBL_MAX) {
    return S21_INF;
  }
  return temp;
}
