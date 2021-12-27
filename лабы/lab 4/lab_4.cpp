#include<iostream>
#include<cmath>     //  подключение
#include <conio.h>	//	необходимых
#include <locale.h>	//	библиотек

using namespace std;

const float Y0okr = -2, X0okr = 13.528, r = 32, X0el = -6, Y0el = -4.633, A = 33, B = 22, k=-0.424475, b=11.14665, xA=0, xB1=26.25985, xB2=44.56981;

float squareA(int n){
    float s = 0, y, Ds;
    float Dx = (xB1 - xA)/n;

    for(float x = xA; x<=xB1; x=x+Dx){
        y = B*sqrt(1-((x-X0el)*(x-X0el))/(A*A))+Y0el;
        Ds = Dx * y;
        s = s + Ds;
    }

    for(float x = xA; x<=xB1; x=x+Dx){
        y = k*x+b;
        Ds = Dx * y;
        s = s - Ds;
    }

    return s;
}

float squareB (int n){
    float s = 0, y, Ds, yT;
    float Dx = (xB2 - xA)/n;

    for(float x = xA; x<=xB2; x=x+Dx){
        y = -sqrt(r*r-(x-X0okr)*(x-X0okr))+Y0okr;
        Ds = -Dx * y;
        s = s + Ds;
    }

    Dx = (xB2 - xB1)/n;
    for(float x = xB1; x<=xB2; x=x+Dx){
        y = k*x+b; 
        Ds = -Dx * y;
        s = s - Ds;
    }

    Dx = (xB1 - xA)/n;
    for(float x = xA; x<=xB1; x=x+Dx){
        y = -B*sqrt(1-((x-X0el)*(x-X0el))/(A*A))+Y0el;
        Ds = -Dx * y;
        s = s - Ds;
    }

    return s;
}

float trapA (int n){
    float s = 0, y, Ds, yT;
    float Dx = (xB1 - xA)/n, yP = B*sqrt(1-((xA-X0el)*(xA-X0el))/(A*A))+Y0el;

    for(float x = xA; x<=xB1; x=x+Dx){
        y = B*sqrt(1-((x-X0el)*(x-X0el))/(A*A))+Y0el;
        yT=(yP+y)/2;
        Ds = Dx * yT;
        s = s + Ds;
        yP=y;
    }

    for(float x = xA; x<=xB1; x=x+Dx){
        y = k*x+b;
        yT=(yP+y)/2;
        Ds = Dx * yT;
        s = s - Ds;
        yP=y;
    }

    return s;
}

float trapB (int n){
    float s = 0, y, Ds, yT;
    float Dx = (xB2 - xA)/n, yP = -sqrt(r*r-(xA-X0okr)*(xA-X0okr))+Y0okr;

    for(float x = xA; x<=xB2; x=x+Dx){
        y = -sqrt(r*r-(x-X0okr)*(x-X0okr))+Y0okr;
        yT=-(yP+y)/2;
        Ds = Dx * yT;
        s = s + Ds;
        yP=y;
    }

    yP = k*xB1+b;
    Dx = (xB2 - xB1)/n;
    for(float x = xB1; x<=xB2; x=x+Dx){
        y = k*x+b;
        yT=-(yP+y)/2;
        Ds = Dx * yT;
        s = s - Ds;
        yP=y;
    }

    yP = -B*sqrt(1-((xA-X0el)*(xA-X0el))/(A*A))+Y0el;
    Dx = (xB1 - xA)/n;
    for(float x = xA; x<=xB1; x=x+Dx){
        y = -B*sqrt(1-((x-X0el)*(x-X0el))/(A*A))+Y0el;
        yT=-(yP+y)/2;
        Ds = Dx * yT;
        s = s - Ds;
        yP=y;
    }

    return s;
}

float simpsonA(int n)
{
 
   float Dx = (xB1-xA)/n;
 
   float s=0, s2 = 0, s4 = 0;

   s4 = B*sqrt(1-((xA+Dx-X0el)*(xA+Dx-X0el))/(A*A))+Y0el;
   for(int m = 2; m < n; m += 2 )
   {
       s4 += B*sqrt(1-((xA+(m+1)*Dx-X0el)*(xA+(m+1)*Dx-X0el))/(A*A))+Y0el;
       s2 += B*sqrt(1-((xA+m*Dx-X0el)*(xA+m*Dx-X0el))/(A*A))+Y0el;
   }
   s= B*sqrt(1-(xA-X0el)*(xA-X0el)/(A*A))+Y0el+B*sqrt(1-(xB1-X0el)*(xB1-X0el)/(A*A))+Y0el+4*s4+2*s2;
   s*= Dx/3;

    s4 = 0, s2 = 0;

    s4 = k*(xA+Dx)+b;
   for(int m = 2; m < n; m += 2 )
   {
        s4 += k*(xA+(m+1)*Dx)+b;
        s2 += k*(xA+m*Dx)+b;
   }
   s = s - Dx/3*(k*xA+b + k*xB1+b + 4*s4 + 2*s2);
   return s;
}

