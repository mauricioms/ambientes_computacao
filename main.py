import quick_sort as sort
import random

def main():
    '''
    n = int(input())
    print("N: {}".format(n))
    A = list(map(int, input().split()))
    '''
    
    n = 10
    A = random.sample(range(n//2, 2*n), n)

    print("Origin:", A)
    sort.QuickSort(A)
    print("Sorted:", A)

    pass

if __name__ == "__main__":
    main()

