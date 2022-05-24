#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#include "ctype.h"
#include "limits.h"
#include "math.h"
#include "string.h"
#include "time.h"

#define MAXTAM 20

typedef long TipoChave;

typedef struct TipoItem
{
  TipoChave Chave;
} TipoItem;

typedef int TipoIndice;
typedef TipoItem TipoVetor[MAXTAM + 1];

void Particao(TipoIndice Esq, TipoIndice Dir, TipoIndice *i, TipoIndice *j, TipoItem *A)
{
  TipoItem x, w;

  *i = Esq;
  *j = Dir;

  x = A[(*i + *j) / 2]; /* obtem o pivo x */

  do
  {
    while (x.Chave > A[*i].Chave)
    {
      (*i)++;
    }

    while (x.Chave < A[*j].Chave)
    {
      (*j)--;
    }

    if (*i <= *j)
    {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;

      (*i)++;
      (*j)--;
    }

  } while (*i <= *j);
}

void Ordena(TipoIndice Esq, TipoIndice Dir, TipoItem *A)
{

  TipoIndice i = 0, j = 0;

  Particao(Esq, Dir, &i, &j, A);

  if (Esq < j)
  {
    Ordena(Esq, j, A);
  }

  if (i < Dir)
  {
    Ordena(i, Dir, A);
  }
}

void QuickSort(TipoItem *A, TipoIndice n)
{
  Ordena(0, n - 1, A);
}

TipoVetor A;

int main()
{
  int i = 0, n = 0;

  scanf("%d", &n);

  if (n <= MAXTAM)
  {
    memset(A, 0, sizeof(TipoItem) * (n + 1));

    for (i = 0; i < n; ++i)
    {
      scanf("%li", &A[i].Chave);
    }

    QuickSort(A, n); // QuickSort

    for (i = 0; i < n; ++i)
    {
      printf("%li, ", A[i].Chave);
    }
  }

  return 0;
}
