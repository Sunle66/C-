//在线OJ10-----牛客

//1.年终奖

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        if(board.empty())
            return 0;
        for(int i = 1;i < 6;i++){
            board[0][i] += board[0][i - 1];
            board[i][0] += board[i - 1][0];
        }
        for(int i = 1;i < 6;i++){
            for(int j = 1;j < 6;j++){
                int upnum = board[i - 1][j] + board[i][j];
                int leftnum = board[i][j - 1] + board[i][j];
                board[i][j] = max(upnum,leftnum);
            }
        }
        return board[5][5];
    }
};

//2.迷宫问题

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> _maze;//迷宫矩阵
vector<vector<int>> _temp;//存储当前路径，第一维表示位置
vector<vector<int>> _best;//存储最佳路径

void Track(int i, int j)
{
    _maze[i][j] = 1;//表示当前节点已走，不可再走
    _temp.push_back({ i, j });//将当前节点加入到路径中

    if (i == N - 1 && j == M - 1) //判断是否到达终点
        if (_best.empty() || _temp.size() < _best.size())
            _best = _temp;

    if (i - 1 >= 0 && _maze[i - 1][j] == 0)//探索向上走是否可行
        Track(i - 1, j);
    if (i + 1 < N && _maze[i + 1][j] == 0)//探索向下走是否可行
        Track(i + 1, j);
    if (j - 1 >= 0 && _maze[i][j - 1] == 0)//探索向左走是否可行
        Track(i, j - 1);
    if (j + 1 < M && _maze[i][j + 1] == 0)//探索向右走是否可行
        Track(i, j + 1);
    _maze[i][j] = 0;
    _temp.pop_back();
}

int main(){

    while (cin >> N >> M){
        _maze = vector<vector<int>>(N, vector<int>(M, 0));
        _temp.clear();
        _best.clear();
        for (auto &i : _maze)
            for (auto &j : i)
                cin >> j;
        Track(0, 0);
        for (auto i : _best)
            cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
    }
    return 0;
}
