main() {
    extrn printf, value, table;

    printf("%d\n", value);
    value = 6;
    printf("%d\n", value);

    printf("%d\n", table[0]);
    table[1] = value + table[0];
    printf("%d\n", table[1]);

    return 0;
}

value 5;
table[2] 7, 0;
