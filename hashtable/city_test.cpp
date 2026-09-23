#include <iostream>
#include "city_hash.h"

using namespace std;

int main()
{
    CityHashTable city;

    city.insertCity(1, "Dehradun");
    city.insertCity(2, "Delhi");
    city.insertCity(3, "Mumbai");

    city.display();

    int x = city.searchCity("Dehradun");

    if(x != -1)
        cout << "\nCity found at index " << x;
    else
        cout << "\nCity not found";

    return 0;
}