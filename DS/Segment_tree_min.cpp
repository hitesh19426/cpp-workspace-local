#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);
int RMQ(int st[] , int n, int a, int b);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

int fillSegmentTree(int arr[], int* tree, int l, int r, int root)
{
    if (l==r)
    {
        tree[root]=arr[l];
        return tree[root];
    }
    
    int m=l+(r-l)/2;
    
    int x=fillSegmentTree(arr, tree, l, m, 2*root+1);
    int y=fillSegmentTree(arr, tree, m+1, r, 2*root+2);
    if (x<y)
        tree[root]=x;
    else 
        tree[root]=y;
        
    return tree[root];
}

/* The functions which 
builds the segment tree */
int *constructST(int arr[],int n)
{
  //Your code here
  int h=(int) ceil(log2(n));
  
  int size= (int) pow(2, h+1) -1;
  
  int* tree=new int[size];
  
  fillSegmentTree(arr, tree, 0, n-1, 0);
  
  return tree;
}

int RMQHelper(int st[], int a, int b, int l, int r, int root)
{
    if (a<=l && r<=b)
    {
        return st[root];
    }
    
    if (b<l || r<a)
    {    
        return 1000000000;
    }
    
    int m=l+(r-l)/2;
    int left=RMQHelper(st, a, b, l, m, 2*root+1);
    int right=RMQHelper(st, a, b, m+1, r, 2*root+2);
    
    if (left<right)
        return left;
    return right;
    
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    if (b<0 || a>n-1 || b<a)
        return -1;
    
    return RMQHelper(st, a, b, 0, n-1, 0);
}

