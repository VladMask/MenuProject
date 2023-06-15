#include "CommandHandler.h"

using namespace std;

struct City
{
	string name;
	string state;
	int population = 0;
};

bool CompareByPopulation(City c1, City c2)
{
	return c1.population < c2.population;
}

bool CompareByName(City c1, City c2)
{
	return c1.name < c2.name;
}

// returns index of city in vector or -1 if city not found
int FindCityIndex(string name, vector<City>& cities)
{
	for (int i = 0; i < cities.size(); i++)
	{
		if (cities[i].name == name)
			return i;
	}
	return -1;
}

//prints exit messege
void Exit()
{
	system("CLS");
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Exit command pressed" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	exit(0);
}

//prints info about city or error statement
void PrintCityInfo(string cityName, vector<City>& cities)
{
	int index = FindCityIndex(cityName, cities);
	if (index != -1)
	{
		cout << setw(CITY_INDEX_WIDTH) << index << setw(CITY_NAME_WIDTH) << cities[index].name
			<< setw(STATE_NAME_WIDTH) << cities[index].state << setw(POPULATION_WIDTH) << cities[index].population << endl;
	}
	else
		cout << cityName + " not found";
}

//prints info about cities is some state or error mesegge if state not found
void StateInfo(vector<City>& cities)
{
	system("CLS");

	string stateName;
	cout << "Enter state name: ";
	cin >> stateName;

	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	cout << "Looking for cities in:\t" << stateName << endl;
	bool flag = false;
	for (int i = 0; i < cities.size(); i++)
	{
		if (cities[i].state == stateName)
		{
			PrintCityInfo(cities[i].name, cities);
			flag = true;
		}
	}
	if (!flag)
		cout << "State with name " + stateName + " is not founded" << endl;
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
}

//prints info about city using JoinCityInfo() func
void CityInfo(vector<City>& cities)
{
	system("CLS");
	string cityName;
	cout << "Enter city name: ";
	cin >> cityName;
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	cout << "Looking for city named:\t" << cityName << endl;
	PrintCityInfo(cityName, cities);
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
}

//sorts vector of cities in order to some criteria
void Sort(vector<City>& cities)
{
	system("CLS");

	string criteria;
	cout << "Enter sorting criteria: ";
	cin >> criteria;

	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	cout << "Sorting by " + criteria << endl;
	if (criteria == "name")
		sort(cities.begin(), cities.end(), CompareByName);
	else
		sort(cities.begin(), cities.end(), CompareByPopulation);
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	for (int i = 0; i < cities.size(); i++)
	{
		PrintCityInfo(cities[i].name, cities);
	}
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
}

//prints info about cities with populations in some range or error messege
void ShowInRange(vector<City>& cities)
{
	system("CLS");

	int lowerBound, upperBound;
	cout << "Enter lower bound: ";
	cin >> lowerBound;
	cout << "Enter upper bound: ";
	cin >> upperBound;

	if (lowerBound > upperBound)
		swap(lowerBound, upperBound);

	bool flag = false;
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	cout << "Looking for populations between " << lowerBound << " and " << upperBound << ":" << endl;
	for (int i = 0; i < cities.size(); i++)
	{
		if ((cities[i].population >= lowerBound) and (cities[i].population <= upperBound))
		{
			PrintCityInfo(cities[i].name, cities);
			flag = true;
		}
	}
	if (!flag)
		cout << "Cities with population in such range is not founded" << endl;
	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
}

//updates info about population in some city or prints error messege
void UpdatePopulation(vector<City>& cities)
{
	system("CLS");

	string cityName;
	cout << "Enter city name: ";
	cin >> cityName;

	int newValue = 0;
	cout << "Enter new value: ";
	cin >> newValue;

	cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	cout << "Updating population for:\t" << cityName << endl;
	int index = FindCityIndex(cityName, cities);
	if (index == -1)
	{
		cout << "ERROR. " + cityName + " not found" << endl;
	}
	else
	{
		cities[index].population = newValue;
		PrintCityInfo(cityName, cities);
		cout << setw(CITY_INDEX_WIDTH + CITY_NAME_WIDTH + STATE_NAME_WIDTH + POPULATION_WIDTH) << setfill('=') << "" << setfill(' ') << endl;
	}
}

//gets data from input file
vector<City> GetData(string finName)
{
	ifstream fin;
	fin.open(finName);
	vector<City> cities;
	while (!fin.eof())
	{
		City city;
		getline(fin, city.name, '\t');
		getline(fin, city.state, '\t');
		fin >> city.population;
		fin.ignore(1, '\n');
		cities.push_back(city);
	}
	cities.pop_back();
	return cities;
}