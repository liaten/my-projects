#include <iostream>     //ввод вывод
#include <clocale>
#include <fstream>      //для работы с текстовыми файлами
#include <sstream>
#include <map>
using namespace std;    //ввод вывод
struct library
{
    string author;   // Фамилия автора книги
    string title;    // Заголовок
    string firm;     // Издательство
    int year;       // Год издания
    int pages;      // Количество страниц
    int value;      // Стоимость
};

int main()
{
    setlocale(LC_ALL,"Rus");
    ifstream in;    // Поток ввода
    in.open ("input.txt",ios::in);
    int STRCOUNT=1;     // Счетчик строк для внесения в структуру
    int BOOKNUM=0;      // Счетчик книг
    if(in.is_open())
    {
        //cout<<"Файл ввода открылся\n";
        ofstream out;          // Поток вывода
        out.open("output.txt", ios::trunc);
        if(out.is_open())
        {
            //cout<<"Файл вывода открылся\n";
            string s;
            map<string,library>vars;
            in.close();
            in.open ("input.txt",ios::in);
            STRCOUNT=0;
            while (getline(in,s))
            {
                STRCOUNT++;
                if(STRCOUNT%6!=0) BOOKNUM = (STRCOUNT/6)+1;
                else BOOKNUM = STRCOUNT/6;
                vars["Book"+to_string(BOOKNUM)];
                //cout<<"Book"+to_string(BOOKNUM)<<" "<<STRCOUNT<<endl;
                if(STRCOUNT%6==1) vars["Book"+to_string(BOOKNUM)].author    = s;
                if(STRCOUNT%6==2) vars["Book"+to_string(BOOKNUM)].title     = s;
                if(STRCOUNT%6==3) vars["Book"+to_string(BOOKNUM)].firm      = s;
                if(STRCOUNT%6==4)
                {
                    istringstream iss (s, istringstream::in);
                    iss>>vars["Book"+to_string(BOOKNUM)].year;
                }
                if(STRCOUNT%6==5)
                {
                    istringstream iss (s, istringstream::in);
                    iss>>vars["Book"+to_string(BOOKNUM)].pages;
                }
                if(STRCOUNT%6==0)
                {
                    istringstream iss (s, istringstream::in);
                    iss>>vars["Book"+to_string(BOOKNUM)].value;
                }
                /*  тут проверка на работу структуры
                    cout<<vars["Book"+to_string(BOOKNUM)].author<<" "<<vars["Book"+to_string(BOOKNUM)].title<<" "<<vars["Book"+to_string(BOOKNUM)].firm<<" ";
                    cout<<vars["Book"+to_string(BOOKNUM)].year<<" "<<vars["Book"+to_string(BOOKNUM)].pages<<" "<<vars["Book"+to_string(BOOKNUM)].value<<endl;
                */
            }
            cout<<"Введите ваш бюджет: ";
            int budget; cin>>budget;
            bool BUDMORE=0; //больше ли бюджет чем цена одной из книг
            bool OUTED1=0;
            for(int i=1; i<=BOOKNUM; i++)
            {
                if(budget>=vars["Book"+to_string(i)].value)
                {
                    if(!BUDMORE)BUDMORE=1;
                    if(!OUTED1)
                    {
                        cout<<"На Ваш бюджет можно купить одну из следующих книг:\n";
                        OUTED1=1;
                    }
                    cout<<vars["Book"+to_string(i)].author<<" - \""<<vars["Book"+to_string(i)].title<<"\" издательства \""<<vars["Book"+to_string(i)].firm<<"\" "<<vars["Book"+to_string(i)].year<<" года, с количеством страниц "<<vars["Book"+to_string(i)].pages<<" и ценой "<<vars["Book"+to_string(i)].value<<" рублей"<<endl;
                    out<<vars["Book"+to_string(i)].author<<" - \""<<vars["Book"+to_string(i)].title<<"\" издательства \""<<vars["Book"+to_string(i)].firm<<"\" "<<vars["Book"+to_string(i)].year<<" года, с количеством страниц "<<vars["Book"+to_string(i)].pages<<" и ценой "<<vars["Book"+to_string(i)].value<<" рублей"<<endl;
                }
            }
            if(!BUDMORE) cout<<"Ваш бюджет меньше минимальной цены одной из книг."<<endl;
        }
        else cout<<"Файл вывода не открылся\n";
    }
    else cout<<"Файл ввода не открылся\n";
    system("pause");
    return 0;
}