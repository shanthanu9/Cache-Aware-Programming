## Processor affinity

Found out this interesting command called taskset. With this one can view processor affinity for a process. In a multicore system, processor affinity is the processors on which the given process will run on.

`$ taskset -p <pid>` returns the a bit mask of processor affinity of process pid.

```
$ taskset -p 1
pid 1's current affinity mask: f
```

My computer has four cores. Note that processor affinity is returned as a hexadecimal number. For a prettier output, -c flag can be used

```
$ taskset -cp 1
pid 1's current affinity list: 0-3
```

You can also set the processor affinity of a process.

```
$ taskset -p 0x1 1
pid 1's current affinity mask: f
taskset: failed to set pid 1's affinity: Operation not permitted
```

Ofcourse, u can't mess around with root :P

You can also run a program with a processor affinity

```
$ taskset 0x1 <location of program to run>
```
