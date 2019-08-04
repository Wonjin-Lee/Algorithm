//
//  Picnic.cpp
//  Algorithm
//
//  Created by LEE WON JIN on 05/08/2019.
//  Copyright © 2019 LEE WON JIN. All rights reserved.
//

#include <iostream>

int n;
bool areFriends[10][10];

int countPairings(bool taken[10])
{
    // 중복을 피하기 위해 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
    int firstFree = -1;
    
    for(int i = 0; i < n; ++i)
    {
        if(!taken[i])
        {
            firstFree = i;
            break;
        }
    }
    // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
    if(firstFree == -1) return 1;
    int ret = 0;
    
    for(int pairWith = firstFree + 1; pairWith < n; ++pairWith)
    {
        if(!taken[pairWith] && areFriends[firstFree][pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}
