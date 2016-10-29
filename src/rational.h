#ifndef _XYAH_GITFLOW_EXAMPLE_RATIONAL_H_
#define _XYAH_GITFLOW_EXAMPLE_RATIONAL_H_

typedef struct t_rational TRational;

typedef TRational* (*FRationalSum)(TRational*,TRational*);
typedef TRational* (*FRationalSub)(TRational*,TRational*);
typedef TRational* (*FRationalDiv)(TRational*,TRational*);
typedef TRational* (*FRationalMul)(TRational*,TRational*);
typedef void (*FRationalPrint)(TRational*);

typedef struct t_rational{

  void *data;

  FRationalSum rationalSum;
  FRationalSub rationalSub;
  FRationalDiv rationalDiv;
  FRationalMul rationalMul;
  FRationalPrint rationalPrint;

}TRational;

TRational *i2r(int);
TRational *new_rational(int,int);


#endif //_XYAH_GITFLOW-EXAMPLE_RATIONAL_H_
