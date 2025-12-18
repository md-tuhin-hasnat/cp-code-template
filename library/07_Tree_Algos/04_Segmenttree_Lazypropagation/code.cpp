/// sl = segment left,sr = segment right, tre[nod] contain [sl-sr] range
#define ll long long
const int MAX_N =100007;
const int oo = 2e9+10;
int ar[MAX_N];
struct LazyTree{
    vector<int>tre,lazy;
    LazyTree(int sz){
        tre.assign((sz*4)+10,0);
        lazy.assign((sz*4)+10,0);
    }
    inline void lazyUpdate(int nod,int sl,int sr){
        if(lazy[nod]==0)return;
        //tre[nod] += lazy[nod];// change += or = // if we chaking for max,min 
        tre[nod] += lazy[nod]*(sr-sl+1);// change += or =
        if(sl!=sr){
            int left_child = 2*nod , right_child = 2*nod+1;
            lazy[left_child] += lazy[nod], lazy[right_child] += lazy[nod];// change += or =
        }
        lazy[nod]=0;
    }
    void build(int nod,int sl,int sr){
        lazy[nod]=0;
        if(sl==sr){
            tre[nod]=ar[sr];// root node
            return;
        }
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        build(left_child , sl , mid);
        build(right_child , mid+1, sr);
        tre[nod] = tre[left_child] + tre[right_child];///change
    }
    ll query(int nod,int sl,int sr,int ql,int qr){
        lazyUpdate(nod,sl,sr);
        if(ql<=sl && sr<=qr){///fully overlaped
            return tre[nod];
        }
        if(qr<sl || sr<ql)return 0;/// out of the range ,0/-oo/oo;
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        return query(left_child,sl,mid,ql,qr)+query(right_child,mid+1,sr,ql,qr);///change
    }
    void update(int nod,int sl,int sr,int ql,int qr,ll val){
        lazyUpdate(nod,sl,sr);
        if(ql<=sl && sr<=qr){///fully overlaped
            lazy[nod]+=val;
            lazyUpdate(nod,sl,sr);
            return;
        }
        if(qr<sl || sr<ql)return;/// position is out of the range
        int mid = (sl+sr)/2;
        int left_child = 2*nod , right_child = 2*nod+1;
        update(left_child,sl,mid,ql,qr,val);
        update(right_child,mid+1,sr,ql,qr,val);
        tre[nod]=tre[left_child]+tre[right_child];///change
    }
};
signed main(){
    int n,q,ql,qr,ty;
    int val;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    LazyTree lt(n);
    lt.build(1,1,n);//lt.build(1,0,n-1);
    while(1){
        cin>>ty;
        if(ty==1){
            cin>>ql>>qr>>val;
            lt.update(1,1,n,ql,qr,val);
        }else if(ty==2){
            cin>>ql>>qr;
            cout<<lt.query(1,1,n,ql,qr)<<"\n";
        }else{
            break;
        }
    }
    
}
