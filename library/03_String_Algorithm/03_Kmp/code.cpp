vector<int> failure_function(string &p){
    vector<int>failure_idx(p.size(),0);
    for(int i=1;i<p.size();i++){
        int j=failure_idx[i-1];
        while(j>0 && p[i]!=p[j]){
            j=failure_idx[j-1];
        }
        if(p[i]==p[j])failure_idx[i]=++j;
    }
    return failure_idx;

}
void KMP(string &txt,string &pat){
    vector<int>failure_idx=failure_function(pat);
    int j=0;
    for(int i=0;i<txt.size();i++){
        while(j>0 && txt[i]!=pat[j])j=failure_idx[j-1];
        if(txt[i]==pat[j]){
            j++;
            if(j==pat.size()){
                cout<<i-pat.size()+1<<" ";
                j=failure_idx[j-1];

            }
        }
    }
  
}