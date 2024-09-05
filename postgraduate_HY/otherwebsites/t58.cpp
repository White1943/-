// 58. 区间和https://kamacoder.com/problempage.php?pid=1070
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;vector<int>nums(n);
    for(auto &x:nums)cin>>x;
    vector<long long>sum(n+1);
    sum[0]=0;
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+nums[i];
    }
    int a,b;
    while(cin>>a>>b){
        cout<<sum[b+1]-sum[a]<<endl;
    }
    return 0;
}