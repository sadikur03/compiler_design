#include <iostream>
using namespace std;

bool check1(char *s){
    
   while(*s!='\0'){
    if(*s!='a'){
        return false;
    }
    s++;
   }
   return true;
}

bool check2(char *s){

  if(*s=='a' || *s=='b'){
    return true;
  }
  else{
    return false;
  }
}

bool check3(char *s){
    while(*s!='\0'){
        if(*s!='a' && *s!='b'){
            return false;
        }
        s++;
    }
    return true;
}
bool check4(char *s){
    if(*s!='a'){
        return false;
    }
    if(*(s+1)=='\0'){
        return false;
    }
    while(*s!='\0'){
       
        s++;
    }
    if(*s=='b'){
        return true;
    }
    return false;
}


    int main() {
        string input;
        cout << "Enter a string: ";
        cin >> input;
    
        char *str = &input[0];  
    
        cout << "check1: ";
        if(check1(str)){
            cout << "Accepted\n";
        }
        else{
            cout << "Rejected\n";
        }
    
        cout << "check2: ";
        if(check2(str))
        {
         cout << "Accepted\n";
        }
        else{
            cout << "Rejected\n";
        }

    
        cout << "check3: ";
        if(check3(str)){
            cout << "Accepted\n";
        }
        else{
             cout << "Rejected\n";
        }
        cout << "check4: ";
        if(check4(str))
        {
            cout << "Accepted\n";
        } 
        else 
        {
            cout << "Rejected\n";  
        }
    
        return 0;
    }

   