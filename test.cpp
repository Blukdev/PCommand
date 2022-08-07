#include<bits/stdc++.h>
#include "lib/parser.h"
string GetAllData(char *FileName){
	ifstream In(FileName); 
	string result((istreambuf_iterator<char>(In)),istreambuf_iterator<char>());
	return result;
}
int main(){
    string context=GetAllData("test.pc");
    Function F=Parse(context);
    cout<<F.Name<<endl;
    for(auto A:F.args)cout<<A<<" ";
    cout<<endl;
    for(auto A:F.Sentences){
        if(A.type=="define")
            for(auto B:A.def.vals)
                cout<<B.first<<"="<<B.second<<" ";
        else if(A.type=="delete")
            for(auto B:A.del.vals)
                cout<<B<<" ";
        cout<<endl;
    }
}