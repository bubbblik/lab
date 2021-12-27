#include <iostream> // Подключение
#include <cmath>
using namespace std;

int main() //главная функция

{
    const float Y0okr = -2, X0okr = 13.528, r = 32, X0el = -6, Y0el = -4.633, A = 33, B = 22;
        /*
        (Y0okr, X0okr) - координаты центра окружности радиусом r
        (X0el, Y0el) - координаты центра эллипса с большой полуосью А и малой полуосью B
        */ 
    const float Xmin_okr = X0okr - r, Xmax_okr = X0okr + r, Ymin_okr = Y0okr - r, Ymax_okr = Y0okr + r;
        /*
            Xmin_okr - крайняя левая точка окружности
            Xmax_okr - крайняя правая точка окружности
            Ymin_okr - крайняя нижняя точка окружности
            Ymax_okr - крайняя верхняя точка окружности
        */
    float X_last, Y_last; // переменные для сохранения последних значения х и у 

    for (float x = Xmin_okr; x <= Xmax_okr; x=x+0.001){
        x = round(x*1000)/1000; //округление х до 3 знаков после запятой

        float y; //создаем переменную у
        y = sqrt(r*r-(x-X0okr)*(x-X0okr)) + Y0okr; //выражаем у из уравнения окружности со знаком "+"
        y = round(y*1000)/1000; //округляем у

        if( (x-X0el)*(x-X0el)/(A*A)+(y-Y0el)*(y-Y0el)/(B*B) <= 1 ){ //подставляем значения х и у в уравнение эллипса
            X_last = x; Y_last = y;                                 //если оно меньше или равно 1, то записываем значения в переменные 
        }

        if( (x-X0el)*(x-X0el)/(A*A)+(y-Y0el)*(y-Y0el)/(B*B) > 1 ){
            if( abs(1-(X_last-X0el)*(X_last-X0el)/(A*A)+(Y_last-Y0el)*(Y_last-Y0el)/(B*B)) < abs(1-(x-X0el)*(x-X0el)/(A*A)+(y-Y0el)*(y-Y0el)/(B*B)) )
                cout<<"("<<X_last<<";"<<Y_last<<")"<<endl;
            else cout<<"("<<x<<";"<<y<<")"<<endl;
            break; //выход из цикла
            }
        }
        /*Если при подставлении х и у в уравнение эллипса получается значение больше 1,
        то идет сравнение модулей разности 1 и значения, полученного при подставлении х и у, X_last и Y_last
        чем меньше эта разность по модулю, тем ближе точка к точке пересечения.
        Если модуль разности меньше при значениях X_last и Y_last, то выводим X_last и Y_last, иначе х и у
        */

        X_last=0; Y_last=0; //обнуляем переменные для следующего цикла

    for (float x = Xmin_okr; x <= Xmax_okr; x=x+0.001){ //повторяем описанный выше алгоритм еще раз
        x = round(x*1000)/1000;

        float y;
        y = -sqrt(r*r-(x-X0okr)*(x-X0okr)) + Y0okr; //значение у получено из уравнения окружности со знаком "-" 
        y = round(y*1000)/1000;

        if( (x-X0el)*(x-X0el)/(A*A)+(y-Y0el)*(y-Y0el)/(B*B) <= 1 ){
            X_last = x; Y_last = y;
        }

        if( (x-X0el)*(x-X0el)/(A*A)+(y-Y0el)*(y-Y0el)/(B*B) > 1 ){
            if( abs(1-(X_last-X0el)*(X_last-X0el)/(A*A)+(Y_last-Y0el)*(Y_last-Y0el)/(B*B)) < abs(1-(x-X0el)*(x-X0el)/(A*A)+(y-Y0el)*(y-Y0el)/(B*B)) )
                cout<<"("<<X_last<<";"<<Y_last<<")"<<endl;
            else cout<<"("<<x<<";"<<y<<")"<<endl;
            break;
            }
        }
        system("pause");
    }
