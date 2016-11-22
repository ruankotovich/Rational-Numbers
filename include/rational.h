#ifndef _XYAH_GITFLOW_EXAMPLE_RATIONAL_H_
#define _XYAH_GITFLOW_EXAMPLE_RATIONAL_H_

typedef struct t_rational TRational;

typedef int (*FRationalGetNumerator)(TRational*);
typedef int (*FRationalGetDenominator)(TRational*);
typedef TRational* (*FRationalSum)(TRational*,TRational*);
typedef TRational* (*FRationalSub)(TRational*,TRational*);
typedef TRational* (*FRationalDiv)(TRational*,TRational*);
typedef TRational* (*FRationalMul)(TRational*,TRational*);
typedef double (*FRationalToDouble)(TRational*);
typedef int (*FRationalFloor)(TRational*);
typedef int (*FRationalCeil)(TRational*);
typedef void (*FRationalPrint)(TRational*);

typedef struct t_rational{

  void *data;

  FRationalGetNumerator getNumerator;
  FRationalGetDenominator getDenominator;
  FRationalSum sum;
  FRationalSub sub;
  FRationalDiv div;
  FRationalMul mul;
  FRationalToDouble toDouble;
  FRationalPrint print;
  FRationalCeil ceil;
  FRationalFloor floor;

}TRational;

TRational *new_rationalFromFloat(float);
TRational *new_rationalFromCharArray(char*);
TRational *new_rational(int,int);


#endif //_XYAH_GITFLOW-EXAMPLE_RATIONAL_H_
