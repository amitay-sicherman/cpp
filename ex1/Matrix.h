//
// Created by amitay.sich on 16/12/2019.
//
#include "iostream"
#ifndef MATRIX_H
#define MATRIX_H

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */


//todo: correct the error handling


typedef struct MatrixDims
{
  int rows, cols;
} MatrixDims;

class Matrix
{
  private:
    MatrixDims* _dims;
    float *_data;

  public:
    //constructors and Destructor:
    Matrix(int rows,int cols);
    Matrix();
    Matrix(Matrix &m);
    Matrix(Matrix const &m);

    ~Matrix();
    //methods:
    int getRows() const ;
    int getCols() const ;
    Matrix& vectorize();
    void plainPrint() const;
    //Operators:
    Matrix& operator=( Matrix const & rightM) ;
   // Matrix& operator=( Matrix rightM) ;

    Matrix& operator*( Matrix const & rightM) const;
//    Matrix operator*( Matrix rightM) ;

    Matrix& operator*(int rightScaler) const;
    friend Matrix operator*(int leftScaler, Matrix& m) ;
    Matrix operator+( Matrix const &rightM) const;
    void operator+=(const Matrix& rightM);

    float operator()( int row, int col) const;
    float& operator()( int row, int col);

    float operator[](int index) const ;
    float& operator[](int index) ;

    friend std::istream & operator >> (std::istream &in,  Matrix &m);
    friend std::ostream & operator << (std::ostream &out, const Matrix &m);


};

#endif // CPP_EX1_MATRIX_H
