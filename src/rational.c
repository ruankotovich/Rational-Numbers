#include "rational.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

typedef struct{
  int numerator;
  int denominator;
}TRationalData;

static int private_f_gcd(int bigger, int lower){
  int rest;

  do{
    rest = bigger % lower;
    if (rest == 0){
      return lower;
    }

    bigger = lower;
    lower = rest;

  }while(rest != 0);

  return 1;
}

static void private_f_rationalize(TRational *rational){
  TRationalData *data = rational->data;
  int numerator = data->numerator, denominator = data->denominator;
  int gcd;

  do{
    gcd = numerator > denominator? private_f_gcd(numerator, denominator) : private_f_gcd(denominator, numerator);
    numerator = numerator/gcd;
    denominator = denominator/gcd;
  }while(gcd != 1);

  data->denominator = denominator;
  data->numerator = numerator;
}

static int f_getNumerator(TRational* r1){
  TRationalData *data = r1->data;
  return data->numerator;
}

static int f_getDenominator(TRational* r1){
  TRationalData *data = r1->data;
  return data->denominator;
}

static void f_rationalPrint(TRational *rational){
  TRationalData *data = rational->data;
  printf("%d/%d\n", data->numerator,data->denominator);
}

static TRational* f_multiplication(TRational*  r1,TRational* r2){
  TRationalData *r1Data = r1->data;
  TRationalData *r2Data = r2->data;
  return new_rational(r1Data->numerator * r2Data->numerator,r1Data->denominator * r2Data->denominator);
}

static TRational* f_division(TRational*  r1,TRational* r2){
  TRationalData *r1Data = r1->data;
  TRationalData *r2Data = r2->data;
  return new_rational(r1Data->numerator * r2Data->denominator,r1Data->denominator * r2Data->numerator);
}

static TRational* f_sum(TRational* r1, TRational* r2){
  TRationalData *r1Data = r1->data;
  TRationalData *r2Data = r2->data;
  return new_rational(r2Data->denominator * r1Data->numerator + r1Data->denominator * r2Data->numerator, r1Data->denominator * r2Data->denominator);
}

static TRational* f_sub(TRational* r1, TRational* r2){
  TRationalData *r1Data = r1->data;
  TRationalData *r2Data = r2->data;
  return new_rational(r2Data->denominator * r1Data->numerator - r1Data->denominator * r2Data->numerator, r1Data->denominator * r2Data->denominator);
}

static float f_toFloat(TRational* r1){
  TRationalData *data = r1->data;
  return ((double)data->numerator) / ((double)data->denominator);
}

static int f_ceil(TRational*r1 ){
  float value = f_toFloat(r1);
  return ceil(value);
}

static int f_floor(TRational*r1 ){
  double value = f_toFloat(r1);
  return floor(value);
}

TRational *new_rational(int numerator, int denominator){
  TRational *newo = malloc(sizeof(TRational));
  TRationalData *newoData = malloc(sizeof(TRationalData));

  newo->data = newoData;
  newoData->denominator = denominator;
  newoData->numerator = numerator;

  newo->print = f_rationalPrint;
  newo->getNumerator = f_getNumerator;
  newo->getDenominator = f_getDenominator;
  newo->div = f_division;
  newo->mul = f_multiplication;
  newo->sum = f_sum;
  newo->sub = f_sub;
  newo->toFloat = f_toFloat;
  newo->ceil = f_ceil;
  newo->floor = f_floor;

  private_f_rationalize(newo);

  return newo;
}

TRational* new_rationalFromFloat(float no){
  int moveds = 0;
  int integerNo = floor(no);

  while(fmod(no,integerNo) != 0){
    moveds++;
    no*=10;
    integerNo = floor(no);
  }

  return new_rational(integerNo, moveds>0? (int)pow(10,moveds) :1);
}
