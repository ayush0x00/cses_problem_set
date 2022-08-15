#include <bits/stdc++.h>
using namespace std;
#define ll long long

void query_digit(const ll &idx,const vector<ll>& powerOfTen){
    int numberOfDigits=0;
    ll blockSoFar=0,digitsSoFar=0;

    for(int i=1;i<=18;i++){
        digitsSoFar += (powerOfTen[i]-powerOfTen[i-1])*i;
        if(idx<=digitsSoFar){
            numberOfDigits = i;
            break;
        }
        blockSoFar+= (powerOfTen[i]-powerOfTen[i-1])*i;
    }

    //Binary Search
    ll low = powerOfTen[numberOfDigits-1];
    ll high = powerOfTen[numberOfDigits]-1;
    ll bestVal=0,startPosOfBestVal=0;

    while(low<=high){
        
        ll mid = (low+high)/2;
        ll startPosOfMidVal = blockSoFar+1+(mid-powerOfTen[numberOfDigits-1])*numberOfDigits;
        if(startPosOfMidVal <= idx){
            if(bestVal<mid){
                bestVal = mid;
                startPosOfBestVal = startPosOfMidVal;
            }
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    string number= to_string(bestVal);
    // cout<<number<<" "<<startPosOfBestVal<<" "<<idx<<"\n";
    // cout<<numberOfDigits<<"\n";
    char ch = number[idx-startPosOfBestVal];
    cout<<ch<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    vector<ll> powerOfTen(19,1);
    for(int i=1;i<=18;i++) powerOfTen[i]=powerOfTen[i-1]*10;
    int queries;
    cin>>queries;
    while(queries--){
        ll idx;
        cin>>idx;
        query_digit(idx,powerOfTen);
    }
    return 0;

}