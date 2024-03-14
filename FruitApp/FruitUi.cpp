#include "FruitUi.h"

#include <utility>

using namespace UI;
using namespace Contr;


Ui::Ui(Controller _controller) : controller(std::move(_controller)) {}


void Ui::mainMenuUI() {
    cout << "Choose an option:" << endl;
    cout << "1. Add a fruit" << endl;
    cout << "2. Delete a fruit" << endl;
    cout << "3. Search" << endl;
    cout << "4. Running low" << endl;
    cout << "5. Print expiration dates" << endl;
    cout << "6. Exit" << endl;
}

void Ui::mainMenu() {
    int option;

    while (true) {
        cout << string(5, '\n');
        mainMenuUI();
        cin >> option;
        cout << string(5, '\n');

        switch (option) {
            // If the user enters 1, it will call the addFruit function
            case 1:
                addFruit();
                // Output a message to prompt the user to continue
                cout << "Press any key to continue... " << endl;
                // Wait for the user to press a key before continuing
                cin.get();
                // Continue the loop to prompt the user for another input
                continue;
                // If the user enters 2, it will call the deleteFruit function
            case 2:
                deleteFruit();
                cout << "Press any key to continue... " << endl;
                cin.get();
                continue;
            case 3:
                search();
                cout << "Press any key to continue... " << endl;
                cin.get();
                continue;
            case 4:
                runningLow();
                cout << "Press any key to continue... " << endl;
                cin.get();
                continue;
            case 5:
                expdate();
                cout << "Press any key to continue... " << endl;
                cin.get();
                continue;
            case 6:
                break;
            default:
                cin.ignore();
                cout << "Invalid input" << endl;
                cout << "Press any key to continue... " << endl;
                cin.get();
                continue;

        }
        break;
    }
}

void Ui::addFruit() {
    string _name, _origin;
    int _price, _quantity;
    Data _exp_date;
    cout << "Please enter a fruit " << endl;
    cin >> _name;
    cout << "Please enter the origin country " << endl;
    cin >> _origin;
    cout << "Please enter the price " << endl;
    cin >> _price;
    cout << "Please enter the expiration date:" << endl;
    cout << "day: ";
    cin >> _exp_date.day;
    cout << "month: ";
    cin >> _exp_date.month;
    cout << "year: ";
    cin >> _exp_date.year;
    cout << endl << "Please enter the quantity " << endl;
    cin >> _quantity;
    cin.ignore();

    controller.addFruit(_name, _origin, _price, _exp_date, _quantity);
    cout << "You've successfully added a fruit!" << endl;

}


void Ui::deleteFruit() {
    string _name, _origin;

    cout << "Please enter the name and the origin of the fruit that you want to delete: " << endl;
    cin >> _name >> _origin;

    if (controller.findFruit(_name, _origin).get_name()==_name && controller.findFruit(_name, _origin).get_origin()== _origin) {
        controller.deleteFruit(_name, _origin);
        cout << "You've successfully deleted a fruit" << endl;
    }
    else
        cout << "There is no fruit with this name and origin" << endl;
}


void Ui::runningLow() {
    int minQuantity;
    cout << "Enter minimum quantity: ";
    cin >> minQuantity;

    for(Fruit& fruit: controller.runninglow(minQuantity))
        cout<<"fruit: "<<fruit.get_name()<<" origin: "<<fruit.get_origin()<<" quantity: "<<fruit.get_quantity()<<endl;

}

void Ui::expdate() {
    for(Fruit& fruit: controller.sort_by_expdate())
    {
        cout<<"fruit: "<<fruit.get_name()<<" origin: "<<fruit.get_origin()<<" expiration date: "<<fruit.get_exp_date().day<<".";
        cout<<fruit.get_exp_date().month<<"."<<fruit.get_exp_date().year<<endl;
    }
}

void Ui::search() {
    string input;
    cout<<"enter what you want to search for: "<<endl;
    cin>>input;
    for(Fruit& fruit: controller.search(input))
    {
        printFruit(fruit);
    }

}
void Ui::printFruit(Fruit fruit) {
    cout<<"fruit: "<<fruit.get_name()<<" origin: "<<fruit.get_origin()<<" price: "<<fruit.get_price();
    cout<<" expiration date: "<<fruit.get_exp_date().day<<"."<<fruit.get_exp_date().month<<"."<<fruit.get_exp_date().year;
    cout<<" quantity: "<<fruit.get_quantity();
}