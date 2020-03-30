//
// Created by amitay.sich on 23/12/2019.
//

#ifndef CPP_EX1_DENSE_H
#define CPP_EX1_DENSE_H

#include "Matrix.h"
#include "Activation.h"
class Dense
{
private:
  Matrix _w;
  Matrix _bias;
  ActivationType _act;
public:
  // constructors and Destructor:
  Dense(Matrix w, Matrix bias, ActivationType actType);  //methods:
  //Methods:
  Matrix& getWeights() ;
  Matrix& getBias() ;
  Activation getActivation() ;
  //Operators:
  Matrix& operator()(Matrix const &input);

};

#endif // CPP_EX1_DENSE_H
