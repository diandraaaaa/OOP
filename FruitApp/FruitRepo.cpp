#include "FruitRepo.h"
#include <algorithm>
using namespace Repo;

Repository::Repository() {
    generateData();
}

void Repository::generateData() {
    fruitVector.push_back(Fruit("apple", "Romania", 10, {1, 12, 2024}, 2));
    fruitVector.push_back(Fruit("pear", "Romania", 5, {14, 9, 2023}, 5));
    fruitVector.push_back(Fruit("banana", "Ecuador", 98, {4, 5, 2023}, 4));
    fruitVector.push_back(Fruit("grape", "Italy", 100, {21, 9, 2023}, 26));
    fruitVector.push_back(Fruit("apple", "Ukraine", 11, {1, 11, 2024}, 90));
    fruitVector.push_back(Fruit("plum", "Hungary", 456, {28, 5, 2023}, 49));
    fruitVector.push_back(Fruit("peach", "China", 6, {5, 5, 2023}, 8));
    fruitVector.push_back(Fruit("watermelon", "Bulgaria", 6, {8, 8, 2023}, 12));
    fruitVector.push_back(Fruit("cherry", "Romania", 67, {12, 8, 2023}, 50));
    fruitVector.push_back(Fruit("kiwi", "China", 3, {14, 11, 2023}, 4));
}

Fruit Repository::findFruit(string _name, string _origin) {
    //searches for the fruit name and origin and returns it
    for (Fruit &fruit: fruitVector) {
        if (fruit.get_name() == _name && fruit.get_origin() == _origin)
            return fruit;
    }
}


void Repository::addFruit(const Fruit &addedFruit) {
    //loops thru the fruitsvector and searches for the fruit we want to add, if it finds it it increases the quantity
    for (Fruit &fruit: fruitVector) {
        if (fruit.get_name() == addedFruit.get_name() && fruit.get_origin() == addedFruit.get_origin()) {
            fruit.set_quantity(fruit.get_quantity() + addedFruit.get_quantity());
            return;
        }
    }
    //if the fruit doesn't exists it creates a new one
    fruitVector.push_back(addedFruit);
}

void Repository::deleteFruit(const Fruit &deletedFruit) {
    //loops thru the fruitsvector and searches for the fruit we want to delet and when it finds it it removes it
    for (int i = 0; i < fruitVector.size(); i++) {
        if (fruitVector[i].get_name() == deletedFruit.get_name() &&
            fruitVector[i].get_origin() == deletedFruit.get_origin()) {
            fruitVector[i] = fruitVector[i + 1];
        }
    }
}

vector<Fruit> Repository::runningLow(int minQuantity) {
    vector<Fruit> lowFruits;
    //checks if the quantity is lower than the number we gave as input
    for (Fruit &fruit: fruitVector) {
        if (fruit.get_quantity() < minQuantity)
            lowFruits.push_back(fruit);
    }
    return lowFruits;
}

vector<Fruit> Repository::fruits() {
    //return a vector with all fruits
    return fruitVector;
}

bool sort_by_name(Fruit& fruit1,Fruit& fruit2){
    return fruit1.get_name()< fruit2.get_name();
}
vector<Fruit> Repository::search(string input) {
    //if the input is an empty vector it returns all the fruits
    if (input == "")
        return fruitVector;
    vector<Fruit> fruits;
    //searches for the string we gave in the names of all the vectrors
    for (Fruit &fruit: fruitVector) {
        if (fruit.get_name().find(input) != string::npos)
            fruits.push_back(fruit);
    }
    sort(fruits.begin(), fruits.end(), sort_by_name);
    return fruits;
}

bool sort_by_exp_date(Fruit &fruit1, Fruit &fruit2) {
    //sorts the date first by year
    if (fruit1.get_exp_date().year != fruit2.get_exp_date().year) {
        return fruit1.get_exp_date().year < fruit2.get_exp_date().year;
        //if the year is the same it sorts it by month
    } else if (fruit1.get_exp_date().month != fruit2.get_exp_date().month) {
        return fruit1.get_exp_date().month < fruit2.get_exp_date().month;
    }
    //if th emonth is the same it sorts it by day
    return fruit1.get_exp_date().day < fruit2.get_exp_date().day;
}

vector<Fruit> Repository::sort_by_expdate() {
    vector<Fruit> restult = fruitVector;
    sort(restult.begin(), restult.end(), sort_by_exp_date);
    return restult;
}