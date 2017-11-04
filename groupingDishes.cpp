#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
    std::map<std::string,std::vector<std::string>> ingredients;
     
    for (int i = 0; i < dishes.size(); i++) {
        for (int j = 1; j < dishes[i].size(); j++) {
           std::map<std::string,std::vector<std::string>>::iterator it = ingredients.find(dishes[i][j]);
           if ( it != ingredients.end() ) {
               it->second.push_back(dishes[i][0]);
           }
           else {
               ingredients.insert(std::pair<std::string, std::vector<std::string>>(dishes[i][j],{dishes[i][0]}));
           }
        }
    }
    
    std::vector<std::vector<std::string>> result;
    std::map<std::string,std::vector<std::string>>::iterator it;
    for ( it = ingredients.begin(); it != ingredients.end(); ++it ) {
        if ( it->second.size() > 1) {
            std::sort(it->second.begin(), it->second.end());
            std::vector<std::string>::iterator it2 = it->second.begin();
            it->second.insert(it2, it->first);
            result.push_back(it->second);
        }           
    }   
    
    return result;
}
