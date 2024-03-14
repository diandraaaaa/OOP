#pragma once

#include "Fruit.h"
#include <vector>

using std::vector;
using Domain::Fruit;
namespace Repo {
    class Repository {
    private:
        vector<Fruit> fruitVector;

    public:
        Repository();

        void generateData();

        Fruit findFruit(string _name, string _origin);

        void addFruit(const Fruit &addedFruit);

        void deleteFruit(const Fruit& deletedFruit);

        vector<Fruit> runningLow(int i);

        vector<Fruit> fruits();

        vector<Fruit> search(string input);

        vector<Fruit> sort_by_expdate();

    };
}
