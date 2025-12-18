struct P{
    double x,y;
};
P pvt;
P vec(P a,P b){return {b.x-a.x,b.y-a.y};}
double Cross(P a,P b){return a.x*b.y-a.y*b.x;}
double eDis(P a,P b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}

bool comp(P a,P b)
{
    double c = Cross(vec(pvt,a),vec(pvt,b));

    if(c) return c>0;
    return eDis(pvt,a)<eDis(pvt,b);

}
vector<P> makeConvexHull(vector<P> p){
    int nConvex=p.size(),i,j;
    if(nConvex<2) return p;
/**     IF ALL POINTS ARE CO-LINER   */
//    j=0;
//    for(i=2;i<nConvex;i++)
//        if(Cross(vec(p[0],p[1]),vec(p[0],p[i]))==0)
//            j++;
//    if(j+2==nConvex)  return P
    pvt=p[0];
    for(int i=1;i<nConvex;i++)
        if(pvt.y>p[i].y)    pvt=p[i];
        else if(pvt.y==p[i].y && pvt.x>p[i].x)    pvt=p[i];

    sort(all(p),comp);
    j=2;
    for(int i=2;i<nConvex;i++)
    {
        //while(j>1 && Cross(vec(p[j-2],p[j-1]),vec(p[j-2],p[i]))<=0) skip same line
        while(j>1 && Cross(vec(p[j-2],p[j-1]),vec(p[j-2],p[i]))<0)    j--;
        p[j++]=p[i];
    }
    p.resize(j);
    return p;
}
void solve(int n) {
    vector<P>v;
    for(int i=0;i<n;i++){
        double x,y;cin>>x>>y;
        v.push_back({x,y});
    }
    double Perimeter=0;
    if(n==1){
        cout<<"("<<sp(v[0].x,1)<<","<<sp(v[0].y,1)<<")\n";
        cout<<"Perimeter length = "<<sp(Perimeter,2)<<"\n";
        return;
    }
    v=makeConvexHull(v);
    reverse(all(v));
    for(int i=0;i<v.size();i++){
        cout<<"("<<sp(v[i].x,1)<<","<<sp(v[i].y,1)<<")-";
        Perimeter+=(eDis(v[i],v[(i+1)%v.size()]));
    }
    cout<<"("<<sp(v[0].x,1)<<","<<sp(v[0].y,1)<<")\n";
    cout<<"Perimeter length = "<<sp(Perimeter,2)<<"\n";
}