float simpsonB(int n)
{
 
   float Dx = (xB2-xA)/n;
 
   float s=0, s2 = 0, s4 = 0;

   s4 = -sqrt(r*r-(xA+Dx-X0okr)*(xA+Dx-X0okr))+Y0okr;
   for(int m = 2; m < n; m += 2 )
   {
       s4 += -sqrt(r*r-(xA+(m+1)*Dx-X0okr)*(xA+(m+1)*Dx-X0okr))+Y0okr;
       s2 += -sqrt(r*r-(xA+m*Dx-X0okr)*(xA+m*Dx-X0okr))+Y0okr;
   }
   s= -sqrt(r*r-(xA-X0okr)*(xA-X0okr))+Y0okr - sqrt(r*r-(xB2-X0okr)*(xB2-X0okr))+Y0okr+4*s4+2*s2;
   s*= -Dx/3;

    s4 = 0, s2 = 0;
    Dx = (xB2-xB1)/n;

    s4 = k*(xB1+Dx)+b;
   for(int m = 2; m < n; m += 2 )
   {
        s4 += k*(xB1+(m+1)*Dx)+b;
        s2 += k*(xB1+m*Dx)+b;
   }
   s = s + Dx/3*(k*xB1+b + k*xB2+b + 4*s4 + 2*s2);

   s4 = 0, s2 = 0;
   Dx = (xB1-xA)/n;

   s4 = -B*sqrt(1-((xA+Dx-X0el)*(xA+Dx-X0el))/(A*A))+Y0el;
   for(int m = 2; m < n; m += 2 )
   {
       s4 += -B*sqrt(1-((xA+(m+1)*Dx-X0el)*(xA+(m+1)*Dx-X0el))/(A*A))+Y0el;
       s2 += -B*sqrt(1-((xA+m*Dx-X0el)*(xA+m*Dx-X0el))/(A*A))+Y0el;
   }
   s= s + Dx/3*(-B*sqrt(1-(xA-X0el)*(xA-X0el)/(A*A))+Y0el-B*sqrt(1-(xB1-X0el)*(xB1-X0el)/(A*A))+Y0el+4*s4+2*s2);

   return s;
}

int ndig(int n){
    int k=0;
    while(n){
        k++; 
        n /= 10; 
    }
    return k;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "rus");
    int n1, n2, n3;
    
    start:

    cout<<"Введите 3 числа разбиений для фигуры А:"<<endl;
    cin>>n1>>n2>>n3;

    cout<<endl;
    cout<<"Площадь фигуры A:"<<endl;
    cout<<" ----------------------------------------------------------------------------"<<endl;
    cout<<"|    Число разбиений      |                     Результы                     | "<<endl;
    cout<<"|                         | -------------------------------------------------|"<<endl;
    cout<<"|            n            |       A        |       B        |       C        |"<<endl;
    cout<<"|-------------------------|--------------------------------------------------|"<<endl;
    cout<<"|            "<<n1;
    for(int i = 0; i<13-ndig(n1); i++){
        cout<<" ";
    }
    cout<<"|    "<<squareA(n1)<<"     |    "<<trapA(n1)<<"     |    "<<simpsonA(n1)<<"     |"<<endl;
    cout<<"|            "<<n2;
    for(int i = 0; i<13-ndig(n2); i++){
        cout<<" ";
    }
    cout<<"|    "<<squareA(n2)<<"     |    "<<trapA(n2)<<"     |    "<<simpsonA(n2)<<"     |"<<endl;
    cout<<"|            "<<n3;
    for(int i = 0; i<13-ndig(n3); i++){
        cout<<" ";
    }
    cout<<"|    "<<squareA(n3)<<"     |    "<<trapA(n3)<<"     |    "<<simpsonA(n3)<<"     |"<<endl;
    cout<<" --------------------------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"Введите 3 числа разбиений для фигуры В:"<<endl;
    cin>>n1>>n2>>n3;

    cout<<endl;
    cout<<"Площадь фигуры В:"<<endl;
    cout<<" ----------------------------------------------------------------------------"<<endl;
    cout<<"|    Число разбиений      |                     Результы                     | "<<endl;
    cout<<"|                         | -------------------------------------------------|"<<endl;
    cout<<"|            n            |       A        |       B        |       C        |"<<endl;
    cout<<"|-------------------------|--------------------------------------------------|"<<endl;
    cout<<"|            "<<n1;
    for(int i = 0; i<13-ndig(n1); i++){
        cout<<" ";
    }
    cout<<"|    "<<squareB(n1)<<"     |    "<<trapB(n1)<<"     |    "<<simpsonB(n1)<<"     |"<<endl;
    cout<<"|            "<<n2;
    for(int i = 0; i<13-ndig(n2); i++){
        cout<<" ";
    }
    cout<<"|    "<<squareB(n2)<<"     |    "<<trapB(n2)<<"     |    "<<simpsonB(n2)<<"     |"<<endl;
    cout<<"|            "<<n3;
    for(int i = 0; i<13-ndig(n3); i++){
        cout<<" ";
    }
    cout<<"|    "<<squareB(n3)<<"     |    "<<trapB(n3)<<"     |    "<<simpsonB(n3)<<"     |"<<endl;
    cout<<" --------------------------------------------------------------------------"<<endl;
    
    cout<<""<<endl;
    cout<<"Для выхода из программы нажмите клавишу ESC, для повторного ввода разбиений нажмите любую другую"<<endl;
    cout<<""<<endl;

    char ch; //создание переменной, в которой будет храниться информация с нажатой клавишей
	int code; //переменная, в которой будет храниться код введенной клавиши
    while(1) //бесконечный цикл для ожидания нажатия клавиши
	{
    	ch = getch(); //функция getch() возвращает данные нажатой клавиши
    	code = static_cast<int>(ch); //функция, переводящая данные нажатой клавиши в целочисленный тип
        	if(ch == 27) // если была нажата клавиша ESС(в ENSCII 27)
            	exit(0); //выход из приложения при нажатии ESC
        	else //если была нажата другая клавиша
            	goto start; //возврат на ключевую точку start
	}


    system("pause");
    return 0;
}
