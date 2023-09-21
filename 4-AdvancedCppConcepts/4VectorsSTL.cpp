#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector <int> var;
    var.push_back(10);
    var.push_back(1);
    var.push_back(5);
    var.push_back(3);
    var.push_back(2);
    //sort
    std::sort(var.begin(), var.end());
    //print the sorted dynamic array
    std::cout << "sorted vector" << std::endl;
    for (auto i : var)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}