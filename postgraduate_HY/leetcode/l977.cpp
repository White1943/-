/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        int i=0,j=len-1;int cursor=j;
        vector<int>res(len);
        for(;cursor>=0;cursor--){
            if(-nums[i]>nums[j]){
                res[cursor]=nums[i]*nums[i];i++;
            }else{
                res[cursor]=nums[j]*nums[j];j--;
            }
        }
        return res;
    }
};
// @lc code=end

