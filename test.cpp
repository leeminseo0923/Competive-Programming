#include <iostream>
#include <unordered_map>
#include <functional>

int main()
{
    std::unordered_map<std::string, std::string, std::hash<std::string>> myMap;

    myMap["key1"] = "value1";
    myMap["key2"] = "value2";
    myMap["key3"] = "value3";

    std::cout << "Value for key1 is " << myMap["key1"] << std::endl;

    return 0;
}