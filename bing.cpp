//
//  main.cpp
//  CppLanguage
//
//  Created by Jiang Haoliang on 13-10-20.
//  Copyright (c) 2013年 Jiang Haoliang. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long count(const string& input) {
    const int rem = 1000000007;
    
    map<char, vector<size_t> > charTable;
    size_t strLen = input.length();
    for (size_t i = 0; i < strLen; ++i) {
        char chr = input[i];
        if (charTable.find(chr) == charTable.end()) {
            charTable[chr] = vector<size_t>();
        }
        charTable[chr].push_back(i);
    }
    
    assert(charTable.size() <= 4);
    if (charTable.size() < 4)
        return 0;
    int result = 0;
    vector<size_t>& bVec = charTable['b'];
    vector<size_t>& iVec = charTable['i'];
    vector<size_t>& nVec = charTable['n'];
    vector<size_t>& gVec = charTable['g'];
    
    for (auto bIter = bVec.begin(); bIter != bVec.end(); ++bIter) {
        size_t bPos = *bIter;
        for (auto iIter = lower_bound(iVec.begin(), iVec.end(), bPos);
             iIter != iVec.end(); ++iIter) {
            size_t iPos = *iIter;
            for (auto nIter = lower_bound(nVec.begin(), nVec.end(), iPos);
                 nIter != nVec.end(); ++nIter) {
                size_t nPos = *nIter;
                for (auto gIter = lower_bound(gVec.begin(), gVec.end(), nPos);
                     gIter != gVec.end(); ++gIter) {
                    ++result;
                    if (result == rem)
                        result = 0;
                }
            }
        }
    }
    return result;
}
    
int main(int argc, const char * argv[]) {
    long bingCount = count("iinbinbing");
    cout << bingCount;
}
