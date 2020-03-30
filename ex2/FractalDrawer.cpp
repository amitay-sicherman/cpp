/**
 * readme:
 * there is 3 parts:
 *
 * the fist is the main, he use the two others parts to print the fractals from the file.
 * the file in this part is FractalDrawer.
 *
 * the second , work on file- check that he is valid and if he is , read and process him.
 * the classes in this part is:
 * 1.CSVReader- get a csv file, check if the data in him much to the template of the ex, and return the data.
 *
 * the third, get the data and 'plot' all the fractals.
 * fractal- abstract class of fractal.
 *      SierpinskiCarpet- the fractal SierpinskiCarpet, inherit fractal
 *      SierpinskiTriangle- the fractal SierpinskiTriangle, inherit fractal
 *      Vicsekfractal-the fractal Vicsekfractal, inherit fractal
 * FractalFactory- a factory to 'fractals' (one of the subclasses), base on the 'factory' patten.
 */



#include <iostream>
#include <cstdlib>
#include "Fractal.h"
#define USAGE_MSG "Usage: FractalDrawer <file path>"
#define ERROR_MSG "Invalid input"


/**
 * @param argc :2
 * @param argv : the file name
 */

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        std::cerr<<USAGE_MSG<<std::endl;
        exit(EXIT_FAILURE);
    }

    //get the data from the file:
    CSVReader reader(argv[1]);

    //for each file 'print' the fractal
    for(auto step:reader.getData())
    {
        FractalFactory::make(step[0],step[1]);
    }
}
