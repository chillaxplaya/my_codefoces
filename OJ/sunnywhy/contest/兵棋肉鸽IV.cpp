#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Piece {                              // 兵棋结构体
    int power;                              // 战斗力值
    int cells;                              // 占用的格子数
    int dr[4], dc[4];                       // 占用格子相对于第一个格子的行偏移和列偏移
};

int main() {
    int numK;
    cin >> numK;
    vector<Piece> pieces(numK);             // 使用vector存储兵棋信息
    
    // 读取所有兵棋的信息
    for (int i = 0; i < numK; ++i) {
        char s;
        int a, h, w;
        cin >> s >> a >> h >> w;
        pieces[i].power = a;
        
        int r0 = -1, c0 = -1, count = 0;    // 记录第一个占用格子的坐标和总占用数
        for (int r = 0; r < h; ++r) {
            string row;
            cin >> row;
            for (int c = 0; c < (int)row.length(); ++c) {
                if (row[c] == s) {
                    if (r0 == -1) {         // 记录第一个占用格子
                        r0 = r;
                        c0 = c;
                    }
                    pieces[i].dr[count] = r - r0;     // 计算行偏移
                    pieces[i].dc[count] = c - c0;     // 计算列偏移
                    count++;
                }
            }
        }
        pieces[i].cells = count;            // 保存占用格子数
    }
    
    int n, m;
    cin >> n >> m;
    const int MAX_NM = n * m;
    const int MAX_MASK = 1 << (m + 2);      // 状态压缩的最大掩码数
    
    vector<vector<int>> dp(MAX_NM + 1, vector<int>(MAX_MASK, -1));  // DP数组
    dp[0][0] = 0;                           // 初始状态
    
    // 按行优先顺序遍历每个格子
    for (int p = 0; p < n * m; ++p) {
        int r = p / m, c = p % m;           // 将格子下标转换为行r和列c
        
        for (int mask = 0; mask < MAX_MASK; ++mask) {
            if (dp[p][mask] < 0) continue;   // 如果当前状态不可达，跳过
            
            int nxt = mask >> 1;             // 不放置兵棋时，状态右移一位
            dp[p + 1][nxt] = max(dp[p + 1][nxt], dp[p][mask]);  // 更新不放兵棋的状态
            
            if (!(mask & 1)) {              // 如果当前格子未被占用，尝试放置兵棋
                for (const auto& piece : pieces) {  // 遍历所有兵棋类型
                    bool ok = true;
                    
                    // 检查兵棋是否可以放置
                    for (int j = 0; j < piece.cells; ++j) {
                        int nr = r + piece.dr[j];
                        int nc = c + piece.dc[j];
                        
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {  // 超出棋盘范围
                            ok = false;
                            break;
                        }
                        
                        int delta = piece.dr[j] * m + piece.dc[j];    // 计算偏移对应的掩码位
                        if (mask & (1 << delta)) {                    // 检查该格子是否已被占用
                            ok = false;
                            break;
                        }
                    }
                    
                    if (ok) {               // 可以放置
                        int nm = mask;
                        for (int j = 0; j < piece.cells; ++j) {
                            nm |= (1 << (piece.dr[j] * m + piece.dc[j]));  // 设置占用格子的掩码位
                        }
                        int nxtP = nm >> 1;                                // 放置后下一个状态
                        dp[p + 1][nxtP] = max(dp[p + 1][nxtP], dp[p][mask] + piece.power);  // 更新状态
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int msk = 0; msk < MAX_MASK; ++msk) {
        ans = max(ans, dp[n * m][msk]);     // 遍历最终状态，取最大值
    }
    cout << ans << "\n";
    return 0;
}