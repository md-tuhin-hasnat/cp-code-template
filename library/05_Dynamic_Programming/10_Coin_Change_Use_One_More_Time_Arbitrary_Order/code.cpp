int way(int W) {
    if (W < 0) return INF;
    if (W == 0) return 0;

    int &rf=memo[W];
    if (rf != -1) {
        return rf;
    }
    rf = INF;
    for (int i = 0;i < NC;i++) {
        rf = min(rf, 1 + way(W - C[i]));
    }
    return rf;
}

