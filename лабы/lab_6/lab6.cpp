#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;
int counterWords = 0;

void SetColor(int text, int background)
{ 
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
} 

void find(string str){
    int counter = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '�' || str[i] == '�' || str[i] == '�' || str[i] =='�' || str[i] =='�' || str[i] =='�' || str[i] =='�' ||str[i] == '�' || str[i] == '�' || str[i] =='�' || str[i] =='�'){
            counter++;
        }
    }
    if(counter >= 2){
            SetColor(6, 0);
            cout<<str<<" ";
            SetColor(7, 0);
            counterWords++;
        }
    else cout<<str<<" ";
    counter = 0;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "rus"); // ���������� ����������� ���������

    string str;

    ifstream fin("text.txt");

    for(int i = 0; !fin.eof(); i++){
        if(fin.is_open()){
            getline(fin, str, ' ');
            find(str);
        }
    }
    cout<<"\n";
    cout<<"����� ���������� ����: "<<counterWords<<endl;

    system("pause");
    return 0;
}
