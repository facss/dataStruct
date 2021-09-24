# 安装gdb

由于mac本机上没有按照gdb，因此需要通过brew install gdb进行安装

# 开始使用gdb

## 介绍gdb可以打开的进程和文件类型

+ 1. 直接使用gdb打开可执行文件：
 ```
gdb program
 ```
+ 2. 打开core文件
```
gdb program core
```
+ 3. 打开执行中的进程
```
gdb program 1234
gdb -p 1234
```

+ 4. 通过args进行参数的传递
```
gdb --args gcc -O2 -c foo.c
```

+ 5. 更多用法可以通过下列获取

```
gdb -help
```

## 退出gdb

执行命令
```
q 或者quit
```

## 其他使用方法
可以用shell命令直接调用gdb
更加详细的介绍后面会补充

## 保存结果到文件中
表示打开日志
```
set logging on
```

关闭日志
```
set logging off
```

修改日志的名字，将file(默认名gdb.txt)修改为file1

```
set logging file file1
```

默认情况下，gdb的日志都是覆盖，可以用下列指令进行日志的追加
```
set logging overwrite [on|off]
```

可以通过下列指令获得日志的相关信息
```
show logging
```

# gdb语法
