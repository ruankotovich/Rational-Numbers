### Rational Numbers ###

This is a simple implementation of rational numbers in C, it contains all the four basic operations using rational numbers, a conversion of a rational number into float, floor and ceil casting of the rational number and two constructors, the first using integers and the second based in float input.


##### Implementation Overview

- `rational.h` typedefs

```
typedef int (*FRationalGetNumerator)(TRational*);
typedef int (*FRationalGetDenominator)(TRational*);
typedef TRational* (*FRationalSum)(TRational*,TRational*);
typedef TRational* (*FRationalSub)(TRational*,TRational*);
typedef TRational* (*FRationalDiv)(TRational*,TRational*);
typedef TRational* (*FRationalMul)(TRational*,TRational*);
typedef float (*FRationalToDouble)(TRational*);
typedef int (*FRationalFloor)(TRational*);
typedef int (*FRationalCeil)(TRational*);
typedef void (*FRationalPrint)(TRational*);

TRational *new_rationalFromFloat(float);
TRational *new_rational(int,int);
```

- `rational.c` functions

```
void f_rationalPrint;
int f_getNumerator;
int f_getDenominator;
TRational* f_division;
TRational* f_multiplication;
TRational* f_sum;
TRational* f_sub;
float f_toFloat;
int f_ceil;
int f_floor;
```
