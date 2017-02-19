#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>

class TVector
{
private:
	double * mas;
	int n;
public:

	TVector();
	
  TVector(double*, int);
	
  ~TVector();
	
  TVector& operator=(const TVector&);
	
  double operator[](size_t) const;
	
  double & operator[](size_t);
	
  int getN();
	
  void print();
  
};

double* operator+(TVector&, TVector&);

#endif //VECTOR_VECTOR_H
