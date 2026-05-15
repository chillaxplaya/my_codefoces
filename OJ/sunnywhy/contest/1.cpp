#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstdlib>

using namespace std;

const int MAXN = 200005;                            // 最大节点数：2*不同值的个数
const int MAX_TOKENS = 100005;                      // 最大token数量

vector<int> adj[MAXN];                              // 邻接表
bool visited[MAXN];                                 // 标记节点是否被访问

int rawVals[MAX_TOKENS];                            // 原始值数组
bool rawMarks[MAX_TOKENS];                          // 原始标记数组
int mappedVals[MAX_TOKENS];                         // 离散化后的值下标
int nTokens = 0;                                    // token计数器

map<int, int> valToId;                              // 值到离散化下标的映射
int idCounter = 0;                                  // 离散化下标计数器

int getId(int val) {
    if (valToId.find(val) == valToId.end()) {       // 如果值未出现过
        valToId[val] = idCounter++;                 // 分配新下标
    }
    return valToId[val];                            // 返回下标
}

int main() {
    ios::sync_with_stdio(false);                    // 关闭同步，提高I/O速度
    cin.tie(NULL);                                  // 解除cin和cout的绑定

    string token;
    while (cin >> token) {                          // 读取每个token
        bool hasMark = false;
        string numStr = token;
        
        if (token.length() > 0 && token[token.length() - 1] == '*') { // 如果token以'*'结尾
            hasMark = true;                                            // 标记为有初始标记
            numStr = token.substr(0, token.length() - 1);              // 去掉'*'得到数字字符串
        }
        
        int val = atoi(numStr.c_str());             // 转换为整数
        rawVals[nTokens] = val;                     // 存储原始值
        rawMarks[nTokens] = hasMark;                // 存储原始标记
        
        if (val != 0) {
            mappedVals[nTokens] = getId(val);       // 非零值离散化
        } else {
            mappedVals[nTokens] = -1;               // 0值用-1表示
        }
        
        nTokens++;
    }

    // 构建传播图：遍历所有相邻正整数对
    for (int i = 0; i < nTokens - 1; ++i) {
        if (rawVals[i] != 0 && rawVals[i+1] != 0) { // 相邻两个都是正整数
            int u = mappedVals[i];                  // 左值的离散化下标
            int v = mappedVals[i+1];                // 右值的离散化下标
            
            // 添加无向边：R(u) <-> L(v)
            // R(u)节点编号为2*u, L(v)节点编号为2*v+1
            adj[2 * u].push_back(2 * v + 1);        // R(u) -> L(v)
            adj[2 * v + 1].push_back(2 * u);        // L(v) -> R(u)
        }
    }

    queue<int> q;                                   // BFS队列
    
    // 初始化：将所有初始标记对应的状态激活
    for (int i = 0; i < nTokens - 1; ++i) {
        if (rawMarks[i] && rawVals[i] != 0 && rawVals[i+1] != 0) {
            int u = mappedVals[i];                  // 左值离散化下标
            int v = mappedVals[i+1];                // 右值离散化下标
            
            if (!visited[2 * u]) {                  // 激活R(u)
                visited[2 * u] = true;
                q.push(2 * u);
            }
            if (!visited[2 * v + 1]) {              // 激活L(v)
                visited[2 * v + 1] = true;
                q.push(2 * v + 1);
            }
        }
    }

    // BFS传播
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (size_t i = 0; i < adj[curr].size(); ++i) {
            int next = adj[curr][i];
            if (!visited[next]) {                   // 如果相邻节点未访问
                visited[next] = true;               // 标记并加入队列
                q.push(next);
            }
        }
    }

    // 输出结果
    for (int i = 0; i < nTokens; ++i) {
        if (i > 0) cout << " ";                     // 除第一个外，前面加空格
        
        cout << rawVals[i];                         // 输出原始值
        
        // 判断是否需要输出'*'
        if (rawVals[i] != 0 && i + 1 < nTokens && rawVals[i+1] != 0) {
            int u = mappedVals[i];                  // 当前值的离散化下标
            int v = mappedVals[i+1];                // 下一个值的离散化下标
            
            bool printMark = false;
            if (rawMarks[i]) printMark = true;      // 原始标记存在
            if (visited[2 * u]) printMark = true;   // R(u)状态激活
            if (visited[2 * v + 1]) printMark = true; // L(v)状态激活
            
            if (printMark) {
                cout << "*";
            }
        }
    }
    cout << endl;                                   // 输出换行

    return 0;
}