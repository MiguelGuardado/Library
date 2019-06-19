#import <iostream>
#import <string>
using namespace std;


class Stu {
public:
Stu();
// Big Five
// functions
Stu(const string&)

//move contructor
TicStu(const TicStu && stu){
    cout<<"Move Constructor invoked"<<endl;
    this->asmt=new string[5];
    for(int i=0;i<5;++i){
        this->asmt[i]=stu.asmt[i];
    }
}
//copy contructor
TicStu(const Ticstu & stu){
    cout<<"copy contstuctor invoked"<<endl;
    this->asmt=new string[5];
    for(int i=0;i<5;++i){
        this->asmt[i]=stu.asmt[i]
    }
}
//Copy Assignment operator
TicStu & TicStu::operator=(const Tic & stu){
    cout<<"copy Assignment Operator invoked"<<endl;
    if(this != &stu){
        if(this->asmt != nullptr){
            delete[] this->asmt;
        }
        this->asmt=new string[5];
        for(int i=0;i<5;++i){
            this->asmt[i]=stu.asmt[i];
        }
    }
    return *this;
}
//Move Assignment Operator
TicStu & TicStu::operator=(const TicStu && stu){
    cout<<"Move Assignment Operator invoked"<<endl;
    if(this != &stu){
        if(this->asmt != nullptr){
            delete[] this->asmt;
        }
        this->asmt=new string[5];
        for(int i=0;i<5;++i){
            this->asmt[i]=stu.asmt
        }
    }
    return *this;
}
//Destructir
~TicStr(){
    cout<<"Destructor invoked"<<endl;
    if(this->asmt !=nullptr){
        delete[] this->asmt;
        this->asmt=nullptr;
    }
}



private:
string * asmt{ nullptr };
// Stu.cpp
Stu::Stu() {
this->asmt = new string [5];
}

int main(){

    return(0);
}


