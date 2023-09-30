
#include <string>
#include <iostream>

using namespace std;

class ContentFile{
    private:
        string file1;
        string file2;
        bool equal;
    public:
        ContentFile(string file1,string file2,bool equal){
            this->equal=equal;
            this->file1=file1;
            this->file2=file2;
        }
        string toString(){
            return this->file1 + " " + this->file2 + " " + (this->equal ? "true" : "false");
        }

};