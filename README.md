# LL1-Parser
编译原理作业，实现LL1文法解析，支持规则灵活定义，错误提示

## enviroment
```
Linux
gcc version >= 3
```

## project constructs
```
|- LL1-Parse
  |- driver    
  |- driver.cpp
  |- scan.h
  |- scan.cpp
  |- grammar.h
  |- grammar.cpp
  |- Makefile       -  makefile
  |- grammar.txt    -  define your own rules
  |- input.txt      -  your own program
```

## usage
**make porject**
```bash
cd /path/to/LL1-Parser
make
```

**run**
```bash
cat input.txt | ./driver grammar.txt
```
