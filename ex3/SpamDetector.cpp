//
// Created by asicherm on 1/16/2020.
//
//
// Created by asicherm on 29/12/2019.
//
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include "HashMap.hpp"
#include <boost/algorithm/string.hpp>
#define ERROR_MSG "Invalid input"
//todo chenge usage msg
#define USAGE_MSG "Usage: FractalDrawer <file path>"

/**
 * the class get a string that contain a .csv file, check that he his valid, and return the data in the right pattarn
 */
class CSVReader
{
private:
    std::string _fileName;
public:
    explicit CSVReader(std::string);
    std::pair<std::vector<std::string>,std::vector<int>> getData();
};
CSVReader::CSVReader(std::string filePath)
{
    _fileName=std::move(filePath);
}


std::pair<std::vector<std::string>,std::vector<int>>  CSVReader::getData()
{
    //open the file:
    std::ifstream file(_fileName);
    if (!file.good())
    {
        std::cerr<<ERROR_MSG<<std::endl;
        exit(EXIT_FAILURE);
    }

    //red the file line by line:
    std::vector<int> intVec;
    std::vector<std::string> strVec;
    std::string line = "";
    while (getline(file, line))
    {
        std::vector<std::string> vec;

        //check each line if she is in the correct templete, and push here to the data:
        boost::algorithm::split(vec, line, boost::is_any_of(","));
//        vec.emplace_back("aaa");
//        vec.emplace_back("2");
        //just 2 col in line:
        if(vec.size()!=2)
        {
            file.close();
            std::cerr<<ERROR_MSG<<std::endl;
            exit(EXIT_FAILURE);
        }
        std::transform(vec[0].begin(), vec[0].end(), vec[0].begin(),
                       [](unsigned char c){ return std::tolower(c); });

        strVec.push_back(vec[0]);
        //check every single value in the line

        //the value can not convert to int:
        if(vec[1].empty() || !std::all_of(vec[1].begin(), vec[1].end(),::isdigit) )
        {
            file.close();
            std::cerr<<ERROR_MSG<<std::endl;
            exit(EXIT_FAILURE);
        }
        //the data is lagel, convert here to int, and push it to the data/
        int checkInt=std::stoi(vec[1]);
        intVec.push_back(checkInt);

    }

    file.close();
    return std::pair<std::vector<std::string>,std::vector<int>>(strVec,intVec);
}

int countFreq(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;

        if (j == M)
        {
            res++;
            j = 0;
        }
    }
    return res;
}


int main(int argc, char *argv[]) {

    if (argc != 4 ) {
        std::cerr << USAGE_MSG << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string argv3=argv[3];
    if (!(std::all_of(argv3.begin(), argv3.end(),::isdigit)))
    {
        std::cerr << USAGE_MSG << std::endl;
        exit(EXIT_FAILURE);
    }

    //get the data from the file:
    CSVReader reader(argv[1]);
    auto p = reader.getData();
    auto db = HashMap<std::string, int>(p.first, p.second);
    std::ifstream ifs(argv[2]);
    if (!ifs.good())
    {
        std::cerr<<ERROR_MSG<<std::endl;
        exit(EXIT_FAILURE);
    }
    std::string text( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    int counter=0;
    for (std::pair<std::string,int> single : db)
    {
        int temp=countFreq(single.first,text);
        counter+=temp*single.second;
    }

    if (counter > std::stoi(argv3))
    {
        cout << "SPAM" << std::endl;
    }
    else {
        cout << "SPAM" << std::endl;
    }
}

