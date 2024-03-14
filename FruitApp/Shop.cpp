#include "FruitUi.h"
#include "tests.h"

using namespace std;
using namespace UI;


int main() {
    Repository repository;
    Controller controller(repository);
    Ui ui(controller);

    ui.mainMenu();
    testAll();
    return 0;
}
