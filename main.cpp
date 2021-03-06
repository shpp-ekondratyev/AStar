#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "stdlib.h"
using namespace std;


class City{
private:
    int number;
    string name;
    pair<double, double> coordinates;
    vector<pair<int, double> >neighbors;

    double g, h;
    int fromCity;

public:
    City(int number, string name, pair<double, double> coordinates, vector<pair<int, double> > neighbors){
        this->number = number;
        this->name = name;
        this->coordinates = coordinates;
        this->neighbors = neighbors;
        g = 0;
        h = 0;
        fromCity = 0;
    }

    int getNumber() {
        return number;
    }

    string getName() {
        return name;
    }

    pair<double, double> getCoordinates() {
        return coordinates;
    }

    vector<pair<int, double> > getNeighbors() {
        return neighbors;
    }

    void setG(double g) {
        this->g = g;
    }

    double getG() {
        return g;
    }

    void setH(double h) {
        this->h = h;
    }

    double getH() {
        return h;
    }

    double getF() {
        return f = g + h;
    }

    void setFromCity(int fromCity) {
        this->fromCity = fromCity;
    }

    int getFromCity() {
        return fromCity;
    }

};


string readLine(ifstream &inputFileStream) {
    string result;
    if (!(inputFileStream >> result)) {
        cerr << "File reading error!" << endl;
        exit(EXIT_FAILURE);
    }
    return result;
}


int readInt(ifstream &inputFileStream) {
    string result = readLine(inputFileStream);
    return atoi(result.c_str());
}


string readString(ifstream &inputFileStream) {
    string result = readLine(inputFileStream);
    return result;
}


double readDouble(ifstream &inputFileStream) {
    string result = readLine(inputFileStream);
    return atof(result.c_str());
}


vector<City> getCities(string inputFileName) {
    vector<City> result;
    ifstream inputFileStream(inputFileName.c_str());
    if (!inputFileStream.is_open()) {
        cerr << "File reading error!" << endl;
        exit(EXIT_FAILURE);
    }
    while(!inputFileStream.eof()) {
        int number = readInt(inputFileStream);
        string name = readString(inputFileStream);
        pair<double, double> coordinates = make_pair(readDouble(inputFileStream), readDouble(inputFileStream));
        int counter = readInt(inputFileStream);
        vector<pair<int, double> > neighbors;
        for (int i = 0; i < counter; ++i)
            neighbors.push_back(make_pair(readInt(inputFileStream), readDouble(inputFileStream)));
        result.push_back(City(number, name, coordinates, neighbors));
    }
    inputFileStream.close();
    return result;
}


int getCityNumber(string cityName, vector<City> &cities) {
    for (vector<City>::iterator it = cities.begin(); it != cities.end(); ++it)
        if (cityName == (*it).getName())
            return (*it).getNumber();
    return 0;
}


vector<int> aStar(int startCityNumber, int finishCityNumber, vector<City> &cities) {

    vector<int> result;

    return result;
}


vector<int> findPath(string startCityName, string finishCityName, vector<City> &cities) {
    int startCityNumber = getCityNumber(startCityName, cities);
    int finishCityNumber = getCityNumber(finishCityName, cities);
    if ((!startCityNumber) || (!finishCityNumber)) {
        cerr << "At least one of the cities is not presented on the map." << endl;
        exit(EXIT_FAILURE);
    }
    vector<int> result = aStar(startCityNumber, finishCityNumber, cities);
    return result;
}


int main()
{
    vector<City> cities = getCities("data.txt");
    vector<int> path = findPath("Kirovograd", "Cherkassy", cities);
    return 0;
}
