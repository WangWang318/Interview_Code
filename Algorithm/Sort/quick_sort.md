## [快速排序模板](https://www.acwing.com/activity/content/problem/content/819/)


```
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int q[N];

void quick_sort(int l, int r){
    if(l >= r)  return ;
    int mid = (l + r)>>1;
    int flag = q[mid];
    int i = l - 1, j = r + 1;
    while(i < j){
        do i++; while(q[i] < flag);
        do j--; while(q[j] > flag);
        if(i < j)   swap(q[i], q[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main(){
    cin>>n;
    for(int i = 0; i < n; i++)  cin>>q[i];
    
    quick_sort(0, n - 1);
    
    for(int i = 0; i < n; i++)  cout<<q[i]<<" ";
    
    return 0;
}
```
## 注意
1. pivot的选取和边界： 
- (l + r)/2 -->(j, j + 1); 
- l -->(j, j + 1); 
- (l + r + 1)/2 -->(i - 1, i);
2. 如果选用 **j** 作为边界条件，排序过后 [l, j] 比 [j+1, r] 元素小

## [第k大的数](https://www.acwing.com/problem/content/788/)

```
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int a[N];

int quick_sort(int l, int r){
    if(l >= r)  return a[l];
    int i = l - 1, j = r + 1;
    int mid = a[l]; // (l + r)/2
    while(i < j){
        while(a[++i] < mid);
        while(a[--j] > mid);
        if(i < j)   swap(a[i], a[j]);
    }
    // if(j == k )  return a[j]; 仔细想想为什么不对 判断里面加上&& a[j] == mid才对
    if(j >= k)  return quick_sort(l, j); // 这两行仔细参照一下二分
    else    return quick_sort(j + 1, r);
}


int main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++)  cin>>a[i];
    k--;
    int ans = quick_sort(0, n - 1);
    cout<<ans;
    
    return 0;
}
```
## 例子
5 2 4 3 1   
如果要找到第四大的数，也就是k = 3   
第一轮，结束时i = 4, j = 3  
5 2 4 3 1  
1 2 4 ***3*** 5  
如果直接输出a[j],答案会是3.
