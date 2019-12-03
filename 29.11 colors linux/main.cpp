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

unsigned combo_count(int **a, unsigned x, unsigned y,unsigned combo,unsigned N)
{
    if(a[x][y]>0) a[x][y]*=-1;
    if(is_same_down(a,x,y,N)) 
    {
        combo++;
        return combo_count(a,x+1,y,combo,N);
    }
    if(is_same_up(a,x,y,N)) 
    {
        combo++;
        return combo_count(a,x-1,y,combo,N);
    }
    if(is_same_right(a,x,y,N)) 
    {
        combo++;
        return combo_count(a,x,y+1,combo,N);
    }
    if(is_same_left(a,x,y,N)) 
    {
        combo++;
        return combo_count(a,x,y-1,combo,N);
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
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    int** comb_array = new int* [ (N+1) * (N+1) ];
    for (unsigned i = 1; i < (N+1) * (N+1); ++i)  comb_array[i] = new int [2];
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
                cout<<i<<' '<<j<<' '<<'='<<combo<<'='<<-a[i][j]<<endl;
            }
            if (combo>=max_combo)
            {
                max_combo=combo;
                comb_array[i*j][0]=a[i][j];
                comb_array[i*j][1]=combo;
            }
        }
    }
    for(unsigned i=1;i<(N+1)*(N+1);i++)
    {
        ;//for(unsigned j=0;j<1;j++) cout<<j<<' '<<endl;
    }
    for (unsigned i = 0; i < 2; ++i)  delete[] comb_array[i];
    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    delete[] comb_array;
    cout<<max_combo<<endl;
    return 0;
}