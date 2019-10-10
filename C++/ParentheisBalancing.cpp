#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string exp){
    stack<char> s;
    char x;

    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            s.push(exp[i]);
            continue;
        }
        //Now the bracket will be the
        //closing one.So the must not be empty at this time.
        if(s.empty())return false;

        switch (exp[i]){
            case '}':
                x=s.top();
                s.pop();
                if(x=='['||x=='(')return false;
            break;
            case ')':
                x=s.top();
                s.pop();
                if(x=='['||x=='{')return false;
            break;
            case ']':
                x=s.top();
                s.pop();
                if(x=='{'||x=='(')return false;
            break;
        }
    }
    return (s.empty());
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string exp;
    getline(cin,exp);

    if(isBalanced(exp))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;

    return 0;
}
