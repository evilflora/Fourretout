#include <iostream>
#include <cstring>

/*
* Conversion des chiffres arabes en romain
* Conversion des chiffres romains en arabe
*/

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
    if ((in - values[i]) >= 0) {
      strncpy(out,letters[i],strlen(letters[i]));
      out+=strlen(letters[i]);
      in -= values[i];
    } else {
        i--;
    }
  }
  return 0;
}


int convert_to_value(char* in, int* out) {
  int i = size_lt;
  do
  {
    if (strncmp(in,letters[i],strlen(letters[i])) == 0) {
      *out += values[i];
      in += strlen(letters[i]);
    } else {
      i--;
    }
  } while(*in); // tant qu'on atteint pas la fin de la chaine -> \0
  return 0;
}
