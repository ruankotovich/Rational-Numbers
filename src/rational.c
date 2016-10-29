#include "rational.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct{
  int numerator;
  int denominator;
}TRationalData;

static int af_gcd(int bigger, int lower){
  int rest;

  do{
    rest = bigger % lower;

    if (!rest){
      return lower;
    }

    bigger = lower;
    lower = rest;
  }while(!rest);

  return 1;
}

static void f_rationalPrint(TRational *rational){
  TRationalData *data = rational->data;
  printf("%d/%d\n", data->numerator,data->denominator);
}

static void af_rationalize(TRational *rational){
  TRationalData *data = rational->data;
  int numerator = data->numerator, denominator = data->denominator;
  int gcd;

  do{
    gcd = numerator > denominator? af_gcd(numerator, denominator) : af_gcd(denominator, numerator);
    numerator = numerator/gcd;
    denominator = denominator/gcd;
  }while(gcd != 1);

  data->denominator = denominator;
  data->numerator = numerator;
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

TRational *new_rational(int numerator, int denominator){
  TRational *newo = malloc(sizeof(TRational));
  TRationalData *newoData = malloc(sizeof(TRationalData));

  newo->data = newoData;
  newoData->denominator = denominator;
  newoData->numerator = numerator;

  newo->rationalPrint = f_rationalPrint;
  newo->rationalDiv = f_division;
  newo->rationalMul = f_multiplication;
  newo->rationalSum = f_sum;
  newo->rationalSub = f_sub;

  af_rationalize(newo);

  return newo;
}
