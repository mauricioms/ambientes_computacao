def Particao (i, j, A):

    x = A[(i + j) // 2] # Obtem o pivo x

    ok = True
    while ok:
        
        while x > A[i]:
            i += 1

        while x < A[j]:
            j -= 1
        
        if i <= j:
            A[i], A[j] = A[j], A[i] # swap(A[i], A[j])

            i += 1
            j -= 1

        ok = True if i <= j else False

    return i, j

def Ordena(l, r, A):
    
    i, j = Particao(l, r, A)

    if l < j:
        Ordena(l, j, A)

    if i < r:
        Ordena(i, r, A)

    pass

def QuickSort(A):
    n = len(A) - 1
    Ordena(0, n, A)
    pass

