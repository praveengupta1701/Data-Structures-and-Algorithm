boolcontainsDuplicate1(vector<int>& nums){
    sort(nums.begin(), nums.end());
    for(inti=0; i<int(nums.size())-1; i++) {
        if(nums[i]==nums[i+1])
            returntrue;
    }
    returnfalse;    
}
boolcontainsDuplicate2(vector<int>& nums){
    map<int, bool> myMap;
    // unordered_map<int, bool> myMap;for(auto& num: nums) {
        if(myMap.find(num) != myMap.end())
            returntrue;
        elsemyMap[num] = true;
    }
    returnfalse;
}
boolcontainsDuplicate3(vector<int>& nums){
    multimap<int, bool> myMap;
    // unordered_multimap<int, bool> myMap;for(auto& num: nums) {
        if(myMap.find(num) != myMap.end())
            returntrue;
        myMap.insert(make_pair(num, true));
    }
    returnfalse;
}
boolcontainsDuplicate4(vector<int>& nums){
    set<int> mySet;
    // unordered_set<int> mySet;// multiset<int> mySet;// unordered_multiset<int> mySet;for(auto& num: nums) {
        if(mySet.find(num) != mySet.end())
            returntrue;
        mySet.insert(num);
    }
    returnfalse;
}
