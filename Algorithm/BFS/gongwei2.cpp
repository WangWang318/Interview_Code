#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
string s1 = "abcdefx";
string s2 = "cabefdx";

unordered_map<char, int> hashmap;
stack<int> stk;
void function(){
    
    for(int i = 0; i < s2.size() - 1; i++){
        hashmap[s2[i]] = i;
    }

    int first, next;
    for(int i = 0; i < s1.size() - 1; i++){
        if(s1[i] == s2[i])   continue ;
        if(!stk.size()){
            first = i;
            stk.push(i);
        }
        next = hashmap[s1[i]];
        do{
            stk.push(next);
            next = hashmap[s1[next]];

        }while(next != first);
        next = s1.size() - 1;
        while(stk.size()){
            int idx = stk.top(); stk.pop();
            swap(s1[idx], s1[next]);
            next = idx;  
            cout<<s1<<" ";
        }
        swap(s1[next], s1[s1.size() - 1]);
        cout<<s1<<" ";
        puts("");
    }
}

int main(){
    function();
    return 0;
}