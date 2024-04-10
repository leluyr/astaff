#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

int main(void){
    
    //input.txtを標準入出力とする
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());

    std::vector<int> test_value;
    int tmp;
    std::cout << "input test value1:" << std::endl;
    std::cin >> tmp;
    test_value.push_back(tmp);
    std::cout << "input test value2:" << std::endl;
    std::cin >> tmp;
    test_value.push_back(tmp);
    for (int i=0;i<test_value.size();i++){
        std::cout << test_value.at(i) << std::endl;
    }

    //csv file読み込み
    std::ifstream file("test.csv");
    std::vector<std::vector<std::string>> vv;

    for (std::string value; std::getline(file, value);) {
        vv.push_back(std::vector<std::string>());
        for (std::stringstream ss(value); std::getline(ss, value, ',');) {
            vv[vv.size()-1].push_back(value);
        }
    }
    for (auto& v : vv) {
        for (auto& e : v) std::cout << " " << e ;
            std::cout << "\n";
    }

    

return 0;
}