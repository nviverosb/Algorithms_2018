# Program to multiply two matrices using nested loops
#import random
import time

def Matrix(A):

    start = time.time()
    numeroDeInstrucciones = 2*A*A*A-A*A
    MatrixA = [[1 for x in range(A)] for y in range(A)]
    MatrixB = [[2 for x in range(A)] for y in range(A)]
    result = [[0 for x in range(A)] for y in range(A)]

    for i in range(len(MatrixA)):
        # iterate through columns of Y
        for j in range(len(MatrixB[0])):
            # iterate through rows of Y
            for k in range(len(MatrixB)):
                result[i][j] = result[i][j] + MatrixA[i][k] * MatrixB[k][j]
    end = time.time()

    return((end-start)/numeroDeInstrucciones)

  # for r in result:
  #   print(r)

def fib(n):
    if n==0 :
        return 0
    a, b = 0, 1
    for i in range(1, n):
        a, b = b, a+b
    return b

def main():
    n = 50
    #print(fib(10))
    resultados = [[0 for x in range(n)] for y in range(10)]
    promedios = [0 for x in range(n)]

    for i in range(10):
        for j in range(n):
            resultados[i][j] = Matrix(j+1)

    for i in range(n):
        for j in range(10):
            promedios[i] = promedios[i] + resultados[j][i]/10

    for i in range(n):
        print(i, " ", promedios[i])


main()
