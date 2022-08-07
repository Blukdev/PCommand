/*
 _     ____ ____   _          _        
| |   / ___/ ___| | |__   ___| |_ __ _ 
| |  | |  | |     | '_ \ / _ \ __/ _` |
| |__| |__| |___  | |_) |  __/ || (_| |
|_____\____\____| |_.__/ \___|\__\__,_|
Lampese Command Compiler beta @BlukDev
*/
#include "strlib.h"
using namespace std;
struct check{
    set<string>vars;
    inline bool inset(string &s){
        return (vars.find(s)!=vars.end());
    }
    inline void insert(string &s){
        vars.insert(s);
    }
    inline void del(string &s){
        vars.erase(s);
    }
}checker;
struct Sentence{
    string type;
    struct Def{
        vector<pair<string,int>>vals;
    }def;
    struct Del{
        vector<string>vals;
    }del;
    vector<Sentence>Sentences;
};
struct Function{
    string Name;
    vector<string>args;
    vector<Sentence>Sentences;
};
Function init(string &code){
    Function initer;
    string Name=readto('(',code);
    initer.Name=Name;
    string arg=readto(')',code);
    initer.args=split(arg,',');
    ++readptr;
    return initer;
}
Function Parse(string &code){
    Function result=init(code);
    while(readptr<code.size()){
        transfer(code);
        string line=readtodouble(';','{',code);
        if(cut(line,4)=="var "){
            //后期需要加入变量名检查
            //生命周期检查的部分只在另外一个嵌套解析函数中写
            auto variables_str=recut(line,4);
            auto variables=split(variables_str,',');    
            Sentence newSentence;
            newSentence.type="define";
            for(auto var:variables){
                if(include(var,'=')){
                    //后期需要引入表达式，这里需要重写
                    auto val=pairSplit(var,'=');
                    if(checker.inset(val.first)){
                        cout<<"Error:The variables "<<val.first<<" already exist and are not allowed to be repeatedly defined.\n";
                        exit(1);
                    }
                    checker.insert(val.first);
                    newSentence.def.vals.push_back({val.first,parseInt(val.second)});
                }else{
                    if(checker.inset(var)){
                        cout<<"Error:The variables "<<var<<" already exist and are not allowed to be repeatedly defined.\n";
                        exit(1);
                    }
                    checker.insert(var);
                    newSentence.def.vals.push_back({var,0});
                }
            }
            result.Sentences.push_back(newSentence);
        }else if(cut(line,7)=="delete "){
            auto variables_str=recut(line,7);
            auto variables=split(variables_str,',');
            Sentence newSentence;
            newSentence.type="delete";
            for(auto var:variables){
                if(checker.inset(var)){
                    newSentence.del.vals.push_back(var);
                    checker.del(var);
                }else{
                    cout<<"Error:The variables "<<var<<" do not exist.\n";
                    exit(1);
                }
            }
            result.Sentences.push_back(newSentence);
        }else if(cut(line,3)=="if("){
            
            
        }else if(cut(line,4)=="for("){

        }
        else if(cut(line,6)=="while("){

        }
        else if(include(line,'=')){

        }
    }
    return result;
}