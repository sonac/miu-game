//
// Created by sonac on 11/13/2021.
//
#include <cassert>
#include "miu_game.h"

void test_ruleOne() {
    std::string res1 = ruleOne("MI");
    std::string res2 = ruleOne("MU");
    std::string res3 = ruleOne("");
    assert(res1 =="MIU");
    assert(res2 == "MU");
    assert(res3.empty());
}

void test_ruleTwo() {
    std::string res1 = ruleTwo("MI");
    std::string res2 = ruleTwo("MIU");
    std::string res3 = ruleTwo("");
    assert(res1 =="MII");
    assert(res2 == "MIUIU");
    assert(res3.empty());
}

void test_ruleThree() {
    std::vector<std::string> res1 = ruleThree("MIII");
    std::vector<std::string> res2 = ruleThree("MIUU");
    std::vector<std::string> res3 = ruleThree("MIIIIU");
    std::vector<std::string> expected1 = {"MU"};
    std::vector<std::string> expected2 = {"MIUU"};
    std::vector<std::string> expected3 = {"MUIU", "MIUU"};
    assert(res1 == expected1);
    assert(res2 == expected2);
    assert(res3 == expected3);
}

void test_ruleFour() {
    std::vector<std::string> res1 = ruleFour("MUI");
    std::vector<std::string> res2 = ruleFour("MIUU");
    std::vector<std::string> res3 = ruleFour("MUUIUUI");
    std::vector<std::string> expected1 = {"MUI"};
    std::vector<std::string> expected2 = {"MI"};
    std::vector<std::string> expected3 = {"MIUUI", "MUUII"};
    assert(res1 == expected1);
    assert(res2 == expected2);
    assert(res3 == expected3);
}