bool startsWithOne(int n) {
    while (n / 10 > 0) n /= 10;
    return n == 1;
}