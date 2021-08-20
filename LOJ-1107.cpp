#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
           int a,b,c,d;
        cin>>a>>b>>c>>d;
        int m;
        cin>>m;
        printf("Case %d:\n",i);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            if(x>=a&&x<=c){
                if(y>=b&&y<=d){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }else{
                printf("No\n");
            }
        }
    }

    return 0;
}