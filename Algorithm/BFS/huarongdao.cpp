#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
string str = "23415x768";
string m = "12345678x";
unordered_map<string, int> d;
queue<string> q;

int BFS(){
    q.push(str);
    d[str] = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    while(q.size()){
        string s = q.front(); q.pop();
        int dis = d[s];
        if(s == m)  return dis;
        int idx = s.find('x');
        int x_idx = idx / 3, y_idx = idx % 3;
        for(int i = 0; i < 4; i++){
            int x_new = x_idx + dx[i], y_new = y_idx + dy[i];
            if(x_new >= 0 && x_new < 3 && y_new >= 0 && y_new < 3){
                swap(s[idx], s[x_new * 3 + y_new]);
                if(!d[s]){
                    d[s] = dis + 1;
                    q.push(s);
                }
                swap(s[idx], s[x_new * 3 + y_new]);
            }
        }
    }
    return -1;
}

int main(){

    cout<<BFS();

    return 0;
}