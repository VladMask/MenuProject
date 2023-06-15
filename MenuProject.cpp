#include "Menu.h"
#include "CommandHandler.h"

struct City
{
	string name;
	string state;
	int population = 0;
};

int main()
{
	string finName = "Test.txt";
	vector<City> cities = GetData(finName);

	vector<string> menu = { "sort", "city", "state", "update", "range", "exit" };

	while (true)
	{
		short activeItem = Menu(menu);
		switch (activeItem)
		{
		case 0:
			Sort(cities);
			Await();
			break;
		case 1:
			CityInfo(cities);
			Await();
			break;
		case 2:	
			StateInfo(cities);
			Await();
			break;
		case 3:
			UpdatePopulation(cities);
			Await();
			break;
		case 4:
			ShowInRange(cities);
			Await();
			break;
		case 5:
			Exit();
		}
	}
}
