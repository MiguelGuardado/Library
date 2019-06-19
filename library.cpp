#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <numeric>
#include <map>
using namespace std;

multimap<string,string> speech;
unordered_map<string,multimap<string,string> > words;

void toUpperCase(string &wordword)
{
    locale loc;
    for (std::string::size_type i = 0; i < wordword.length(); ++i)
    {
        wordword[i] = toupper(wordword[i], loc);
    }
}

void toLowerCase(string &wordword)
{
    locale loc;
    for (std::string::size_type i = 0; i < wordword.length(); ++i)
    {
        wordword[i] = tolower(wordword[i], loc);
    }
}

string joinstring(const vector<string>& tempvector,char ch){
    string tempdef;
    for(vector<string>::const_iterator j = tempvector.begin();j!=tempvector.end();j++){
        tempdef+=*j;
        if(j!=tempvector.end()-1){
            tempdef+=ch;
        }
    }
    return(tempdef);
}
bool checkinput(vector<string> userinput){
    toLowerCase(userinput[0]);
    toLowerCase(userinput[1]);
    toLowerCase(userinput[2]);
    for(auto& x: words){
        if(x.first==userinput[0]){
            if(userinput.size()!=1){
            for(auto& y:x.second){
                if(y.first==userinput[1]){
                    if(userinput[2]=="distinct"){
                        return(true);
                    }
                    if(userinput.size()==2){
                        return(true);
                    }
                }
            }
            if(userinput[1]=="distinct"){
                return(true);
            }
        }else{
            return(true); 
        }
    }
}
return(false);
}


void inputData(vector<string> tokens,string word){
    string tempname;
    string tempdef;
for(int i=tokens.size();i>0;i--){
        if(tokens[i]=="-=>>"){
            //this breaks up the string so you get the part of speech for the map index
            int index=(tokens[i-1].find("|"))+1;
            tempname=tokens[i-1].substr(index,tokens[i-1].size());
            
            //this breaks up the part of the string to get inputted into the map 
            vector<string> tempvector;
            for(int j=i+1;j<tokens.size();j++){
                if(tokens[j+1]=="-=>>"){
                    int lastdefindex=tokens[j].find("|")-1;
                    string lastdef=tokens[j].substr(0,lastdefindex);
                    tempvector.push_back(lastdef);
                    break;
                }else{
                tempvector.push_back(tokens[j]);
                }
            }
            tempdef=joinstring(tempvector,' ');
            tempvector.clear(); 
            speech.insert(pair <string, string> (tempname,tempdef));
        }
        //load speech map now inside map with work key attached
    } 
    words[word]=speech;
    speech.clear();
}

void LoadData(){
string line;
ifstream in;
string def;
in.open("Data.CS.SFSU.txt");
if(!in.is_open()){
    cout<<"Text file does not exist";
}
if (in.is_open())
  {
    while ( getline (in,line) )
    {
    //creates a string split vector for inputting the data
    std::istringstream buf(line);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> tokens(beg, end);
    //now that the string is broken up into tokens I will now put the words into the data structure.
        int defindex=tokens[0].find("|");
        string def=tokens[0].substr(0,defindex);

    inputData(tokens,def);
    tokens.clear();

  }
    in.close();
}
}
void uselibrary(vector<string> userinput){
    multimap <string, string> :: iterator itr;
    string distincttemp;
    if(userinput.size()==1){
        for(auto& x: words.at(userinput[0])){
        cout<<userinput[0]<<" ["<<x.first<<"]"<<":"<<x.second<<endl;
        }
        return;
    }else if(userinput.size()==2){
        toLowerCase(userinput[1]);
        for(auto&x:words){
        if(x.first==userinput[0]){
        for(auto&y:x.second){
        if(y.first==userinput[1]||userinput[1]=="distinct"){   
            if(userinput[1]=="distinct"){ 
            for(auto&x:words.at(userinput[0])){
                for(auto&y:words.at(userinput[0])){
                    if(x.first!=distincttemp){
                        if(x.first==y.first){
                        distincttemp=x.first;
                        cout<<userinput[0]<<" ["<<x.first<<"]"<<":"<<x.second<<endl;
                        break;
                    }
                    }
                }
            }      
        }else{
        multimap <string, string> :: iterator itr;
        for (itr = words.at(userinput[0]).begin(); itr!= words.at(userinput[0]).end(); ++itr) {
            if(itr->first==userinput[1]){
                cout<<userinput[0]<<" ["<<userinput[1]<<"]:"<<itr->second<<endl;
            }
        }
        }
        return;
        }
        }
        }
    }
    cout<<"word not found please try again"<<endl;    
    }else if(userinput.size()==3){
        toLowerCase(userinput[1]);
        multimap<string,string>::iterator itr;
        for(itr=words.at(userinput[0]).begin();itr!=words.at(userinput[0]).end();itr++){
            if(itr->first!=distincttemp){
            if(itr->first==userinput[1]){
                distincttemp=itr->first;
                cout<<userinput[0]<<" ["<<userinput[1]<<"]:"<<itr->second<<endl;
            }
            }
        }
    }
}

int main(){
    cout<<"! Loading Data...."<<endl;
    LoadData();
    cout<<("! Loading Complete")<<endl;
    cout<<" ";
    cout<<"-----DICTIONARY 340 C++ -----"<<endl;
    while(true){
        cout<<"Search: ";
        string input=" ";
        getline(cin,input);
        toUpperCase(input);
        std::istringstream buf(input);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> inputvec(beg, end);
       
        toUpperCase(inputvec[0]);
        if(inputvec[0]=="!Q"){
            break;
        }else{
            toLowerCase(inputvec[0]);
            if(checkinput(inputvec)){
            uselibrary(inputvec);
            }else{
            cout<<"word not found please try again"<<endl;

            }
        } 
    }
    
    cout<<"-----THANK YOU-----"<<endl;

     
    return 0;
}