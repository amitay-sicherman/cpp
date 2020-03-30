//
// Created by amitay.sich on 23/12/2019.
//

#include "Dense.h"
Dense::Dense(Matrix w, Matrix bias, ActivationType actType)
{
  _w=w;
  _bias=bias;
  _act=actType;
}
Matrix& Dense::getBias()
{
  return _bias;
}
Matrix& Dense::getWeights()
{
  return _w;
}
Activation Dense::getActivation()
{
  Activation act(_act);
  return act;
}
Matrix& Dense::operator()(Matrix const& input)
{
  auto m=new Matrix(input.getRows(),input.getCols());
  (*m)=this->getWeights()*input+this->getBias();
  *m=this->getActivation()(*m);
  return *m;
}
