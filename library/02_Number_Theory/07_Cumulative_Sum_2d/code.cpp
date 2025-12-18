int r,c;
scanf("%d%d",&r,&c);
int ar[r+5][c+5],px[r+5][c+5];
for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
        cin>>ar[i][j];

for(int i=0;i<=r;i++)px[i][0]=0;
for(int j=0;j<=c;j++)px[0][j]=0;

px[1][1]=ar[1][1];
for(int i=2;i<=r;i++){
    px[i][1]=px[i-1][1]+ar[i][1];
    
}
for(int j=2;j<=c;j++){
    px[1][j]=px[1][j-1]+ar[1][j];
}
for(int i=2;i<=r;i++)
    for(int j=2;j<=c;j++){
        px[i][j]=px[i-1][j]+px[i][j-1]+ar[i][j]-px[i-1][j-1];
    }
    cout<<"\nprefix sum array :"<<endl;
for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
        cout<<px[i][j]<<" ";
    }
    cout<<"\n";
}
cout<<"Range of summation array (i1,j1)->(i2,j2)"<<endl;
int i1,i2,j1,j2,ans;
cin>>i1>>j1>>i2>>j2;
if(i1>i2)swap(i1,i2);
if(j1>j2)swap(j1,j2);

ans=px[i2][j2]-px[i2][j1-1]-px[i1-1][j2]+px[i1-1][j1-1];

cout<<"sum of range = "<<ans<<endl;


