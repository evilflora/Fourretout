#include <iostream>
#include <cstring>

using namespace std;

const int   values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
const char* letters[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int   size_lt = (sizeof(values)/sizeof(int))-1;

int convert_to_letters(int, char*);
int convert_to_value(char*, int*);
int convert_date(char*, char*, char);

int main() {
  int input_a        = 1287;
  char output_a[256] = { 0 };
  
  int output_b       = 0;
  char input_b[]     = "MCMXCV";
  
  char input_c[]     = "MCMXCV-II-VII";
  char output_c[256] = { 0 };
  
  convert_to_letters(input_a,output_a);
  printf("Chiffre romains: %s\n",output_a);
  
  convert_to_value(input_b,&output_b);
  printf("Chiffre arabes : %d\n",output_b);
  
  convert_date(input_c,output_c,'a');
  printf("Date arabes    : %s\n",output_c);
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

int convert_date(char* in, char* out, char sens) {
  char* pch;
  
  if (sens == 'a') {
    int tmp = 0, offset = 0;;
    pch = strtok (in," -/"); // recherche le premier caractère parmit les séparateurs
    while (pch != NULL)
    {
      convert_to_value(pch,&tmp); // on converti le premier bout de chaine en nombre
      offset += snprintf(out+offset,64-offset,"%02d ", tmp); // on créé la chaine, le snprintf retourne la longueur de la chaine
      tmp = 0; // on reset la valeur de la convertion
      pch = strtok (NULL, " ,.-"); // on recherche le prochain bout de chaine
      
    }
    return 0;
  } else if (sens == 'r') {
    return 0;
  } else {
    return -1;
  }
}
