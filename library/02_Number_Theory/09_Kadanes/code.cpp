cin>>n;
ll ar[n+6];
ll mx=-9999999999;
ll sum=0;
for(int i=1;i<=n;i++){
    cin>>ar[i];
    sum=max(ar[i],sum+ar[i]);
    mx=max(mx,sum);
}
cout<<mx<<"\n";

