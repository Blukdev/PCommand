#include<bits/stdc++.h>
#include "lib/opt.h"
#include "lib/parser.h"
using namespace std;
string GetAllData(char *FileName){
	ifstream In(FileName); 
	string result((istreambuf_iterator<char>(In)),istreambuf_iterator<char>());
	return result;
}
int main(int argc,char *argv[]){
    char *InputName;
    vector<string>str={"--help","-h","--input","-i"};
    vector<LampOpt::CommandRead>Ret=LampOpt::getopt(argc,argv,str);
    for(int i=0,e=Ret.size();i<e;++i)
		if(Ret[i].CommandName=="-h")cout<<"Usage\n\n--help/-h : Get help.\n--input/-i : Set input file.\n\nPcommand v0.1 @BlukDev 2022\n"; 
		else if(Ret[i].CommandName=="-i")InputName=argv[Ret[i].argvl];
    string context=GetAllData(InputName);
    
}