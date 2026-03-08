#include<iostream>
#include<string>
#include<fstream>
#include<vector>
 
using namespace std;
 
 
bool isSeparator(char ch){
    string value=" ,;(){}[]";
    for(int i=0;i<value.size();i++){
        if(ch==value[i]){
            return true;
        }
    }
    return false;
}
 
bool isOperator(char ch){
    string value="+-*/%=";
    for(int i=0;i<value.size();i++){
        if(ch==value[i]){
            return true;
        }
    }
    return false;
}
 
bool iskeyword(string str){
    string value[32]={"auto","break","case","char",
                      "const","continue","default",
                      "do","double","else","enum",
                      "extern","float","for","goto",
                      "if","int","long","register",
                      "return","short","signed","sizeof",
                      "static","struct","switch","typedef",
                      "union","unsigned","void","volatile"};
    for(int i=0;i<32;i++){
        if(str==value[i]){
            return true;
        }
    }
    return false;
}
 
bool isIdentifier(string str){
    bool valid=true;
    if(iskeyword(str)){
        return false;
    }   
    if(valid){
        if((str[0]>='0' && str[0]<='9')){
            valid=false;
        }
    if((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z') || str[0]=='_'){
        for(int i=1;i<str.size();i++){
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9') || str[i]=='_'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}
return valid;
}
 
bool isNumber(string str){
    bool valid=true;
    for(int i=0;i<str.length();i++){
        if((str[i]>='0' && str[i]<='9')|| str[i]=='.'){
            continue;
        }
        else{
            valid = false;
            break;
        }
    }
    return valid;
}
void parse(string str){
    vector<string> tokens;
    string token="";
    for(int i=0;i<str.length();i++){
        if(isSeparator(str[i])){
            if(token!=""){
                tokens.push_back(token);
                token="";   
            }
        }
        else if(isOperator(str[i])){
            if(token!=""){
                tokens.push_back(token);
                token="";
            }
            token.push_back(str[i]);
            tokens.push_back(token);
            token="";
        }
        else{
        token.push_back(str[i]);
       }
    }
    if(token!=""){
        tokens.push_back(token);   
        token="";
    }
 
 
    for(int i=0;i<tokens.size();i++){
        if(iskeyword(tokens[i])){
            cout<<tokens[i]<<" is a keyword"<<endl;
        }
        else if(isIdentifier(tokens[i])){
            cout<<tokens[i]<<" is an identifier"<<endl;
        }
        else if(isNumber(tokens[i])){
            cout<<tokens[i]<<" is a number"<<endl;
        }
        else if(tokens[i].size() == 1 && isOperator(tokens[i][0])){
        cout << tokens[i] << " is an operator" << endl;
        }
        else{
            cout<<tokens[i]<<" is an invalid token"<<endl;
        }
    }
}
 
int main(){
    ifstream file;
    string line;
    file.open("data.txt");
    if (!file.is_open()) {
        cout << "Error: data.txt file cannot found. try again. " << endl;
        return 1;
    }
    while (getline(file, line))
    {
        parse(line);
    }
    file.close();
 
return 0;
}