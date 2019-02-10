//divide-and-conquer
//slide: P80
//求解棋盘覆盖问题
#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1025;
//问题表示
int k;//棋盘大小
int x,y;//特殊方格的位置
//求解问题表示
int board[MAX][MAX];
int tile = 1;
//(tr, tc)表示左上角 (dc, dr)表示特殊点坐标
void ChessBoard(int tr, int tc, int dr, int dc, int size){
    if(size == 1) return;
    int t = tile++;
    int s = size/2;
    //考虑左上角象限
    if(dr<tr+s && dc<tc+s){//特殊方格在此象限中
        ChessBoard(tr, tc, dr, dc, s);
    }else{
        board[tr+s-1][tc+s-1] = t;//用t号L型骨牌覆盖右下角
        ChessBoard(tr, tc, tr+s-1, tc+s-1, s);//将右下角作为特殊方格继续处理该象限
    }
    //考虑右上角象限
    if(dr<tr+s && dc>=tc+s){//特殊方格在此象限中
        ChessBoard(tr, tc+s, dr, dc, s);
    }else{
        board[tr+s-1][tc+s] = t;//用t号L型骨牌覆盖左下角
        ChessBoard(tr, tc+s, tr+s-1, tc+s, s);//将右下角作为特殊方格继续处理该象限
    }
    //考虑左下角象限
    if(dr>=tr+s && dc<tc+s){//特殊方格在此象限中
        ChessBoard(tr+s, tc, dr, dc, s);
    }else{
        board[tr+s][tc+s-1] = t;//用t号L型骨牌覆盖右上角
        ChessBoard(tr+s, tc, tr+s, tc+s-1, s);//将右下角作为特殊方格继续处理该象限
    }
    //考虑右下角象限
    if(dr>=tr+s && dc>=tc+s){//特殊方格在此象限中
        ChessBoard(tr+s, tc+s, dr, dc, s);
    }else{
        board[tr+s][tc+s] = t;//用t号L型骨牌覆盖右下角
        ChessBoard(tr+s, tc+s, tr+s, tc+s, s);//将右下角作为特殊方格继续处理该象限
    }
}
int main(){
    int k = 3;
    ChessBoard(0, 0, 1, 2, 8);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
