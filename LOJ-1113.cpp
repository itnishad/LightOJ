#include<bits/stdc++.h>
using namespace std;

string url(string st){
    return st.substr(6,st.length());

}

int main()
{
    int t;
    cin>>t;
    getchar();
    string commend;
    for(int i=1; i<=t; i++)
    {
        stack<string> backward;
        stack<string> forwards;
        string current="http://www.lightoj.com/";
        printf("Case %d:\n",i);
        while(1)
        {
            getline(cin,commend);
            if(commend=="QUIT")
            {
                break;
            }
            else if(commend=="BACK")
            {
                if(backward.empty()==true)
                {
                    printf("Ignored\n");
                }
                else
                {
                    forwards.push(current);
                    current=backward.top();
                    cout<<current<<"\n";
                    backward.pop();
                }

            }
            else if(commend=="FORWARD")
            {
                if(forwards.empty()==true)
                {
                    printf("Ignored\n");
                }
                else
                {
                    backward.push(current);
                    current=forwards.top();
                    cout<<current<<"\n";
                    forwards.pop();
                }

            }
            else
            {
                backward.push(current);
                while(!forwards.empty()){
                    forwards.pop();
                }
               current=url(commend);
                cout<<current<<"\n";
            }
        }
    }
    return 0;
}