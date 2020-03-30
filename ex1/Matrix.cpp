//
// Created by amitay.sich on 16/12/2019.
//

#include "Matrix.h"
#define ERROR_DIM "Error: dim 0 not valid"
#define ERROR_INDEX "Error: matrix index out of range"
#define ERROR_DIM_MATRIX "Error: matrixes dimneed to be much to  * rules"
#define ERROR_SIZE "Error: the matrix must be same size"
#define ERROR_READ_FILE "Error: martix and file not equals"
/////////////////////////////////////////////
//constructors://///////////////////////////
///////////////////////////////////////////
Matrix::Matrix()
{

  _dims=new MatrixDims;
  _dims->cols=1;
  _dims->rows=1;
  _data=new float[1]();
  _data[0]=0;
}

Matrix::Matrix(int rows,int cols)
{
  if (rows>0 && cols>0)
  {
    _dims = new MatrixDims;
    _dims->cols = cols;
    _dims->rows = rows;
    _data = new float[rows*cols]();
    for (int i =0 ; i< rows*cols; ++i)
    {
      _data[i]= 0;
    }
  }
  else
  {
    std::cerr<<ERROR_DIM<<std::endl;
    exit(EXIT_FAILURE);
  }
}

Matrix::Matrix(Matrix &m)
{
    _dims = new MatrixDims;
    _dims->cols = m.getCols();
    _dims->rows = m.getRows();
    _data = new float[_dims->rows*_dims->cols]();
    for (int i =0 ; i< _dims->rows*_dims->cols; ++i)
    {
        _data[i]= m[i];
    }
}
Matrix::Matrix(Matrix const &m)
{
    _dims = new MatrixDims;
    _dims->cols = m.getCols();
    _dims->rows = m.getRows();
    _data = new float[_dims->rows*_dims->cols]();
    for (int i =0 ; i< _dims->rows*_dims->cols; ++i)
    {
        _data[i]= m[i];
    }
}
Matrix::~Matrix()
{
  delete _dims;
  delete[] _data;
}

/////////////////////////////////////////////
///////methods://///////////////////////////
///////////////////////////////////////////
int Matrix::getRows() const
{
  return _dims->rows;
}

int Matrix::getCols() const
{
  return _dims->cols;
}

Matrix& Matrix::vectorize()
{
  _dims->rows=_dims->rows*_dims->cols;
  _dims->cols=1;
  return *this;
}

void Matrix::plainPrint () const
{
  for (int i =0 ; i< _dims->rows*_dims->cols; ++i)
  {
    std::cout<<_data[i];
    if (i%_dims->cols==_dims->cols-1)
    {
        std::cout<<" ";
        std::cout <<std::endl;
    }
    else
    {
      std::cout<<" ";
    }
  }
}


/////////////////////////////////////////////
///////operators:///////////////////////////
///////////////////////////////////////////
Matrix& Matrix::operator=(Matrix const &rightM)
{
    if(this != &rightM)
    {
//        delete this;
//        auto m=new Matrix (rightM);
//        return *m;
        _dims->cols = rightM.getCols();
        _dims->rows = rightM.getRows();
        delete _data;
        _data= new float[_dims->rows*_dims->cols]();
        for (int i =0 ; i< _dims->rows*_dims->cols; ++i)
        {
            _data[i]= rightM[i];

        }
    }
    return *this;
}


Matrix& Matrix::operator*( Matrix const & rightM) const
{
  if (_dims->cols==rightM._dims->rows)
  {
    auto m=new Matrix(_dims->rows,rightM.getCols());

    for (int index=0; index < m->getRows()* m->getCols(); ++index)
    {
      float singleSum=0;
      int r=int(index/ m->getCols());
      int c=index % m->getCols();
      for (int i=0; i<rightM.getRows();++i)
      {
          singleSum+=_data[r* _dims->cols+i]*rightM[i* rightM._dims->cols+c];
      }
        (*m)[index]=singleSum ;
    }

      return *m;
  }
  else
  {
    std::cerr<<ERROR_DIM_MATRIX<<std::endl;
    exit(EXIT_FAILURE);
  }

}

Matrix& Matrix::operator*(int rightScaler) const
{
  auto m= new Matrix(this->getRows(),this->getCols());
  for(int i=0; i<_dims->cols*_dims->rows; ++i)
  {
    (*m)[i]=_data[i]*(float)rightScaler;
  }
  return *m;
}

Matrix operator*(int leftScaler, Matrix &m)
{
  {
    Matrix newM(m.getRows(),m.getCols());
    for(int i=0; i<m.getCols()*m.getRows(); ++i)
    {
      newM[i]=m[i]*(float)leftScaler;
    }
    return newM;
  }
}

Matrix Matrix::operator+(Matrix const &rightM) const
{
  if(_dims->rows == rightM._dims->rows && _dims->cols == rightM._dims->cols)
  {
    Matrix m(this->getRows(),this->getCols());

    for(int i=0; i<_dims->cols*_dims->rows; ++i)
    {
      m[i]=_data[i]+rightM[i];
    }
    return m;
  }
  else
  {
    std::cerr<<ERROR_SIZE<<std::endl;
    exit(EXIT_FAILURE);

  }
}

void Matrix::operator+=(const Matrix &rightM)
{
  if(_dims->rows == rightM._dims->rows && _dims->cols == rightM._dims->cols)
  {
    for (int i = 0; i < _dims->cols * _dims->rows; ++i) {
      _data[i] = _data[i] + rightM._data[i];
    }
  }
  else
  {
    std::cerr<<ERROR_SIZE<<std::endl;
    exit(EXIT_FAILURE);
  }
}


float Matrix::operator[](int index) const
{
  if (index < _dims->cols*_dims->rows && index>=0)
  {
    return _data[index];
  }
  std::cerr<<ERROR_INDEX<<std::endl;
  exit(EXIT_FAILURE);
}

float& Matrix::operator[](int index)
{
  if (index < _dims->cols*_dims->rows && index>=0)
  {
    float &ret=_data[index];
    return ret;
  }
  std::cerr<<ERROR_INDEX<<std::endl;
  exit(EXIT_FAILURE);

}
float Matrix::operator()(int row, int col) const
{
  if (row<this->getRows() && row>=0 && col>=0 && col<this->getCols())
  {
    return _data[row*_dims->cols+col];
  }
  std::cerr<<ERROR_INDEX<<std::endl;
  exit(EXIT_FAILURE);

}

float& Matrix::operator()(int row, int col)
{
  if (row<this->getRows() && row>=0 && col>=0 && col<this->getCols())
  {
    float &ret=_data[row*_dims->cols+col];
    return ret;
  }
  std::cerr<<ERROR_INDEX<<std::endl;
  exit(EXIT_FAILURE);
}

std::istream& operator>>(std::istream &in, Matrix &m)
{
  float f;
  int i=0;
  while (in.read(reinterpret_cast<char*>(&f), sizeof(float)))
  {
    if (i >= m._dims->rows*m._dims->cols)
    {
      std::cerr<<ERROR_READ_FILE<<std::endl;
      exit(EXIT_FAILURE);
    }
    m._data[i] = f;
    i++;
  }
  return in;
}

std::ostream& operator<<(std::ostream &out, const Matrix &m)
{
  {
    for (int i =0 ; i< m._dims->rows*m._dims->cols; ++i)
    {

      if(m[i]<=0.1)
      {
        out<<"  ";
      }
      else
      {
        out<<"**";
      }
      if (i%m._dims->cols==m._dims->cols-1)
      {
        out<<std::endl;
      }
    }
  }
  return out;
}