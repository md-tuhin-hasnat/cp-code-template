int sto[20];
int N, R;
void bt(int start, int depth){
    if(depth == R){
        for(int i=0;i<R;i++)
        cout<<sto[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = start;i<=N;i++){
        sto[depth] = i;
        bt(i+1, depth+1);
    }
}
int main(){
    while(cin>>N>>R){
        bt(1, 0);
    }
}




