#include "Fruit.h"
#include <string>
#include <utility>

using namespace std;
using namespace Domain;

Fruit::Fruit(string _name, string _origin, int _price, Data _exp_date, int _quantity) {
    name = std::move(_name);
    origin = std::move(_origin);
    price = _price;
    exp_date = _exp_date;
    quantity = _quantity;
}

string Fruit::get_name() const{
    return this->name;
}

string Fruit::get_origin() const {
    return this->origin;
}

int Fruit::get_price() const{
    return this->price;
}

void Fruit::set_price(int value){
    this->price= value;
}

int Fruit::get_quantity() const {
    return this->quantity;
}

void Fruit::set_quantity(int value){
    this->price= value;
}


Data Fruit::get_exp_date() {
    return this->exp_date;
}
