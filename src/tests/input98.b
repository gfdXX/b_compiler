/* Comments use the PL/I form and disappear wherever whitespace can occur. */
main/* comment between identifier and parameter list */() {
    auto x;
    extrn printf;

    x = 4 /* this whole block is ignored: + 100 */ + 1;
    printf("%d*n", x);

    printf("A*nB*n");

    printf("%d*n", '*n');
    printf("%d*n", '*t');
    printf("%d*n", '**');
    printf("%d*n", '*"');
    printf("%d*n", '*(');
    printf("%d*n", '*)');
    printf("%d*n", '*0');
    printf("%d*n", '*e');

    return 0;
}
