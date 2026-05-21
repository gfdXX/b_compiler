main() {
    auto x;
    extrn printf;

    x = 4;

    switch x {
    case 1:
        printf("%d*n", 1);
    case 2:
        printf("%d*n", 2);
    case 3:
        printf("%d*n", 3);
    }

    printf("%d*n", 99);

    return 0;
}
