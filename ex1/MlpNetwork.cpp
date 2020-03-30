//
// Created by amitay.sich on 23/12/2019.
//

#include "MlpNetwork.h"
MlpNetwork::MlpNetwork(Matrix *w, Matrix *bias)
{
  for(int i=0;i<SIZE;++i)
  {
    _w[i]=w[i];
    _bias[i]=bias[i];
  }
}
Digit MlpNetwork::operator()(Matrix img)
{
  Matrix output;
  Matrix input;
  input=img;
  for (int i=0; i<SIZE-1;++i)
  {
    Dense level(_w[i],_bias[i],Relu);
    output=level(input);

    input=output;
  }
  Dense level(_w[SIZE-1],_bias[SIZE-1],Softmax);
  output=level(input);
  unsigned int value=0;
  float probability=0;
  for (int i =0 ; i< output.getRows()*output.getCols(); ++i)
  {
    if(output[i]>probability)
    {
      probability=output[i];
      value=i;
    }
  }
  Digit ans={value,probability};

  return  ans;
}