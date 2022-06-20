#include "s21_math.h"

long double s21_sqrt(double x) {
  long double answ;
  if (x != x) {
    answ = x;
  } else if (x == S21_INF) {
    answ = S21_INF;
  } else if (x == -S21_INF) {
    answ = S21_NAN;
  } else if (x == 0) {
    answ = 0;
  } else {
    answ = s21_pow(x, 0.5);
  }
  return answ;
}
