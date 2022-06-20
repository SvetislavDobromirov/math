#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double answ = 0;

  if (exp == 0 || base == 1) {
    answ = 1;
  } else if (exp != exp) {
    answ = exp;
  } else if (base == 0) {
    if (exp > 0)
      answ = 0;
    else
      answ = S21_INF;
  } else if (base == -1 && s21_fabs(exp) < 1) {
    answ = -S21_NAN;
  } else if (base == -1 && (exp == S21_INF || exp == -S21_INF)) {
    answ = 1;
  } else if (base != base) {
    answ = base;
  } else if (base - base != 0) {
    if (exp > 0) {
      answ = S21_INF;
    } else {
      answ = 0;
    }
  } else if (base < 0) {
    if (exp != s21_floor(exp)) {
      answ = -S21_NAN;
    } else if (s21_fabs(s21_fmod(exp, 2)) == 1) {
      base = -base;
      answ = -s21_exp(exp * s21_log(base));
    } else {
      base = -base;
      answ = s21_exp(exp * s21_log(base));
    }
  } else {
    if (exp - exp != 0 && exp == 1) exp = 1;
    answ = s21_exp(exp * s21_log(base));
  }
  return answ;
}
