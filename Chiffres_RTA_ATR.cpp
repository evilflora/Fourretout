#include <iostream>
#include <cstring>

using namespace std;

const int   values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const char* letters[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int   size_lt = (sizeof(values)/sizeof(int))-1;

int convert_to_letters(int, char*);
int convert_to_value(char*, int*);

int main() {
  int input_a        = 1287;
  char output_a[256] = { 0 };
  
  int output_b       = 0;
  char input_b[]    = "MCMXCV";
  
  convert_to_letters(input_a,output_a);
  printf("Chiffre romains: %s\n",output_a);
  
  convert_to_value(input_b,&output_b);
  printf("Chiffre arabes : %d\n",output_b);
}

int convert_to_letters(int in, char* out) {
  int i = size_lt;
  if (in < 0 || in > 9999) return -1;
  while(in > 0) // tant que sa valeur est > 0
  {
    if ((in - values[i]) >= 0) { // on verifie qu'on peut soustraire notre valeur
      strncpy(out,letters[i],strlen(letters[i])); // on copie le chiffre romain dans la chaine
      out+=strlen(letters[i]); // on déplace le curseur dans la chaine
      in -= values[i]; // on soustrait notre valeur
    } else {
        i--; // on passe à notre index suivant, change de valeur et de chiffre romain
    }
  }
  return 0;
}

int convert_to_value(char* in, int* out) {
  int i = size_lt;
  do
  {
    if (strncmp(in,letters[i],strlen(letters[i])) == 0) { // on compare le chiffre romain de la chaine à ceux qu'on connait
      *out += values[i]; // on augmente notre valeur de la valeur arabe du chiffre romain
      in += strlen(letters[i]); // on se déplace dans la chaine de lecture de la longueur du chiffre romain
    } else {
      i--; // on passe à notre index suivant, change de valeur et de chiffre romain
    }
  } while(*in); // tant qu'on atteint pas la fin de la chaine -> \0
  return 0;
}
