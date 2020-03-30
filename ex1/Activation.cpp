//
// Created by amitay.sich on 23/12/2019.
//

#include "Activation.h"
#include "math.h"

Activation::Activation(ActivationType actType)
{
  _actType=actType;
}

ActivationType Activation::getActivationType() const
{
  return _actType;
}

Matrix Activation::operator()(Matrix &input ) const
{
  Matrix outPut(input);
  if (_actType==Softmax)
  {
    double factor=0;
    for (int i =0 ; i< input.getRows()*input.getCols(); ++i)
    {
      factor+=std::exp((double)input[i]);
    }
    //factor=1/factor;
    for (int i =0 ; i< input.getRows()*input.getCols(); ++i)
    {
      outPut[i]=(float)(std::exp((double )input[i])/factor);
    }
      return outPut;
  }

  if (_actType==Relu)
  {
      for (int i =0 ; i< input.getRows()*input.getCols(); ++i)
      {
          if (input[i] >= 0) {
              outPut[i] = input[i];
          }
          else
          {
              outPut[i]=0;
          }
      }
  }
  return outPut;
}
