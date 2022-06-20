

#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>

#ifndef S21_PI
#define S21_PI 3.14159265358979323846264338327950288
#endif

#ifndef S21_INF
#define S21_INF 1. / 0.
#endif

#ifndef S21_NAN
#define S21_NAN 0. / 0.
#endif

#ifndef S21_EXP
#define S21_EXP 2.7182818284590452353602874713526624
#endif

#ifndef S21_EPS
#define S21_EPS 1e-9
#endif

long double s21_factorial(int x);
long double s21_pow_int(long double x, unsigned exp);
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  //  SRC_S21_MATH_H_
