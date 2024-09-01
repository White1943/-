#include <iostream>
#include <bits/stdc++.h>
#include "C201P19.h"
// chcp 65001
using namespace std;
void delete_nums(int start, vector<int> &nums)
{
    for (int i = start; i < nums.size() - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    nums.pop_back();
}
int main()
{
    // f08();
    cout<<3333;
    return 0;
}
void f08()
{
    vector<int> nums{2, 4, 2, 1, 5, 44, 33, 0, 9, 3, 8};
    int len = nums.size();
    int m;
    while (cin >> m)
    {
        if (m >= len)
            cout << "M 异常\n";
        else
        {
            vector<int> temp(nums.begin(), nums.end());
            printVec(temp);
            vector<int> t(nums.begin(), nums.begin() + m);
            cout << "T:";
            printVec(t);
            for (int i = m; i < len; i++)
            {
                temp[i - m] = temp[i];
            }
            for (int i = len - m; i < len; i++)
            {
                temp[i] = t[i - len + m];
            }
            printVec(temp);
        }
    }
}
void f06()
{    
    vector<int> nums1{2, 3, 2, 4, 5, 8, 4, 6, 0};
    vector<int> nums2{12, 2, -3, 0, 12};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int len = nums1.size() + nums2.size();
    vector<int> temp(len);
    int i1, i2;
    i1 = i2 = 0;
    int pushI = 0;
    while (i1 < nums1.size() && i2 < nums2.size())
    {
        if (nums1[i1] < nums2[i2])
        {
            temp[pushI++] = nums1[i1++];
        }
        else
        {
            temp[pushI++] = nums2[i2++];
        }
    }
    while (i1 < nums1.size())
    {
        temp[pushI++] = nums1[i1++];
    }
    while (i2 < nums2.size())
    {
        temp[pushI++] = nums2[i2++];
    }
    printVec(nums1);
    printVec(nums2);
    printVec(temp);
}
void f05()
{
    vector<int> nums{2, 3, 2, 4, 5, 0, 2, 3, 2, 7, 9, 10, 2};
    sort(nums.begin(), nums.end());
    int cmp = nums[0];
    int survive = 1;
    int kill = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == cmp)
        {
            // 相同数
            kill++;
        }
        else
        {
            nums[survive++] = nums[i];
            cmp = nums[i];
        }
    }
    printf("删除相同元素后数组为\n");
    for (int i = 0; i < nums.size() - kill; i++)
    {
        cout << nums[i] << " ";
    }
}
void f04()
{
    int s, t;
    cin >> s >> t;

    vector<int> nums{2, 3, 2, 4, 5, 0, 2, 3, 2, 7, 9, 10, 2};
    if (s >= t)
        cout << "s t大小不符合规定\n";
    int survive = 0, index = 0, killTime = 0;
    printVec(nums);
    for (; index < nums.size(); index++)
    {
        if (nums[index] <= t && nums[index] >= s)
        {
            killTime++;
        }
        else
        {
            nums[survive++] = nums[index];
        }
    }

    while (killTime--)
    {
        nums.pop_back();
    }
    printf("删除%d与%d之间的数后的数组为\n", s, t);
    printVec(nums);
}
void f03()
{
    vector<int> nums{2, 3, 2, 4, 5, 0, 2, 3, 2, 7, 9, 10, 2};
    int kill = 2;
    //    cin>>kill;
    int survive = 0, index = 0, killTime = 0;
    printVec(nums);
    for (; index < nums.size(); index++)
    {
        if (nums[index] == kill)
        {
            killTime++;
        }
        else
        {
            nums[survive++] = nums[index];
        }
    }

    while (killTime--)
    {
        nums.pop_back();
    }
    printf("删除%d后的数组为\n", kill);
    printVec(nums);
}
void f02()
{
    vector<int> nums{3, 2, 4, 5, 0, 7, 9, 10};
    int len = nums.size();
    for (int i = 0; i < len / 2; i++)
    {
        swap(nums[i], nums[len - 1 - i]);
    }
    printVec(nums);
}
void printVec(std::vector<int> &nums)
{
    cout<<"数组所有元素为:\n";
    for (auto x : nums)
        printf("%d  ", x);
    cout << endl;
}
void f01()
{
    vector<int> nums{3, 2, 4, 5, 7, 9, 10};
    int index = -1;
    int mini = INT_MAX;
    cout << "hel\n";
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < mini)
        {
            mini = nums[i];
            index = i;
        }
    }
    if (index == -1)
        cout << "没有最小的元素,可能数组为空\n";
    else
    {
        printf("最小元素是%d,下标为%d\n", nums[index], index);
        // cout<<"最小元素是"
        nums[index] = nums.back();
        nums.pop_back();
    }
}