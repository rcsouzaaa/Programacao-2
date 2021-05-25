#include <stdio.h>

#define SET_BIT(Y, BIT) Y = Y | (1 << BIT)
#define CLR_BIT(Y, BIT) Y &= ~(1<<BIT)
#define CPL_BIT(Y, BIT) Y = Y ^ (1 << BIT)
#define TST_BIT(Y, BIT) Y & (1 << BIT )
int main(){

    //SET BIT

    int dado_hex = 0;

    SET_BIT(dado_hex, 4); //Y = 0 ou (1 << 4 ), onde 1 << 4 é 16. A resposta do calculo sera 16 ou 0x10 (duas casas hexadecimais)
    printf("Dado, 4 bit: 0x%.4x\n", dado_hex); // Y = 16

    SET_BIT(dado_hex, 2); //Y = 16 ou (1 << 2 ), onde 1 << 2 é 4. A resposta do calculo sera 20 ou 0x14 (duas casas hexadecimais)
    printf("Dado, 2 bit: 0x%.4x\n", dado_hex);

    //CLR BIT

    int dado_hex2 = 25; // 25 decimal / 11001 binario / 16 hexadecimal

    CLR_BIT(dado_hex2, 3); // Y E o bit invertido deslocado para o segundo mais significativo.
    printf("Dado, bit 3: 0x%.4x\n", dado_hex2); // 10001

    CLR_BIT(dado_hex2, 0);
    printf("Dado, bit 0: 0x%.4x\n", dado_hex2); //11000

    //CPL BIT

    int dado = 10;

    CPL_BIT(dado, 0); // Y = 10 xor (1 << 0), ou seja 10 xor entre Y e bit deslocado (o menos significativo) para ser complementado
    printf("Dado: %d\n", dado); //Y = 11

    CPL_BIT(dado, 3); // Y = 11 xor (1 << 3) , ou seja 10 xor entre Y e bit deslocado (o mais significativo) para ser complementado
    printf("Dado: %d\n", dado); //Y = 3

    //TST BIT

    int dado2 = 10; // 1010 binario

     if(TST_BIT(dado2,2)) // Testando se o segundo bit mais significativo é 1 ou 0
    {
        printf("Dado: 1"); // caso seja 1
    }
    else
    {
        printf("Dado: 0"); //caso seja 0
    }
    return 0;
}
