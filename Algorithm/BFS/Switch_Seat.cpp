// 换位置
// "ABCD" 每次可以两两交换，最少需要多少次交换达到 "CDAB"

//状态表示 string
//状态之间的距离


#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
string str1 = "ACBD"; 
string str2 = "ACBD";
unordered_map<string,int> d;
queue<string> q;

int BFS(){
    q.push(str1);
    d[str1] = 0;
    
    while(q.size()){
        string s = q.front(); q.pop();
        int distance = d[s];
        if(s == str2)   return distance;
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                swap(s[i], s[j]);
                if(!d.count(s)){
                    d[s] = distance + 1;
                    q.push(s);
                }
                swap(s[i], s[j]);
            }
        }
    }
    return -1;
}

int main(){

    int ans = BFS();
    cout<<ans<<endl;
    return 0;
}