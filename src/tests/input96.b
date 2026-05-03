main() {
    auto v[1];
    extrn printf;

    v[0] = 77;

    if (&v[0] != 0) {
        printf("%d*n", *&v[0]);
    }

    printf("%d*n", (&v[0] == 0) ? 0 : 88);

    return 0;
}
