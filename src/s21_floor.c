#include "s21_math.h"

long double s21_floor(double x) {
  if (x - x != 0) {
  } else if (x == (long long int)x) {
  } else if (x > 0) {
    x = (long long int)x;
  } else {
    x = (long long int)x - 1;
  }
  return x;
}
