#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
string str1 = "abcdefx";
string str2 = "cabfdex";

stack<int> stk;
unordered_map<char,int> hashmap;    // 查找某个元素在目标string中的位置

int main(){
    for(int i = 0; i < str2.size() - 1; i++)    hashmap[str2[i]] = i;
    for(int i = 0; i < str1.size() - 1; i++){
        if(str1[i] == str2[i])  continue;
        int first = i;
        int next = hashmap[str1[i]];
        stk.push(first);
        while(next != first){
            stk.push(next);
            next = hashmap[str1[next]];
        }
        int tmp = str1.size() - 1;
        while(stk.size()){
            int idx = stk.top(); stk.pop();
            swap(str1[idx], str1[tmp]);
            tmp = idx;
            cout<<str1<<endl;
        }
        swap(str1[tmp], str1[str1.size() - 1]);
        cout<<str1<<endl;
    }
    return 0;
}