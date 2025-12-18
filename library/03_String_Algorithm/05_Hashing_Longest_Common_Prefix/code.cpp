void lcp(int i1,int j1,int i2,int j2){
     int l=1,r=min(j1-i1+1,j2-i2+1);/// minimum length of two string
     int ans=0;
     while(l<=r){
         int mid =l+r >>1;
         if(sub_hash(i1,i1+mid-1,txthsh)==sub_hash(i2,i2+mid-1,pathsh)){
             ans=mid;
             l=mid+1;
         }else{
             r=mid-1;
         }
     }
     cout<<ans<<"\n";
     cout<<txt.substr(i1,ans)<<"\n";
}
