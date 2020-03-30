//
// Created by asicherm on 29/12/2019.
//
#include <vector>
#include "cmath"
#include <string>
#ifndef CPP2_FRACTAL_H
#define CPP2_FRACTAL_H



/**
 * abstract class of fractal
 */
class Fractal
{
protected:
    int _dim;
    int _lineLenght;
    std::vector<int> _shape;
    std::vector<std::vector<int>> _emptyPlaces;
    int _basicSize;
    /**
    * create the fractal
    */
    void create() ;
    /**
     * plot the fractal
     */
    void plot() ;


public:
    ~Fractal();
};


/**
 * SierpinskiCarpet, inherit from fractal.
 * dim is the dim of the fractal
 */
class SierpinskiCarpet:public Fractal
{
public:
    /**
     * constractor of the SierpinskiCarpet
     * @param dim : the fractal dim (0<dim<6)
     */
    explicit SierpinskiCarpet(int dim);
};

/**
 * SierpinskiTriangle, inherit from fractal.
 */
class SierpinskiTriangle:public Fractal
{
public:
    /**
     * constractor of the SierpinskiTriangle
     * @param dim : the fractal dim (0<dim<6)
     */
    explicit SierpinskiTriangle(int dim);
};

/**
 * Vicsekfractal, inherit from fractal.
 */
class Vicsekfractal:public Fractal
{
public:
    /**
     * constenctor the the Vicsekfractal
     * @param dim : the fractal dim (0<dim<6)
     */
    explicit Vicsekfractal(int dim);
};

/**
 * the FractalFactory-
 * he get fractal type and dim, and then create the fractal
 */
class FractalFactory
{
public:
    /**
     * print fractal to the screen
     * @param type - the type of the fractal (1<=type<=3)
     * @param dim : the fractal dim (0<dim<6)
     */
    static void make(int type,int dim);
    /**
     * @return the number of fractal that have (from 1 to getNum())
     */
    static int getNum(){ return 3;}
    /**
     * @return the number of dims that lagel to fractal (from 1 to getDim())
     */
    static int getDim(){ return 6;}
};
/**
 * the class get a string that contain a .csv file, check that he his valid, and return the data in the right pattarn
 */
class CSVReader
{
private:
    std::string _fileName;
public:
    /**
     *
     */
    explicit CSVReader(std::string);
    /**
     *
     * @return
     */
    std::vector<std::vector<int>> getData();
};


#endif //CPP2_FRACTAL_H
