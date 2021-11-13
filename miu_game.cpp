//
// Created by sonac on 11/13/2021.
//
#include <iostream>
#include <windows.h>
#include "miu_game.h"

string ruleOne(string str) {
    if (str.ends_with('I')) {
        return str+'U';
    }
    return str;
};

string ruleTwo(string str) {
   if (str.starts_with("M")) {
       string tail = str.substr(1);
       return str + tail;
   }
   return str;
};

vector<string> ruleThree(string str) {
    size_t iii_pos = str.find("III");
    if (iii_pos == string::npos)
        return vector{str};
    vector<string> vec;
    string initStr = str;
    for (int i = 0; i < str.length() - 2; i++) {
        iii_pos = initStr.find("III", i);
        if (iii_pos > str.length() - 2)
            break;
        i = int(iii_pos);
        str.replace(iii_pos, 3, "U");
        vec.push_back(str);
        str = initStr;
    }
    return vec;
};

vector<string> ruleFour(string str) {
    size_t uu_pos = str.find("UU");
    if (uu_pos == string::npos)
        return vector{str};
    vector<string> vec;
    string initStr = str;
    for (int i = 0; i < str.length() - 1; i++) {
        uu_pos = initStr.find("UU", i);
        if (uu_pos > str.length() - 1)
            break;
        i = int(uu_pos);
        str.replace(uu_pos, 2, "");
        vec.push_back(str);
        str = initStr;
    }
    return vec;
};

bool checkLayer(vector<string> layer) {
    for (auto el: layer)
        if (el == "MU") {
            std::cout << "found!";
            return true;
        }
    return false;
};

vector<string> applyRules(string str) {
    vector<string> res;
    string r1 = ruleOne(str);
    if (r1 != str)
        res.push_back(r1);
    string r2 = ruleTwo(str);
    if (r2 != str)
        res.push_back(r2);
    vector<string> r3 = ruleThree(str);
    for (const string& el: r3)
        if (el != str)
            res.push_back(el);
    vector<string> r4 = ruleFour(str);
    for (const string& el: r4)
        if (el != str)
            res.push_back(el);
    return res;
}

void Game() {
    string initString = "MI";
    vector<string> currentLayer = applyRules(initString);
    while (!checkLayer(currentLayer)) {
        /*
        std::cout << "current layer: ";
        for (const string& el: currentLayer)
            std::cout << el << " ";
            */
        std::cout << std::endl;
        vector<string> tmp;
        for (const string& el: currentLayer)
            for (const string& rEl: applyRules(el))
                tmp.push_back(rEl);
        currentLayer = tmp;
        //Sleep(1000);
    }
}