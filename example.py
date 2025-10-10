import time

def print_arr(arr):
    print(' '.join(str(x) for x in arr))

def print_mat(mat):
    for row in mat:
        print_arr(row)

def main():
    start = time.time()
    print("Starting a timed operation...")

    a = [1, 2, 3, 4, 5]
    b = [1, 2, 3, 7, 5]
    test = [[1, 2, 3], [1, 5, 6]]
    d = ["hello", "bitch", "its me"]

    print(' '.join(d))
    print_arr(a)

    a = b + a
    print_arr(a)
    print_arr(b)
    print_mat(test)

    for _ in range(1_000_000):
        a = [x + 5 for x in a]

    a = [1, 2, 3, 4, 5]
    a = [x ** 3 for x in a]
    print_arr(a)

    a = [int(x / (x / 2 if x != 0 else 1)) for x in a]
    print_arr(a)

    print("EAX2025QO")

    a = [1, 2, 3, 4, 5]
    a = [x - 5 for x in a]
    print_arr(a)

    end = time.time()
    print(f"Elapsed time: {end - start:.6f} seconds")

if __name__ == "__main__":
    main()
