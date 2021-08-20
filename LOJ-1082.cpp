#include<bits/stdc++.h>
#define MX 1000001
#define RE 1000001
using namespace std;

int tree[MX*4];
int arr[MX];

void init (int node, int b, int e){
        if(b==e){
            tree[node]=arr[b];
            return;
        }
        int left=node*2;
        int right=(node*2)+1;
        int mid=(b+e)/2;
        init(left,b,mid);
        init(right,mid+1,e);
        if(tree[left]<tree[right])
        {
            tree[node]=tree[left];
        }else{
            tree[node]=tree[right];
        }
}

int query(int node, int b, int e, int i, int j){
    if(i>e||j<b){
        return RE;
    }
    else if(b>=i&& e<=j){
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
    if(p<q){
        return p;
    }else{
        return q;
    }

}

int main(){
    int t,a=1;
    scanf("%d",&t);
    while(t--){
        int n,q,x,y;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",a);
        for(int i=1;i<=q;i++){
            scanf("%d%d",&x,&y);
           int result=query(1,1,n,x,y);
           printf("%d\n",result);

        }
        a++;
    }

    return 0;
}