
def generate_array(N):
    arr = [0] * N
for i in range(0, N, 2):
    arr[i] = 7
    if i + 1 < N:
        arr[i + 1] = 5
    return arr

T = int(input())

for in range(T):
    N = int(input())
    # Generate the array and print 
    result = generate_array(N)
    print(*result)