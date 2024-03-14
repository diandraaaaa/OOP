#include "FruitController.h"

using namespace Contr;

Contr::Controller::Controller(Repository _repository) : repository(std::move(_repository)){}


void Controller::addFruit(string _name, string _origin, int _price, Data _exp_date, int _quantity) {
    Fruit addedFruit(_name, _origin, _price, _exp_date, _quantity);
    repository.addFruit(addedFruit);
}

void Controller::deleteFruit(string _name, string _origin) {
    Fruit deletedFruit = findFruit(_name, _origin);
    repository.deleteFruit(deletedFruit);
}

Fruit Controller::findFruit(string _name, string _origin) {
    return repository.findFruit(_name, _origin);
}

vector<Fruit> Controller::runninglow(int minQuanity) {
    if(minQuanity>0){
        return repository.runningLow(minQuanity);
    }
}

vector<Fruit> Controller::fruits() {
    return repository.fruits();
}

vector<Fruit> Controller::search(string input) {
    return repository.search(input);
}

vector<Fruit> Controller::sort_by_expdate() {
    return repository.sort_by_expdate();
}



