/*
Some people always try to compare everything! 
Sometimes there are even big families trying to compare everything they see. 
So now, two families are trying to compare their Christmas gifts.

Both families contain equal number of members, each of which calculated 
the size of his/her gift: the size of ith member gift is equal family1[i] 
for the first family and family2[i] for the second family.

We don't know why, but to compare their gift these families decided to calculate 
the number of such pairs (i, j) such that i < j, family1[i] > family2[i], 
and family1[j] < family2[j]. Help them, find out the number of such pairs!
*/

int christmasLargeFamiliesGifts(std::vector<int> family1, std::vector<int> family2) {
    int count_pairs = 0;    
    std::set<std::pair<int,int>> hashset;
    
    for (int i = 0; i < family1.size(); i++) {
        if (family1[i] > family2[i])    
            hashset.emplace(std::make_pair(i,1));
    }
    for (int j = 0; j < family2.size(); j++) {
       if (family1[j] < family2[j])
           hashset.emplace(std::make_pair(j,2));
    }
    
    int count_ones_before = 0;
    
    for (auto it = hashset.begin(); it != hashset.end(); ++it) {
        if (it->second == 2) {
            count_pairs += count_ones_before;        
        }
        else {
            count_ones_before++;
        }
    }
    return count_pairs;
}
