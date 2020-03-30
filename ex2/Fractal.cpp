//
// Created by asicherm on 29/12/2019.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "Fractal.h"
#define ERROR_MSG "Invalid input"


//todo: check that dim is >0 and <6

Fractal::~Fractal()
{
    _shape.clear();

}
SierpinskiCarpet::SierpinskiCarpet (int dim){
    _emptyPlaces={{1,1}};
    _basicSize=3;
    _dim=dim;
    _lineLenght=std::pow(_basicSize,_dim);
    auto shape=new std::vector<int>(_lineLenght*(_lineLenght+1),0);
    _shape=*shape;
    delete shape;
    create();
    plot();
}

SierpinskiTriangle::SierpinskiTriangle (int dim){
    _emptyPlaces={{1,1}};
    _basicSize=2;
    _dim=dim;
    _lineLenght=std::pow(_basicSize,_dim);
    auto shape=new std::vector<int>(_lineLenght*(_lineLenght+1),0);
    _shape=*shape;
    create();
    plot();
}
Vicsekfractal::Vicsekfractal(int dim){
    _emptyPlaces={{0,1},{1,0},{1,2},{2,1}};
    _basicSize=3;
    _dim=dim;
    _lineLenght=std::pow(_basicSize,_dim);
    auto shape=new std::vector<int>(_lineLenght*(_lineLenght+1),0);
    _shape=*shape;
    create();
    plot();
}

void Fractal::plot() {
    for(auto single:_shape)
    {
        switch(single)
        {
            case 0:
                std::cout<<std::endl;
                break;
            case 1:
                std::cout<<' ';
                break;
            case 2:
                std::cout<<"#";
                break;
            default:
                std::cout<<"";
        }
    }
    std::cout<<std::endl;
}



void Fractal::create() {

    int counter=0;

    for (int i=0; i<_lineLenght*_lineLenght;++i)
    {
        int row = i/_lineLenght;
        int col=i%_lineLenght;
        for (int j=0; j<_dim; ++j )
        {
            for (auto s:_emptyPlaces)
            {

                if (row/int(std::pow(double(_basicSize),(double)j))%_basicSize==s[0] &&
                    col/int(std::pow(double(_basicSize),(double)j))%_basicSize==s[1])
                {
                    _shape[counter]=1;
                    //todo: break the double loop
                }
            }
        }
        if (_shape[counter]==0)
        {
            _shape[counter]=2;
        }
        ++counter;
        if(i%_lineLenght==_lineLenght-1)
        {
            _shape[counter]=0;
            ++counter;
        }
    }
}
void FractalFactory::make(int type,int dim) {

    if (type==1)
    {
        SierpinskiCarpet s(dim);
        return;
    }
    if (type==2)
    {
        SierpinskiTriangle s(dim);
        return;
    }
    if (type==3)
    {
        Vicsekfractal s(dim);
        return;
    }
}
CSVReader::CSVReader(std::string filePath)
{
    std::string VALID_FILE =".csv";
    if(filePath.length()<=4 ||
       filePath.compare(filePath.length()-VALID_FILE.length() ,VALID_FILE.length(),VALID_FILE)!=0)
    {
        std::cerr<<ERROR_MSG<<std::endl;
        exit(EXIT_FAILURE);
    }
    _fileName=filePath;
}


std::vector<std::vector<int>> CSVReader::getData()
{
    //open the file:
    std::ifstream file(_fileName);
    if (!file.good())
    {
        std::cerr<<ERROR_MSG<<std::endl;
        exit(EXIT_FAILURE);
    }

    //red the file line by line:
    std::vector<std::vector<int> > dataList;
    std::string line = "";
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        std::vector<int> intVec;
        //check each line if she is in the correct templete, and push here to the data:
        boost::algorithm::split(vec, line, boost::is_any_of(","));
        //just 2 col in line:
        if(vec.size()!=2)
        {
            file.close();
            std::cerr<<ERROR_MSG<<std::endl;
            exit(EXIT_FAILURE);
        }
        //check every single value in the line
        for (unsigned long i = 0 ; i < vec.size()  ; i++)
        {
            //the value can not convert to int:
            if(vec[i].empty() || !std::all_of(vec[i].begin(), vec[i].end(),::isdigit) )
            {
                file.close();
                std::cerr<<ERROR_MSG<<std::endl;
                exit(EXIT_FAILURE);
            }
            //the data is lagel, convert here to int, and push it to the data/
            int checkInt=std::stoi(vec[i]);
            if ((i==0 && checkInt>=1 && checkInt<=FractalFactory::getNum())
                ||(i==1 && checkInt>=1 && checkInt<=FractalFactory::getDim()))
            {
                intVec.push_back(checkInt);
            }
            //the numbers not much to the types/dims
            else
            {
                file.close();
                std::cerr<<ERROR_MSG<<std::endl;
                exit(EXIT_FAILURE);
            }
        }
        //push line to the data:
        dataList.push_back(intVec);
    }
    file.close();
    std::reverse(dataList.begin(),dataList.end());
    return dataList;
}

