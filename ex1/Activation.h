//
// Created by amitay.sich on 23/12/2019.
//

//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"
/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
  Relu,
  Softmax
};

class Activation
{
private:
  ActivationType _actType;
public:
  // constructors and Destructor:
  Activation(ActivationType actType);
  //methods:
  ActivationType getActivationType() const ;
  //Operators:
  Matrix operator()( Matrix &input ) const;
};

#endif //ACTIVATION_H
