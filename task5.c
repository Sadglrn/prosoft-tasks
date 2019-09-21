/*
Имеем чистый C. Напишите generic функцию линейного поиска в массиве. И приведите пример использования вашей функции.
*/

#include <stdio.h>
#include <string.h>

int lSearch(void *key, void *base, int n, int elemSize,
            int (*cmp)(void*, void*))
{
  for (int i = 0; i < n; i++)
  {
    if (cmp(key, (char*)base + i * elemSize) == 0)
      return i;
  }
  return -1;

}

int FloatCmp(void *p1, void *p2)
{
  if (*(float*)p1 > *(float*)p2)
    return 1;
  else if (*(float*)p1 < *(float*)p2)
    return -1;
  else
    return 0;
}


int IntCmp(void *p1, void *p2)
{
  int *ip1 = (int*)p1;
  int *ip2 = (int*)p2;

  return *ip1 - *ip2;
}


int main(void) 
{
  
  int ikey = 4;
  int iarray[] = {4, 3, 1};
  int r1 = lSearch(&ikey, iarray, 3, sizeof(int), IntCmp);
  printf("Search in int array: %d\n", r1);
  

  float fkey = 6.2;
  float farray[] = {4.2, 7.89, 5.8, 6.2, 9.11};
  int f1 = lSearch(&fkey, farray, 5, sizeof(float), FloatCmp);
  printf("Search in float array: %d\n", f1);

  return 0;
}
