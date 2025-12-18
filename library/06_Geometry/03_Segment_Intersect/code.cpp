

struct P{
    double x,y;
};
P vec2d(P &a,P &b){
    return{b.x - a.x, b.y - a.y};
}
double cross(P &A, P &B) {
    return A.x * B.y - A.y * B.x;
}
bool onSegment(P &a,P &b, P &p) {
    return min(a.x,b.x)-1e-9<=p.x&&p.x<=max(a.x,b.x)+1e-9
        && min(a.y,b.y)-1e-9<=p.y&&p.y<=max(a.y,b.y)+1e-9;
}
P getIntersectionPoint(P a, P b, P c, P d) {
    P AB = vec2d(a, b);
    P CD = vec2d(c, d);
    P AC = vec2d(a, c);
    double det = cross(AB, CD);
    double t = cross(AC, CD) / det;
    return {a.x + t * AB.x, a.y + t * AB.y};
}
bool segmentIntersect(P &a,P &b, P &c, P&d){
    P AB=vec2d(a,b);
    P AC=vec2d(a,c);
    P AD=vec2d(a,d);
    P CD=vec2d(c,d);
    P CB=vec2d(c,b);
    P CA=vec2d(c,a);

    if(cross(AB,AC)*cross(AB,AD)<0 && cross(CD,CB)*cross(CD,CA)<0)
        return true;
    if(cross(AB,AC)==0 && onSegment(a,b,c))return true;
    if(cross(AB,AD)==0 && onSegment(a,b,d))return true;
    if(cross(CD,CB)==0 && onSegment(c,d,b))return true;
    if(cross(CD,CA)==0 && onSegment(c,d,a))return true;
    return false;

}
void solve() {
    P a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;

    if(segmentIntersect(a,b,c,d)){
        YES
        // Special case: check if lines are collinear
        P AB = vec2d(a, b);
        P CD = vec2d(c, d);
        if(abs(cross(AB, CD))<1e-9){
            cout<<"Segments are collinear"<<endl;
        } else {
            P it = getIntersectionPoint(a, b, c, d);
            cout << "Point: " << it.x << " " << it.y << endl;
        }
    }else{
        NO
    }


}
