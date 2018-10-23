#include <bits/stdc++.h>
using namespace std;

#define MAX_T 100
#define MAX_R 100
#define MAX_C 100
#define MAX_N 10
#define FIERY '1'
#define FRIEND '2'

struct Cell{int row, col;};
struct BfsCell : Cell{unsigned int depth;};

#define is_valid(r, c, R, C) ((r)>=0 && (r)<(R) && (c)>=0 && (c)<(C))
#define can_visit(m, v) ((m)!=FIERY && (v)==UINT_MAX)

char M[MAX_R][MAX_C];
long long ANS[MAX_T];
unsigned int V[MAX_N][MAX_R][MAX_C];
Cell D[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void bfs(const Cell& src, int R, int C, int n)
{
    queue<BfsCell> q;
    q.push({src.row, src.col, 0});
    V[n][src.row][src.col] = 0;

    while (!q.empty()) {
        BfsCell cur = q.front();
        int cr = cur.row;
        int cc = cur.col;
        unsigned int cd = cur.depth;
        q.pop();

        for (auto &d : D) {
            int nr = cr + d.row;
            int nc = cc + d.col;
            if( is_valid(nr, nc, R, C) && can_visit(M[nr][nc], V[n][nr][nc]) ) {
                V[n][nr][nc] = cd+1;
                q.push({{nr, nc}, cd+1});
            }
        }
    }
}

unsigned long long solve(const vector<Cell>& friends, const int& R, const int& C)
{
    unsigned long long ans = UINT_MAX;
    memset(V, UINT8_MAX, sizeof(int) * MAX_N * MAX_R * MAX_C);

    for(int f=0; f<friends.size(); ++f){
        bfs(friends[f], R, C, f);
    }

    for(int r=0; r<R; ++r){
        for(int c=0; c<C; ++c){
            unsigned int mx = 0;
            for(int f=0; f<friends.size(); ++f){
                mx = (mx > V[f][r][c] ? mx : V[f][r][c]);
            }
            ans = (ans < mx ? ans : mx);
        }
    }

    return ans;
}

int main()
{
    int T;
    cin>>T;

    for (int t=0; t<T; ++t) {
        int R, C, N;

        cin>>R>>C>>N;
        vector<Cell> friends;

        for (int r=0; r<R; ++r) {
            for(int c=0; c<C; ++c) {
                cin>>M[r][c];
                if(M[r][c]==FRIEND){
                    friends.push_back({r, c});
                }
            }
        }
        ANS[t] = solve(friends, R, C);
        ANS[t] = (ANS[t] >= UINT_MAX ? -1 : ANS[t]);
    }

    for (int t=0; t<T; ++t) {
        cout<<ANS[t]<<endl;
    }
}
