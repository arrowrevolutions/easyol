import time

start_time = time.perf_counter()

a=[1,2,3,4,5]

b=[1,2,5,7,3]

a+=b

print(a)
#  a.reverse()


end_time = time.perf_counter()
elapsed_time = end_time - start_time

print(f"Elapsed time: {elapsed_time:.8f} seconds")
