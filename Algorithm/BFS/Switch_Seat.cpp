#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string str1 = "abcdefx";
string str2 = "cabfdex";
queue<string> q;
unordered_map<string, int> d;


int BFS(){
    q.push(str1);
    d[str1] = 0;
    while(q.size()){
        string s = q.front(); q.pop();
        int dis = d[s];
        if(s == str2)   return dis;
        int idx = s.find('x');
        for(int i = 0; i < str1.size(); i++){
            swap(s[idx], s[i]);
            if(!d.count(s)){
                q.push(s);
                d[s] = dis + 1;
            }
            swap(s[idx], s[i]);
        }
    }
    return -1;
}

int main(){

    cout<<BFS();

    return 0;
}