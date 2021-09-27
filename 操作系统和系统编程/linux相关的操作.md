## 如何让linux进程在后台运行

[引用的微信公众号原文](https://mp.weixin.qq.com/s/9NhoeVMqgVivBskmzhq6XQ)

一般有两种方式

+ 1)使用command & 后台运行，关掉终端会停止运行
+ 2)nohup command & 后台运行，关掉终端也会继续运行

注意事项

+ (1)如果使用nohup执行程序未显示进行标准输出重定向，则标准输出默认重定向当前工作目录的 nohup.out 文件中。如果当前工作目录的 nohup.out 文件不可写，输出重定向到 $HOME/nohup.out 文件中。如果没有文件能创建或打开用于追加，那么 command 参数指定的命令不可调用。
+ (2) 如果标准错误未显示重定向，那么标准错误默认重定向到与标准输出相同的文件。

# 命令格式
```
nohup COMMAND [ARGS]
nohup OPTION
```
# 选项说明

```
--help

 显示帮助信息并退出

--version

 显示版本信息并退出
 ```

# 常用示例

（1）使用nohup 命令提交作业，那么在缺省情况下该作业的所有输出都被重定向到一个名为nohup.out的文件中，除非另外指定了输出文件。

```
nohup ./test.sh &
```

（2）标准输出与标准错误输出重定向。

```
nohup ./test.sh > test.log 2>&1 &
```

（3）指定输出文件， 输出被重定向到output.txt文件中

```
nohup bash a.sh &> error.txt
``` 

注意：
+ 1）2>&1 标识标准错误输出重定向等同于标准输出重定向，即标准错误输出也重定向到文件test.log;

+ 2）& 命令是命令放在后台执行，需要放在命令的最后面。