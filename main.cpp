#include <iostream>
#include "test.h"
#include "miu_game.h"

int main() {
    test_ruleOne();
    test_ruleTwo();
    test_ruleThree();
    test_ruleFour();
    std::cout << "tests are successful\n running the game" << std::endl;
    Game();
    return 0;
}
