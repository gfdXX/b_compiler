main() {
    auto f;
    extrn printf;

    f = &printf;
    printf("%d\n", 11);
    f("%d\n", 12);

    return 0;
}
