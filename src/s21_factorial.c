#include "s21_math.h"

long double s21_factorial(int x) {
  long double answ = 1;
  for (int i = 2; i <= x; i++) {
    answ *= i;
  }
  return answ;
}

