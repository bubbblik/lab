#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void gotoxy(short x, short y)
{
    COORD p = { x, y };
    // ���������� ��������� COORD � �������� ���� ��������� p
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    //����������� ������� SetConsoleCursorPosition � GetStdHandle �� WinApi
}

void SetColor(int text, int background)
{ 
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
} 

int number(int min, int max)
{
  int num = min + rand() % (max - min + 1);

  return num;
}

string word(int l){
    string sString;
    for (int nCount = 0; nCount < l; ++nCount)
		sString += 'a' + rand() % 26;
    return sString;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int m = 10, n = 10, k = 2, l = 7;
    
    string matr[m][n];

    double counter = 0;
    int counter4 = 0, couterWords = 0;

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            matr[i][j]=word(number(k, l));
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            if(matr[i][j].length()==4)
                counter4++;
        }
        if(counter4 >= 1){
            for(int i = 0; i<m; i++){
                    for (int g = 0; g < matr[i][j].length(); g++){
                        if(matr[i][j][g] == 'a' || matr[i][j][g] == 'e' || matr[i][j][g] == 'y' || matr[i][j][g] == 'u' || matr[i][j][g] == 'i' || matr[i][j][g] == 'o')
                            counter++;
                    }
                    if(counter/matr[i][j].length()>=0.2){
                        gotoxy(j*8, i);
                        SetColor(6, 0);
                        cout<<matr[i][j];
                        SetColor(7, 0);
                        couterWords++;
                    }
                    else{ 
                        gotoxy(j*8, i);
                        cout<<matr[i][j];
                    }
                    counter = 0;
            }
        }
        else {
            for(int i = 0; i<m; i++){
                gotoxy(j*8, i);
                cout<<matr[i][j];
            }
        }
        counter4 = 0;
    }
    gotoxy(0, m);
    cout<<"���������� ���������� ����: "<<couterWords<<endl;
    system("pause");
    return 0;
}