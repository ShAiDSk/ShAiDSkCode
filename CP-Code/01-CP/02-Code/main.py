def swap_sequence(A, N, P, Q, R, S):
  B = A[:]
  B[P-1:Q] = A[R-1:S]
  B[R-1:S] = A[P-1:Q]
  return B

A = [int(x) for x in input().split()]
N = len(A)
P, Q, R, S = [int(x) for x in input().split()]

B = swap_sequence(A, N, P, Q, R, S)

print(*B)