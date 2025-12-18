ll der[MAXN];
void precalculate_derangements() {
    der[0]=1;der[1]=0;der[2]=1;
    for (int i = 3; i < MAXN; i++) {
        der[i]=(i-1)*(der[i-1]+der[i-2])%MOD;
    }
}
