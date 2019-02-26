## Sequentail access vs Strided Access

The following analysis is inspired by this [blog](https://hcoelho.com/blog/45/Cache-friendly_code:_experimenting_with_cache_hit_and_miss_in_C).

Analysing cache misses for two programs accessing array sequentially and in intervals (with gaps).

The following command is used to analyze the cache misses:
```
$ perf stat -B -e cache-references,cache-misses <compiled program path>
```

The above command may need sudo access.

1.c and 2.c are programs where arrays are accessed sequentially and strided manner. The programs are compiled with -O0 flag to disable compiler optimizations.

Below is the performance for 1.c:
```
Sum: 90000; Iterations: 10000

 Performance counter stats for './1.o':

            13,403      cache-references                                            
             5,558      cache-misses              #   41.468 % of all cache refs    

       0.001272111 seconds time elapsed
```

Below is the performace for 2.c:
```
Sum: 90000; Iterations: 10000

 Performance counter stats for './2.o':

          8,29,963      cache-references                                            
          6,81,837      cache-misses              #   82.153 % of all cache refs    

       0.269232804 seconds time elapsed
```

Observe the drastic difference in performance in the above two programs.

Now let's consider the performace of 2.c by changing the size of inteval.

**Interval = 10000**
```
          6,09,099      cache-misses              #   78.519 % of all cache refs    
```

**Interval = 1000**
```
            99,307      cache-misses              #   68.498 % of all cache refs    
```

**Interval = 100**
```
            21,657      cache-misses              #   46.380 % of all cache refs    
```

**Interval = 10**
```
             5,917      cache-misses              #   33.957 % of all cache refs    
```

There is around 10% differnce in 10000 and 1000 sized intervals. But there is a drastic improvement for 100 intervals. Intuitively, this is because the array can be loaded into the cache for 100 sized intervals. 


