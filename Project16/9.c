int main() {
    int numar = 5;

    int binaryNum[32];
    int i = 0;
    while (numar > 0) 
    {
        binaryNum[i] = numar % 2;
        numar = numar / 2;
        i++;
    }

    return 0;
}
