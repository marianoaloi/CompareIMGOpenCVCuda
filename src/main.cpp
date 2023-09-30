#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <sstream>
// #include <bits/stdc++.h>
// #include <ContentFile.cpp>
// #include <ContentFile.h>
#include <src/CreateImgsCompare.cpp>

using namespace std;

void splitMore(std::filesystem::path path,vector<string> row, vector<ContentFile> &content,bool equal)
{

    string file1,file2;
    for (int i = 0; i < row.size(); i++)
    {
        for (int j = i + 1; j < row.size(); j++)
        {
            file1=path.string() + row[i];
            file2=path.string() + row[j];
            manipulateImg(file1,file2,equal,content);
        }
    }
}

void manipulateImg(string &file1,string &file2,bool &equal,vector<ContentFile> &content){
    content.push_back(ContentFile(file1, file2,equal));
}

void readFile(string filteStr,vector<ContentFile> &content,bool equal)
{
    ifstream compareFile(filteStr);
    vector<string> row;
    string line, word , file1,file2;
    std::filesystem::path path = filteStr;
    path = path.parent_path();
    path += "/img/";
    while (getline(compareFile, line))
    {
        row.clear();

        stringstream str(line);

        while (getline(str, word, ','))
            row.push_back(word);

        // content.push_back(row);
        if (row.size() == 2)
        {

            file1=path.string() + row[0];
            file2=path.string() + row[1];
            manipulateImg(file1,file2,equal,content);
        }
        else
        {
            splitMore(path,row, content,equal);
        }
    }
    row.clear();
}

int main(int argc, char **argv)
{

    vector<ContentFile> content;

    ofstream MyFile("errorsFiles.txt");
    readFile("/mnt/BACKUP/videos3/arquivo.comparação.txt",content,true);
    readFile("/mnt/BACKUP/videos3/forcenegative.txt",content,false);
    CreateImgsCompare cic(content);
    cic.createImg();


    // for (int i = 0; i < content.size(); i++)
    // {
        
    //     cout << content[i].toString() << "\n";
    // }
}
