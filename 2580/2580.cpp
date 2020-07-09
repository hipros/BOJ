#include<bits/stdc++.h>
using namespace std;

bool vis[3][10][10]; //-, !, ㅁ
int m[9][9], empty;

void answer()
{
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout<<m[i][j]<<" ";
        cout<<'\n';
    }
}
int dfs(int f)
{
    if(empty == f) {
        answer();
        return -1;
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(m[i][j] == 0){
                for(int n = 1; n <= 9; n++){
                    if(vis[0][i][n] == 0 && vis[1][j][n] == 0 && vis[2][(i/3)*3 + (j/3)][n] == 0){
                        m[i][j] = n;
                        vis[0][i][n] = vis[1][j][n] = vis[2][(i/3)*3 + (j/3)][n] = 1;

                        if(dfs(f+1) == -1) return -1;

                        m[i][j] = 0;
                        vis[0][i][n] = vis[1][j][n] = vis[2][(i/3)*3 + (j/3)][n] = 0;
                    }
                }
                return 1;
            }
        }
    }
}
int main ()
{
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int input;
            cin>>input;
            if(input == 0){
                empty++;
                continue;
            }
            m[i][j] = input;
            vis[0][i][input] = vis[1][j][input] = vis[2][(i/3)*3 + (j/3)][input] = 1;
        }
    }
    dfs(0);
    return 0;
}