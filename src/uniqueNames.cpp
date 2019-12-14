#include <iostream>
#include <vector>
#include <set>

std::vector<std::string> unique_names(const std::vector<std::string>& names1, const std::vector<std::string>& names2)
{
    std::set<std::string> temp_set;
    
    for(auto name : names1)
    {
        temp_set.insert(name);
    }
    
    for(auto name : names2)
    {
        temp_set.insert(name);
    }
    
    std::vector<std::string> return_str;
    
    for(auto name : temp_set)
    {
        return_str.push_back(name);
    }
    
    return return_str;
}

#ifndef RunTests

int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};
    
    std::vector<std::string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}

#endif
