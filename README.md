# Cache Aware Programming

Here I analyse performance of programs with respect to cache hits. I have also considered possible optimizations for improving cache hits.

A (not so) brief introduction to memory heirarchy:

A baking chocolate chip analogy: ([credit](https://stackoverflow.com/questions/1126529/what-is-the-cost-of-an-l1-cache-miss))

    - Registers are your hands: if an ingredient is in your hands, you can just drop it in the dough.
    - L1 is the kitchen counter. If something is not in your hands, it is still fairly quick to get if it is on the counter.
    - L2 is the fridge. It is still quick, but you need to walk to the fridge, open it, get stuff out of the way, get the item, close the fridge...
    - L3 is your cupboard: it's further away from the fridge, packed with other items, etc.
    - DRAM is the corner store: you need to grab your wallet, put on your pants, forget your keys, and walk 5 minutes.
    - Hard drive is driving to another city to buy your can of beans.

Following is the brief details of my cpu. All the stats provided for programs run on my cpu:)

```
Architecture:        x86_64
CPU op-mode(s):      32-bit, 64-bit
Byte Order:          Little Endian
CPU(s):              4
On-line CPU(s) list: 0-3
Thread(s) per core:  2
Core(s) per socket:  2
Socket(s):           1
NUMA node(s):        1
Vendor ID:           GenuineIntel
CPU family:          6
Model:               69
Model name:          Intel(R) Core(TM) i3-4005U CPU @ 1.70GHz
Stepping:            1
CPU max MHz:         1700.0000
CPU min MHz:         800.0000
BogoMIPS:            3392.19
Virtualization:      VT-x
L1d cache:           32K
L1i cache:           32K
L2 cache:            256K
L3 cache:            3072K
NUMA node0 CPU(s):   0-3
```

The following command gives cpu details:
```bash
$ lscpu
```
To get the basic details of cache:
```
$ lscpu | grep cache
```
To get more details on cache:
```
$ dmidecode -t cache  #maybe run as sudo
```
To get more details on RAM:
```
$ free -h 
```
