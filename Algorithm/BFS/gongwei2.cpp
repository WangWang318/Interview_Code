#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
string s1 = "abcdef";
string s2 = "cabefd";

unordered_map<char, int> hashmap;
stack<int> stk;
void function(){
    
    for(int i = 0; i < s2.size(); i++){
        hashmap[s2[i]] = i;
    }

    int first, next;
    for(int i = 0; i < s1.size(); i++){
        if(hashmap[s1[i]] == i)   continue ;
        if(!stk.size()){
            first = i;
            stk.push(i);
        }
        next = hashmap[s1[i]];
        do{
            stk.push(next);
            next = hashmap[s1[next]];

        }while(next != first);
        while(stk.size()){
            int idx = stk.top(); stk.pop();
            s1[idx] = s2[idx];
            cout<<s1<<endl;
        }
        puts("");
    }
}

int main(){
    function();
    return 0;
}