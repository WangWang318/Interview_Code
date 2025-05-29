#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
string s1 = "12345x";
string s2 = "51234x";

queue<string> q;
unordered_map<string, int> d;

int BFS(){
    q.push(s1);
    d[s1] = 0;
    while(q.size()){
        string s = q.front(); q.pop();
        int dis = d[s];
        if(s == s2) return dis;
        int idx = s1.find('x');
        for(int j = 0; j < s1.size(); j++){
            swap(s[idx], s[j]);
            if(!d.count(s)){
                d[s] = dis + 1;
                q.push(s);
            }
            swap(s[idx], s[j]);
        }
    }
    return -1;
}

int main(){
    cout<<BFS();

    return 0;
}