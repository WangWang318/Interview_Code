#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 105;
int n, m;
int a[N][N], d[N][N];
queue<pair<int,int>> q;

void BFS(){
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int x_new = x + dx[i], y_new = y + dy[i];
            if(x_new >= 0 && x_new < n && y_new >= 0 && y_new < m && d[x_new][y_new] == -1 && a[x_new][y_new] == 0){
                d[x_new][y_new] = d[x][y] + 1;
                q.push({x_new, y_new});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    BFS();
    cout<<d[n - 1][m - 1];
    return 0;
}