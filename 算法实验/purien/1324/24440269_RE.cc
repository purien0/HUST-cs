#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 50;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
 
int n,m,l, mp[maxn][maxn]; 
bool visited[maxn][maxn];
int queuex[maxn*maxn], queuey[maxn*maxn];
 
int main(){
    int i,j, x, y, k, head, tail, ans, cnt=1;
    bool flag;
    int tmp_x, tmp_y, tmp_val,  cur_x, cur_y, cur_val;
    while(scanf("%d %d %d", &n, &m, &l) != EOF){
        if(n==0 && m==0 && l==0){
            break;
        }
        memset(mp, 0, sizeof(mp));
        memset(visited, false, sizeof(visited));
        head = tail = 0;
        for(i=0; i<l; i++){
            scanf("%d %d", &x, &y);
            if(i == 0){
                queuex[head] = x;
                queuey[head++] = y;
            }
            mp[x][y] = l-i;
        }
        scanf("%d", &k);
        for(i=0; i<k; i++){
            scanf("%d %d", &x, &y);
            visited[x][y] = true;
        }
        ans = -1;   flag = false;
        while(head >= tail){
            if(flag){ break; }
            tmp_x = queuex[tail]; tmp_y = queuey[tail++];
            tmp_val = mp[tmp_x][tmp_y];
            for(i=0; i<4; i++){
                cur_x = dx[i] + tmp_x;
                cur_y = dy[i] + tmp_y;
                if(cur_x == 1 && cur_y == 1){
                    ans = tmp_val + 1;
                    flag = true;
                    break;
                }
                if( cur_x >=1 && cur_x <= n && cur_y>=1 && cur_y<=m && \
                    !visited[cur_x][cur_y] && fabs(mp[cur_x][cur_y] - tmp_val)>=l){
                    queuex[head] = cur_x;
                    queuey[head++] = cur_y;
                    mp[cur_x][cur_y] = tmp_val + 1;
                }
            }
        }
        if(ans != -1){
            printf("Case %d: %d\n", cnt++, ans-l);
        }else{
            printf("Case %d: %d\n", cnt++, ans);
        }
    }
    return 0;
}