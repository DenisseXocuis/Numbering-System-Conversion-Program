/*  DenisseXocuis
 *  Numering-System-Conversion-Program
 *  Binary,Decimal, Octal & Hexadecimal
 *  2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define T 256 

// prototipos
void menu();
void error();
void salir();
void info();
void pausa();

void dec_bin(int);
void dec_oct(int);
void dec_hex(int);
void bin_dec(int);
void oct_dec(int);
void hex_dec(char hex_n[T]);

int main()
{
    int opc, n;
    char hex_n[T];
    do{
        menu();
        scanf("%d", &opc);

        switch (opc){
        case 1:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            dec_bin(n);
            pausa();
        break;
        case 2:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            dec_oct(n);
            pausa();
            break;

        case 3:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            dec_hex(n);
            pausa();
        break;
        case 4:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
            bin_dec(n);
            pausa();

        break;
        case 5:
            puts("Ingrese el numero a convertir");
            scanf("%d", &n);
			oct_dec(n);
            pausa();
        break;
        case 6:
            puts("Ingrese el numero a convertir");
            scanf("%s", &hex_n);
            hex_dec(hex_n);
            pausa();
        break;
        case 7:
            info();
        break;
        case 0:
            salir();
        break;
        default:
            error();
        }
    } while (opc);
    
return 0;
}

void menu()
{
    system("clear||cls");
    puts("------------------------------------------------------");
    puts("-------CONVERSOR DE DIVERSOS SISTEMAS NUMERICOS-------");
    puts("------------------------------------------------------");
    puts("[1] Convertir de Decimal --> Binario");
    puts("[2] Convertir de Decimal --> Octal");
    puts("[3] Convertir de Decimal --> Hexadecimal");
    puts("[4] Convertir de Binario --> Decimal");
    puts("[5] Convertir de Octal   --> Decimal");
    puts("[6] Convertir de Hexadecimal --> Decimal");
    puts("[7] Acerca de...");
    puts("[0] Salir...");
    printf("Seleccione una opción....  \n>");
}

void error(){
    puts("-------------------");
    puts("--OPCIÓN INVALIDA--");
    puts("-------------------");
    pausa();
}

void salir(){
    puts("---------------------");
    puts("--CERRANDO PROGRAMA--");
    puts("---------------------");
}

void info(){
    system("clear||cls");
    puts("------------------------------------------------------");
    puts("-------CONVERSOR DE DIVERSOS SISTEMAS NUMERICOS-------");
    puts("------------------------------------------------------");
    puts("C. Ing. Denisse Xocuis");
    puts("C. Ing. Guillermo Themsel");
    puts("C. Ing. Karina Coyolt");
    puts("Ingeniería Informatica");
    puts("Versión 0.6");
    puts("© 2023");
    pausa();
}

void pausa(){
    printf("Presione cualquier tecla para continuar . . . ");
    fflush(stdin);
    getchar();
    getchar();
}

void dec_bin(int n){
int R[T], i;
    for(i=0; n > 0; i++){
        R[i] = n%2;
        n /= 2;
    }
    //Imprime el resultado
    printf("El valor binario es: ");
    for(i-=1; i>=0; i--)
        printf("%d", R[i]);
    putchar('\n');
}

void dec_oct(int n){ 
int R[T], i;
	for(i=0; n > 0; i++){
		R[i] = n%8;
		n /= 8;
	} 

	printf("El valor octal es: ");
	for(i-=1; i>=0; i--)
	    printf("%d", R[i]);
    putchar('\n');
}

void dec_hex(int n)
{
    int i=0, t;
    char R[T];


    while (n){
        t=n%16;
            if (t<10) t+=48;
            else t=t+55;
        R[i]=t;
        n/=16;
        i++;
    }
    printf("El valor hexadecimal es: ");
    for (i-=1; i>=0; i--)
    printf("%c", R[i]);
    putchar('\n');
}

void bin_dec(int n){
int R = 0,R1,err;
for(int i = 1;n != '\0' ; i*=2){
    R1 = n%10;
    if(R1 < 0)
        R1 *= -1;

    if(R1 != 1 && R1 != 0){ 
        putchar('\n');
        puts("ERROR: El numero no es binario");
        err = 1;
        break;
        }
    else
        R += (R1 * i);
        n /= 10;
}
    if(err != 1)
        printf("El valor decimal es: %d \n", R);
}

void oct_dec(int n){
int R;
for(int i=1;n !='\0'; i*=8){
    R += (n%10)* i;
    n /= 10;
}
    printf("El valor decimal es: %d \n", R);
}

void hex_dec(char hex_n[T]){
    int R=0, i = 0, t, l;
  
    l = strlen(hex_n)-1;

    while (hex_n[i]) {
  

        if (hex_n[i] >= '0' && hex_n[i] <= '9') 
            t = hex_n[i] - 48;
        else if (hex_n[i] >= 'A' && hex_n[i] <= 'F')
            t = hex_n[i] - 55;

        R += t * pow(16, l);
        l--;
        i++;
    }
    printf("El valor decimal es: %d \n", R);

}
