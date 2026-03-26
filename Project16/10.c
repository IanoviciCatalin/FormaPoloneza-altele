int main() {
    int numar = 0b1010;

    char hexNum[32]; // Stocăm rezultatul în baza 16 sub formă de caractere
    int i = 0;
    int j = 0;
    int temp = 0;
    int power = 1;

    while (numar > 0) 
    {
        temp += (numar % 2) * power;
        numar = numar / 2;
        power *= 2;
        i++;

        if (i == 4)
        {
            if (temp < 10)
                hexNum[j] = temp + '0'; // Caracterele pentru cifrele 0-9
            else
                hexNum[j] = temp + 55; // Caracterele pentru cifrele A-F
            j++;
            i = 0;
            temp = 0;
            power = 1;
        }
    }

    // Convertim cifrele rămase, dacă există
    if (i > 0)
    {
        hexNum[j] = temp + '0';
        j++;
    }

    // Terminăm șirul de caractere cu terminatorul '\0'
    hexNum[j] = '\0';

    // Pauză pentru a inspecta variabila hexNum
    // Puteți utiliza comanda watch pentru a urmări conținutul array-ului

    return 0;
}
