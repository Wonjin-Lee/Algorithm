//
//  Recursion.cpp
//  Algorithm
//
//  Created by LEE WON JIN on 02/08/2019.
//  Copyright © 2019 LEE WON JIN. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void pick(int n, vector<int>& picked, int toPick)
{
    // 기저 사례로써 toPick, 즉 더 이상 고를 수 없으면 고른 항목들을 출력
    if(toPick == 0) { printPicked(picked); return; }
    
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    
    for(int next = smallest; next < n; ++next)
    {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}
