int n;
vector<vector<string>>boards;
bool UnderAttack(int row,int col,vector<string>&board){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q')
            return true;
        --row,--col;
    }
    col = dupcol;
    row = duprow;
    while(row<n && col>=0){
        if(board[row][col]=='Q')
            return true;
        ++row,--col;
    }
    row = duprow;
    col = dupcol;
    while(col>=0){
        if(board[row][col]=='Q')
            return true;
        --col;
    }
    return false;
}
void res(int col,vector<string>&board){
    if(col==n){
        boards.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(UnderAttack(row,col,board))
            continue;
        board[row][col]='Q';
        res(col+1,board);
        board[row][col]='.';
    }
}
int main(){
    cin>>n;
    vector<string>board(n,string(n,'.'));
    res(0,board);
    int w=0;
    for(auto ans : boards){
        cout<<"Possible Way :"<<++w<<el;
        for(auto r : ans){
            cout<<r<<el;
        }
        cout<<el;
    }
    board.clear(),boards.clear();

}
