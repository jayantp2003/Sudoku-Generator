#include <bits/stdc++.h>
#include <random>
using namespace std;
#define endl '\n' 

void fill_diagonal(vector<vector<int>> &v,int &n)
{
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }

    shuffle(a.begin(), a.end(), random_device());

    for (int i = 0; i < n; i++)
    {
        v[i][i] = a[i];
    }
    
}

pair<int,int> find_empty_cells(vector<vector<int>> &v,int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i][j]==0)
            {
                return {i,j};
            }
        }        
    }
    return {-1,-1};
    
}

bool is_valid(vector<vector<int>> &v,int &x,int &y,int &value,int &n,int &k)
{
    
    for (int i = 0; i < n; i++)
    {
        if(v[x][i]==value)
            return false;

        if(v[i][y]==value)
            return false;

        for (int j = 0; j < n; j++)
        {
            if(v[k*((int)x/k) + j/k][k*((int)y/k) + j%k]==value)
                return false;
        }
        
    }
    return true;
}

bool solve_sudoku(vector<vector<int>> &v,int &n,int &k)
{
    pair<int,int> val = find_empty_cells(v,n);
    int x = val.first;
    int y = val.second;

    if(x==-1&&y==-1)
    {
        return true;
    }

    for (int i = 1; i <= n; i++)
    {
        if(is_valid(v,x,y,i,n,k))
        {
            v[x][y]=i;
            if(solve_sudoku(v,n,k))
            {
                return true;
            }
            v[x][y]=0;
        }
    }
    return false;
    
}

void erase_some_grid(vector<vector<int>> &v,int &n,int &c)
{
    int x=0;
    if(c==1)
        x = 25;
    else if(c==2)
        x = 40;
    else
        x = 55;

    while(x>0)
    {
        int i = rand()%9;
        int j = rand()%9;

        if(v[i][j]!=0)
        {
            v[i][j]=0;
            x--;
        }
    }

}

vector<vector<int>> generate_sudoku(int &n,int &c)
{
    vector<vector<int>> v(n,vector<int>(n,0));

    fill_diagonal(v,n);
    int k = (int)sqrt(n);
    if(solve_sudoku(v,n,k))
    {
        cout<<"Status - Success!"<<endl;
        cout<<endl;
        erase_some_grid(v,n,c);
    }
    else
    {
        cout<<"Status - Failed to load, please try again"<<endl;
        cout<<endl;
    }
    return v;
}

void print_sudoku(vector<vector<int>> &v)
{
    for(auto it:v)
    {
        for(auto jt:it)
        {
            cout<<jt<<" ";
        }
        cout<<endl;
    }
}

void gen()
{
    int k;
    int c;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Instructions"<<endl;
    cout<<"To have the rules mainted for sudoku, you need to enter size of grid as a square number to prevent any bug, you need to enter its squared root value and you will be provided the choice of level you would like to play. 0 represents empty cells in the grid. Enjoy!!"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Enter k for k^2 grid length"<<endl;
    cin>>k;
    cout<<"Enter 1 for easy."<<endl;
    cout<<"Enter 2 for medium"<<endl;
    cout<<"Enter 3 for hard"<<endl;
    cout<<endl;
    cin>>c;
    int n = k*k;
    vector<vector<int>> v = generate_sudoku(n,c);
    print_sudoku(v); 
}

int main()
{
    gen();
    return 0;
}