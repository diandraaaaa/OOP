#include <iostream>
#include <string>

using namespace std;
namespace Domain {
    struct Data {
        int day;
        int month;
        int year;
    };

    class Fruit {
    private:
        string name;
        string origin;
        int price;
        Data exp_date{};
        int quantity;

    public:
        Fruit(string _name, string _origin, int _price, Data exp_date, int quantity);

        string get_name() const;

        string get_origin() const;

        int get_price() const;

        void set_price(int value);

        int get_quantity() const;

        void set_quantity(int value);

        Data get_exp_date() ;
    };

}