# URISC

```Python
__author__ = 'asdawej'
```

The simulation interpreter of URISC.

An index of URISC only contain 3 operands - `pos1 pos2 label`. For every execution cycle, `MEM[pos2]` will be replaced by `MEM[pos2]-MEM[pos1]`, then if `MEM[pos2] < 0`, the program goto `line`.

`main.urisc` is the code of a multiplication program. Should be noticed: `0` for `line` is to kill the program. The description is:

```PowerShell
CCLR:       C,    C,    BEF
WHILE:      ONE,  A,    CONT
TEMPCLR:    TEMP, TEMP, START
START:      B,    TEMP, ADD
ADD:        TEMP, C,    BACK
BACK:       ONE,  TEMP, WHILE
CONT:       ...

TEMP:       WORD 0
ONE:        WORD 1
```

`data.txt` is the result for th WORD:

```PowerShell
0   0   ;TEMP
1   1   ;ONE
2   10  ;A
3   20  ;B
4   30  ;C, for general situation
```
