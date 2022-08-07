#include<bits/stdc++.h>
using namespace std;
unsigned readptr=0;
inline vector<string>split(string &s,char k){
    vector<string>result;
    string now="";
    for(auto c:s){
        if(c==k){
            result.push_back(now);
            now="";
        }else now.push_back(c);
    }
    if(now!="")result.push_back(now);
    return result;
}
inline string readto(char x,string &s){
    string str="";
    while(readptr<s.size()){
        if(s[readptr]==x){
            ++readptr;
            break;
        }
        else{
            str+=s[readptr];
            ++readptr;
        }
    }
    return str;
}
inline string readtodouble(char x,char y,string &s){
    string str="";
    while(readptr<s.size()){
        if(s[readptr]==x||s[readptr]==y){
            ++readptr;
            break;
        }
        else{
            str+=s[readptr];
            ++readptr;
        }
    }
    return str;
}
inline void transfer(string &s){
    while(readptr<s.size())
        if(s[readptr]==' '||s[readptr]=='\n'||s[readptr]=='\r')
            ++readptr;
        else break;
}
inline string cut(string &s,int cnt){
    string result="";
    if(cnt>=s.size())return "";
    for(int i=0;i<cnt;++i)result.push_back(s[i]);
    return result;
}
inline string recut(string &s,int cnt){
    string result="";
    for(int i=cnt;i<s.size();++i)result.push_back(s[i]);
    return result;
}
inline bool include(string &s,char k){
    for(auto c:s)
        if(c==k)
            return true;
    return false;
}
inline pair<string,string> pairSplit(string &s,char k){
    pair<string,string>result;
    string now="";
    for(auto c:s)
        if(c==k){
            result.first=now;
            now="";
        }else now.push_back(c);
    result.second=now;
    return result;
} 
inline int parseInt(string &s){
    int x=0;
    for(auto c:s)x=(x<<3)+(x<<1)+(c&15);
    return x;
} 
