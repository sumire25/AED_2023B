#include<stdio.h>
#define maxLetters 26

int main(){
  int letters[maxLetters];
  int n;
  char str[101];

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s", str);
    for(int i = 0; i < maxLetters; i++) letters[i] = 0;
    int max = 0;
    int len = 0;
    char *iter = str;
    while(*iter){
      int idx = *iter- 'A';
      letters[idx]++;
      /*if(letters[idx] > max)
        max = letters[idx];*/
      max = (letters[idx] > max) ? letters[idx] : max;
      len++;
      iter++;
    }
    printf("Caso #%d: %d, %s\n", i + 1, len - max, str);
  }
}