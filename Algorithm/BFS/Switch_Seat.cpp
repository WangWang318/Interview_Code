#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

string str1 = "abcdefx";
string str2 = "cabfdex";
queue<string> q;
unordered_map<string, int> d;
unordered_map<string, string> pr;

int BFS(){
    q.push(str1);
    d[str1] = 0;
    while(q.size()){
        string s = q.front(); q.pop();
        int dis = d[s];
        if(s == str2)   return dis;
        int idx = s.find('x');
        string p = s;
        for(int i = 0; i < str1.size(); i++){
            swap(s[idx], s[i]);
            if(!d.count(s)){
                q.push(s);
                d[s] = dis + 1;
                pr[s] = p;
            }
            swap(s[idx], s[i]);
        }
    }
    return -1;
}

int main(){

    cout<<BFS()<<endl;
    string s = str2;
    while(pr.count(s)){
        cout<<s<<endl;
        s = pr[s];
    }
    cout<<s;
    return 0;
}