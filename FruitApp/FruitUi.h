#pragma once

#include "FruitController.h"
using namespace Contr;

namespace UI {
    class Ui {
    private:
        Controller controller;
    public:
        Ui(Controller _controller);

        void mainMenuUI();

        void mainMenu();

        void addFruit();

        void deleteFruit();

        void printFruit(Fruit fruit);

        void runningLow();

        void expdate();

        void search();
    };

}
