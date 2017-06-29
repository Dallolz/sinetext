#include <math.h>
#include <stdio.h>
#include <string.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

int getcoord(int x, int a, double p)
{
  double res = sin(x / p);
  return (floor(a * (res + 1)));
}

int main(int ac, char **av)
{
  char str[64];
  double p;
  int a;
  char map[64][64];

  a = atoi(av[2]);
  p = atoi(av[3]);
  
  memset(map, 0, sizeof(map));
  memset(str, 0, 64);
  memcpy(str, av[1], strlen(av[1]));
  
  int cpt1 = 0;
  int cpt = 0;
  int cpt2 = 0;
  while (str[cpt]) {
    //    gotoxy(cpt, getcoord(cpt, a, p));
    map[getcoord(cpt, a, p)][cpt] = str[cpt];
    cpt++;
  }
  cpt = 0;
  while (cpt1 < 64)
    {
      cpt2 = 0;
      while (cpt2 < 64) {
	if (map[cpt1][cpt2] == 0)
	  write(1, " ", 1);
	else
	  write(1, &map[cpt1][cpt2], 1);
	cpt2++;
      }
      cpt1++;
      write(1, "\n", 1);
    }
}
