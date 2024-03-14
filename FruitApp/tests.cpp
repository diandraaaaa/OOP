#include "FruitController.h"
#include <iostream>
#include <sstream>
#include <cassert>

#include "FruitUi.h"

using namespace UI;
using namespace Contr;
using UI::Ui;



void testDomain() {

    Fruit fruit("Apple", "USA", 2, { 2023, 5, 3 }, 10);

    // test getters and setters
    assert(fruit.get_name() == "Apple");
    assert(fruit.get_origin() == "USA");
    assert(fruit.get_price() == 2);
    assert(fruit.get_quantity() == 10);
    assert(fruit.get_exp_date().year == 2023);
    assert(fruit.get_exp_date().month == 5);
    assert(fruit.get_exp_date().day == 3);

    fruit.set_price(3);
    assert(fruit.get_price() == 3);

    fruit.set_quantity(5);
    assert(fruit.get_quantity() == 5);
}

void testController(){
    Repository repo;
    Controller controller(repo);
    assert(controller.fruits().size()==10);
    assert(controller.fruits().front().get_name()=="apple");
    assert(controller.fruits().back().get_name()=="kiwi");
    controller.addFruit("apple", "Romania", 10, {1, 12, 2024}, 20);
    assert(controller.fruits().front().get_quantity()==22);
    controller.deleteFruit("apple", "Romania");
    assert(controller.fruits().size()==9);
    vector<Fruit> runlow = controller.runninglow(5) ;
    assert(runlow.size()==3);
    controller.addFruit("fruct", "Romania", 10, {1, 12, 2024}, 20);
    assert(controller.fruits().size()==10);
    controller.addFruit("fruct1", "Romania", 10, {1, 12, 2024}, 20);
    assert(controller.fruits().size()==11);

}

void testRepository(){
    Repository repo;
    assert(repo.fruits().size()==10);
    assert(repo.fruits().front().get_name()=="apple");
    assert(repo.fruits().back().get_name()=="kiwi");
    Fruit fruit1("apple", "Romania", 10, {1, 12, 2024}, 20);
    repo.addFruit(fruit1);
    assert(repo.fruits().front().get_quantity()==22);
    repo.deleteFruit(fruit1);
    assert(repo.fruits().size()==9);


}
void testAll()
{
    testDomain();
    testController();
    testRepository();
}
