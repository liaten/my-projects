#include <iostream>
#include <time.h>
using namespace std;
//есть ли сверху то же число
bool is_same_up(int **a, unsigned x, unsigned y,unsigned N)
{
    if(-a[x][y]==a[x-1][y] && (x-1)>0) return 1;
    else return 0;
}
//есть ли снизу то же число
bool is_same_down(int **a, unsigned x, unsigned y,unsigned N)
{
    if(-a[x][y]==a[x+1][y] && (x+1)<N+1) return 1;
    else return 0;
}
//есть ли слева то же число
bool is_same_left(int **a, unsigned x, unsigned y,unsigned N)
{
    if(-a[x][y]==a[x][y-1] && (y-1)>0) return 1;
    else return 0;
}
//есть ли снизу то же число
bool is_same_right(int **a, unsigned x, unsigned y,unsigned N)
{
    if(-a[x][y]==a[x][y+1] && (y+1)<N+1) return 1;
    else return 0;
}
//есть ли схожие числа рядом
bool is_any_same_nearby(int **a, unsigned x, unsigned y,unsigned N)
{
    if(is_same_up(a,x,y,N) || is_same_down(a,x,y,N) || is_same_left(a,x,y,N) || is_same_right(a,x,y,N)) return 1;
    else return 0;
}

unsigned combo_count(int **a, unsigned x, unsigned y,unsigned &combo,unsigned N)
{
    if(a[x][y]>0) a[x][y]*=-1;
    if(is_same_down(a,x,y,N))
    {
        combo++;
        combo=combo_count(a,x+1,y,combo,N);
    }
    if(is_same_up(a,x,y,N))
    {
        combo++;
        combo=combo_count(a,x-1,y,combo,N);
    }
    if(is_same_right(a,x,y,N))
    {
        combo++;
        combo=combo_count(a,x,y+1,combo,N);
    }
    if(is_same_left(a,x,y,N)) 
    {
        combo++;
        combo=combo_count(a,x,y-1,combo,N);
    }
    return combo;
}

int main()
{
    unsigned N;
    cout << "Введите число: ";
    cin >> N;
    unsigned combo; //комбинация
    unsigned max_combo=1; //макс комбинация
    int** a = new int* [N+2];
    for (unsigned i = 0; i < N+2; ++i)  a[i] = new int [N+2];
    srand (time(NULL));
    for(unsigned i=0;i<N+2;i++)
    {
        for(unsigned j=0;j<N+2;j++)
        {
            if(i==0 || j==0 ) a[i][j]=0;
            else if (i==N+1 || j==N+1) a[i][j]=0;
            else a[i][j]=rand()%7+1;
            if(a[i][j]!=0) 
            {
                switch (a[i][j])
                {
                    case 1:  cout << "\033[1;31m[]\033[0m "; break;
                    case 2:  cout << "\033[1;32m[]\033[0m "; break;
                    case 3:  cout << "\033[1;33m[]\033[0m "; break;
                    case 4:  cout << "\033[1;34m[]\033[0m "; break;
                    case 5:  cout << "\033[1;35m[]\033[0m "; break;
                    case 6:  cout << "\033[1;36m[]\033[0m "; break;
                    case 7:  cout << "\033[1;37m[]\033[0m "; break;
                }
            }
        }
        cout<<endl;
    }
    int** comb_array = new int* [ (N+1) * (N+1) ];
    for (unsigned i = 1; i < (N+1) * (N+1); ++i)  comb_array[i] = new int [2];
    int COUNT=0;
    for(unsigned i=1;i<N+1;i++)
    {
        for(unsigned j=1;j<N+1;j++)
        {
            //if(is_same_left(a,i,j,N)) cout<<i<<' '<<j<<endl; рабочий пример
            combo=0;
            a[i][j]*=-1;
            //if(is_any_same_nearby(a,i,j,N)) cout<<i<<' '<<j<<endl;
            if (is_any_same_nearby(a,i,j,N)) 
            {
                a[i][j]*=-1;
                combo=combo_count(a,i,j,combo,N)+1;
                if(combo==0)continue;
                //cout<<i<<' '<<j<<' '<<'='<<combo<<'='<<-a[i][j]<<endl;
            }
            COUNT++;
            if (combo>=max_combo)
            {
                max_combo=combo;
                comb_array[COUNT][0]=-a[i][j];
                comb_array[COUNT][1]=combo;
            }
            a[i][j]*=-1;
        }
    }

    cout<<"Максимальная комбинация: "<<max_combo<<endl;
    for(unsigned i=1;i<(N+1)*(N+1);i++) 
    {
        if(comb_array[i][1]==max_combo)
        {
            //cout<<comb_array[i][0]<<endl;
            switch(comb_array[i][0])
            {
                case 1:  cout<<"\033[1;31mКрасный\033[0m ";break;
                case 2:  cout << "\033[1;32mЗеленый\033[0m "; break;
                case 3:  cout << "\033[1;33mЖелтый\033[0m "; break;
                case 4:  cout << "\033[1;34mСиний\033[0m "; break;
                case 5:  cout << "\033[1;35mПурпурный\033[0m "; break;
                case 6:  cout << "\033[1;36mЦиановый\033[0m "; break;
                case 7:  cout << "\033[1;37mБелый\033[0m "; break;
            }
            cout<<endl;
        }
    }
    if(max_combo==1) cout<<"Нет комбинаций больше 1\n";

    for (unsigned i = 0; i < 2; ++i)  delete[] comb_array[i];
    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    delete[] comb_array;
    return 0;
}