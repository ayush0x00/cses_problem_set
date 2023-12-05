#include <bits/stdc++.h>
using namespace std;

vector<long long>segment;
vector<int>nums;

void build(int idx, int low, int high){
    if(low==high){
        segment[idx]=nums[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    segment[idx]=segment[2*idx+1]+segment[2*idx+2];
    return;
}

long long query(int idx, int curr_lo, int curr_hi, int query_l, int query_r){
    if(query_l > curr_hi || curr_lo>query_r) return 0;  //no overlap
    else if(query_l<=curr_lo && query_r>=curr_hi) return segment[idx];  //complete overlap
    else{   //partial overlap
        int mid = (curr_hi+curr_lo)/2;
        long long lval = query(2*idx+1,curr_lo,mid,query_l,query_r);
        long long rval = query(2*idx+2,mid+1,curr_hi,query_l,query_r);
        return lval+rval;
    }
    return 0;
}

void update(int idx, int low, int high, int upd_idx, int val){
    if(low==high){
        segment[idx]=val;
        return;
    }
    int mid = (low+high)/2;
    if(upd_idx<=mid) update(2*idx+1,low,mid,upd_idx,val);
    else update(2*idx+2,mid+1,high,upd_idx,val);
    segment[idx] = segment[2*idx+1]+segment[2*idx+2];
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("test_input.txt","r",stdin);
    #endif
    int n,q;
    cin>>n>>q;
    nums = vector<int>(n);
    segment = vector<long long>(4*n);
    for(int i=0;i<n;i++) cin>>nums[i];
    build(0,0,n-1);
    while(q--){
        int type,arg1,arg2;
        cin>>type>>arg1>>arg2;
        if(type==1){
            update(0,0,n-1,arg1-1,arg2);
        }
        else{
            cout<<query(0,0,n-1,arg1-1,arg2-1)<<"\n";
        }
    }
}