#include <iostream>
#include "city_hash.h"

using namespace std;

int CityHashTable::hashFunction(string name)
{
    int sum = 0;

    for(int i = 0; i < name.length(); i++)
        sum += name[i];

    return sum % SIZE;
}

void CityHashTable::insertCity(int id, string name)
{
    int index = hashFunction(name);

    while(table[index].id != 0)
        index = (index + 1) % SIZE;

    table[index].id = id;
    table[index].name = name;
}

int CityHashTable::searchCity(string name)
{
    int index = hashFunction(name);

    while(table[index].id != 0)
    {
        if(table[index].name == name)
            return index;

        index = (index + 1) % SIZE;
    }

    return -1;
}

void CityHashTable::display()
{
    cout << "\nCITY HASH TABLE\n";

    for(int i = 0; i < SIZE; i++)
    {
        if(table[i].id != 0)
        {
            cout << i << " : "
                 << table[i].id << " - "
                 << table[i].name << endl;
        }
    }
}