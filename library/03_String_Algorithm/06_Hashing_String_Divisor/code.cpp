void string_divisors(string const &s){/// nlog(n)
    hashing(s);
    int n=s.size();
    for(int len=1;len<=n;len++){
        bool ok=true;
        for(int i=0;i+len-1<n;i+=len){
            ok &= sub_hash(i,i+len-1)==sub_hash(0,len-1);
            
            if(i+len+len-1>=n && i+len<=n-1){///partial maching
                ok &= sub_hash(i+len,n-1)==sub_hash(0,n-1-i-len);
            }
        }
        if(ok==true){
            cout<<s.substr(0,len)<<"\n";
        }
    }
}