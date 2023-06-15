#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const short CITY_INDEX_WIDTH = 4;
const short CITY_NAME_WIDTH = 20;
const short STATE_NAME_WIDTH = 18;
const short POPULATION_WIDTH = 11;

struct City;

bool CompareByPopulation(City c1, City c2);

bool CompareByName(City c1, City c2);

// returns index of city in vector or -1 if city is not founded
int FindCityIndex(string name, vector<City>& cities);

//prints exit messege
void Exit();

//prints info about city or error statement
void PrintCityInfo(string cityName, vector<City>& cities);

//prints info about cities is some state or error mesegge is state is not founded
void StateInfo(vector<City>& cities);

//prints info about city to file using JoinCityInfo() func
void CityInfo(vector<City>& cities);

//sorts vector of cities in order to some criteria
void Sort(vector<City>& cities);

//prints info about cities with populations in some range or error messege
void ShowInRange(vector<City>& cities);

//updates info about population in some city or prints error messege
void UpdatePopulation(vector<City>& cities);

//gets data from input file
vector<City> GetData(string finName);
