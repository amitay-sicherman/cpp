//
// Created by amitay.sich on 23/12/2019.
//

//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

// Insert MlpNetwork class here...

#include "Matrix.h"
#include "Activation.h"
#include "Dense.h"
#include "Digit.h"
#define SIZE 4

class MlpNetwork
{
private:
  Matrix _w[SIZE];
  Matrix _bias[SIZE];
public:
  // constructors and Destructor:
  MlpNetwork(Matrix w[], Matrix bias[]);
  //Methods:
  //Operators:
  Digit operator()(Matrix img);

};


#endif // MLPNETWORK_H