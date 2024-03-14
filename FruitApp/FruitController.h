#pragma once

#include "FruitRepo.h"

using Repo::Repository;
using Domain::Data;

namespace Contr {
    class Controller {
    private:
        Repository repository;

    public:
        explicit Controller(Repository _repository);

        void addFruit(string _name, string _origin, int _price, Data _exp_date, int _quantity);

        void deleteFruit(string _name, string _origin);

        Fruit findFruit(string _name, string _origin);

        vector<Fruit> runninglow(int minQuantity);

        vector<Fruit> fruits();

        vector<Fruit> search(string input);

        vector<Fruit> sort_by_expdate();
    };
}