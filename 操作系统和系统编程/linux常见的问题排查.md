
## CPU使用率

- 用户CPU
- 系统CPU
- IOWAIT
- 软中断
- 硬中断
- 窃取CPU
- 客户CPU

### top

查看CPU负载情况

`top -c `，然后按1

```
top - 14:32:54 up 136 days, 22:31, 13 users,  load average: 4.34, 4.79, 5.03
Tasks: 666 total,   2 running, 662 sleeping,   0 stopped,   2 zombie
%Cpu0  :  6.1 us,  6.1 sy,  0.0 ni, 87.4 id,  0.0 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu1  :  4.8 us,  5.2 sy,  0.0 ni, 90.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu2  :  5.2 us,  3.7 sy,  1.5 ni, 88.1 id,  1.1 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu3  :  5.5 us,  5.8 sy,  0.0 ni, 88.3 id,  0.4 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu4  :  5.1 us,  5.8 sy,  1.5 ni, 87.3 id,  0.0 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu5  : 21.2 us,  4.9 sy,  0.0 ni, 73.5 id,  0.0 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu6  :  4.7 us,  6.5 sy,  0.0 ni, 88.7 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu7  :  7.1 us,  7.1 sy,  0.0 ni, 85.8 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu8  :  4.0 us,  6.6 sy,  0.0 ni, 89.4 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu9  :  5.1 us,  5.1 sy,  0.0 ni, 89.1 id,  0.7 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu10 :  4.3 us,  5.8 sy,  0.0 ni, 89.1 id,  0.4 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu11 :  2.8 us,  4.6 sy, 22.7 ni, 68.1 id,  1.8 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu12 :  4.7 us,  5.0 sy, 11.1 ni, 78.5 id,  0.7 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu13 :  4.7 us,  7.2 sy,  0.0 ni, 87.7 id,  0.4 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu14 :  4.0 us,  5.5 sy,  0.0 ni, 90.1 id,  0.4 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu15 :  3.2 us,  6.8 sy,  9.3 ni, 80.3 id,  0.4 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu16 :  5.1 us,  6.9 sy,  0.0 ni, 88.1 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu17 :  4.8 us,  5.2 sy,  0.0 ni, 90.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu18 :  4.1 us,  5.6 sy,  0.0 ni, 90.4 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu19 :  7.4 us,  5.7 sy,  0.0 ni, 85.8 id,  0.7 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu20 :  4.3 us,  7.6 sy,  0.0 ni, 88.1 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu21 :  4.0 us,  4.7 sy,  6.9 ni, 82.5 id,  1.8 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu22 :  5.2 us,  5.5 sy,  0.0 ni, 88.9 id,  0.4 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu23 :  5.4 us,  7.9 sy,  0.0 ni, 86.6 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu24 :  5.0 us,  4.6 sy, 13.5 ni, 74.0 id,  2.8 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu25 :  4.7 us,  6.1 sy,  0.0 ni, 87.1 id,  1.8 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu26 :  6.8 us,  5.7 sy,  0.0 ni, 87.1 id,  0.4 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu27 :  7.0 us,  9.4 sy, 11.5 ni, 71.4 id,  0.3 wa,  0.0 hi,  0.3 si,  0.0 st
%Cpu28 :  5.0 us,  6.8 sy,  0.0 ni, 87.5 id,  0.4 wa,  0.0 hi,  0.4 si,  0.0 st
%Cpu29 :  5.8 us,  6.2 sy,  0.0 ni, 88.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu30 :  6.6 us,  4.4 sy,  1.1 ni, 87.2 id,  0.7 wa,  0.0 hi,  0.0 si,  0.0 st
%Cpu31 :  5.0 us,  6.8 sy,  7.6 ni, 79.1 id,  1.4 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem : 16019204 total,   328248 free, 12364760 used,  3326196 buff/cache
KiB Swap: 15625212 total, 10402604 free,  5222608 used.  2033816 avail Mem 

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND                                                                                                                                                             
29045 root      20   0 1244916 396268 269764 S  18.8  2.5   2142:31 ./broom_group_media_brpc_1100_d                                                                                                                                     
 6656 root      20   0 1187684 359588 266724 S  18.2  2.2  18596:30 ./broom_group_media_brpc_5501_d                                                                                                                                     
 4336 root      20   0 1214084 372632 269132 S  17.8  2.3   2046:57 ./broom_group_media_brpc_2200_d                                                                                                                                     
24681 root      20   0 1202976 368284 270688 S  17.8  2.3   2082:25 ./broom_group_media_brpc_4400_d                                                                                                                                     
10592 root      20   0 1195472 348764 267004 S  17.2  2.2   6161:24 ./broom_group_media_brpc_4404_d                                                                                                                                     
 8413 root      20   0  218532  36040   3000 S  16.2  0.2   3275:44 ./live_http2yy_d                                                                                                                                                    
 7230 root      20   0  938812 331888 267844 S  14.2  2.1   2106:59 ./live_brpc_send_gift_v1_d                                                                                                                                          
15818 root      20   0 1110788 368732 272232 S  13.5  2.3  25358:43 ./brpc_msg_proxy_d                                                                                                                                                  
 4814 root      20   0  908832 315220 253580 S  12.9  2.0   1862:11 ./live_brpc_gift_logistics                                                                                                                                          
26926 root      20   0  915920 342632 267196 S  12.9  2.1   1400:43 ./broom_group_access_brpc_d --flagfile=../conf/gflags.conf                                                                                                          
14474 root      20   0 1120996 341884 269756 S  12.5  2.1  19069:05 ./brpc_inbox_d                                                                                                                                                      
16065 root      20   0  972144 370572 268448 S  12.5  2.3  17554:01 ./broom_group_access_proxy_brpc_d                                                                                                                                   
29360 root      20   0 1105348 348304 269816 S  12.5  2.2  24949:41 ./brpc_msg_store_d                                                                                                                                                  
31382 root      20   0  789988 299168 264200 S  12.5  1.9  24312:59 ./live_brpc_gift_log_d                                                                                                                                              
 5416 root      20   0  634500  51468   5644 S  12.2  0.3   3872:13 ./live_brpc_currency_consumer_d                                                                                                                                     
19066 root      20   0  920068 343352 267236 S  12.2  2.1   1355:52 ./broom_group_access_brpc_d --flagfile=../conf/gflags.conf                                                                                                          
26144 root      20   0  915692 340472 267220 S  12.2  2.1   1401:58 ./broom_group_access_brpc_d --flagfile=../conf/gflags.conf                                                                                                          
26572 root      20   0  915664 340948 267144 S  12.2  2.1   1364:01 ./broom_group_access_brpc_d --flagfile=../conf/gflags.conf                                                                                                          
32135 root      20   0  926988 327560 265520 S  12.2  2.0  12759:30 ./broom_group_mic_brpc_4404_d                                                                                                                                       
10068 root      20   0  899056 329404 267520 S  11.9  2.1   1871:00 ./brpc_record_list_query_d                                                                                                                                          
15966 root      20   0  986324 381644 287672 S  11.9  2.4  17537:46 ./broom_group_access_proxy_brpc_d                                                                                                                                   
21762 root      20   0  901448 336560 265620 S  11.9  2.1  12527:01 ./broom_group_mic_brpc_5501_d                                                                                                                                       
25575 root      20   0  942512 333752 271208 S  11.9  2.1   2092:42 ./live_brpc_broadcast_d                                                                                                                                             
31757 root      20   0  896000 336032 266868 S  11.9  2.1   4974:04 ./live_brpc_giftlog_info                                                                                                                                            
14959 root      20   0  896552 331884 263132 S  11.6  2.1   1891:41 ./brpc_record_list_write_d                                                                                                                                          
 7409 root      20   0 1090620 165112  46648 S   7.9  1.0   2400:54 ./name_agent                                                                                                                                                        
 8547 root      20   0 1955268 355496 272080 S   6.9  2.2  13985:33 ./bigolive_msg_gw_v3_d                                                                                                                                              
17153 root      20   0 1236532 389568 272184 S   6.9  2.4 886:39.54 ./live_brpc_gift_query --flagfile=../conf/gflags.conf                                                                                                               
25056 root      20   0 1272040 323940 266792 S   6.6  2.0   3562:06 ./brpc_virtual_currency_trade_platform_d                                                                                                                            
 6285 root      20   0 1256220 310632 267116 S   6.3  1.9   4930:07 ./brpc_virtual_currency_query_platform_d                                                                                                                            
17690 root      20   0 1265228 321196 266656 S   6.3  2.0   1890:27 ./brpc_virtual_currency_front_platform_d
```


### mpstat

查看CPU情况

`mpstat -P ALL 5`

```

Average:     CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
Average:     all   11.22    0.00    6.50    0.04    0.00    1.02    0.00    0.00    0.00   81.22
Average:       0   13.72    0.00    6.44    0.00    0.00    4.16    0.00    0.00    0.00   75.68
Average:       1   11.16    0.00    8.11    0.00    0.00    3.45    0.00    0.00    0.00   77.28
Average:       2    9.07    0.00    5.49    0.00    0.00    2.32    0.00    0.00    0.00   83.12
Average:       3   13.73    0.00    5.94    0.00    0.00    2.25    0.00    0.00    0.00   78.07
Average:       4   11.51    0.00    5.86    0.21    0.00    2.72    0.00    0.00    0.00   79.71
Average:       5    8.72    0.00    7.71    0.00    0.00    2.84    0.00    0.00    0.00   80.73
Average:       6   11.02    0.00    6.86    0.00    0.00    3.12    0.00    0.00    0.00   79.00
Average:       7   11.73    0.00    6.17    0.00    0.00    2.88    0.00    0.00    0.00   79.22
Average:       8   13.57    0.00    5.85    0.00    0.00    0.00    0.00    0.00    0.00   80.58
Average:       9   13.40    0.00    7.42    0.00    0.00    0.00    0.00    0.00    0.00   79.18
Average:      10   15.00    0.00    5.00    0.00    0.00    0.00    0.00    0.00    0.00   80.00
Average:      11   14.20    0.00    6.17    0.00    0.00    0.00    0.00    0.00    0.00   79.63
Average:      12   10.48    0.00    5.66    0.21    0.00    0.00    0.00    0.00    0.00   83.65
Average:      13   10.77    0.00    8.13    0.20    0.00    0.00    0.00    0.00    0.00   80.89
Average:      14    8.73    0.00    6.86    0.00    0.00    0.00    0.00    0.00    0.00   84.41
Average:      15    8.79    0.00    6.28    0.00    0.00    0.21    0.00    0.00    0.00   84.73
Average:      16    7.84    0.00    6.14    0.00    0.00    0.21    0.00    0.00    0.00   85.81
Average:      17   12.16    0.00    6.80    0.00    0.00    0.21    0.00    0.00    0.00   80.82
Average:      18    9.94    0.00    6.63    0.00    0.00    0.00    0.00    0.00    0.00   83.44
Average:      19    6.88    0.00    8.33    0.00    0.00    0.00    0.00    0.00    0.00   84.79
Average:      20    8.40    0.00    5.67    0.00    0.00    0.00    0.00    0.00    0.00   85.92
Average:      21   14.06    0.00    7.23    0.00    0.00    0.00    0.00    0.00    0.00   78.71
Average:      22    9.89    0.00    3.87    0.65    0.00    0.00    0.00    0.00    0.00   85.59
Average:      23   14.67    0.00    7.44    0.00    0.00    0.00    0.00    0.00    0.00   77.89
```

### pidstat

查看单个进程的情况

```bash
# 查看总体进程CPU指标，1s输出一次
pidstat -u 1
# 查看某个pid下进程CPU指标，1s输出一次
pidstat -u 1 -p 24946

12:27:22 PM   UID       PID    %usr %system  %guest    %CPU   CPU  Command
12:27:23 PM     0     24946   23.00    3.00    0.00   26.00     6  welog_vlive_rev
12:27:24 PM     0     24946   20.00    1.00    0.00   21.00    12  welog_vlive_rev
12:27:25 PM     0     24946   13.00    2.00    0.00   15.00     6  welog_vlive_rev
12:27:26 PM     0     24946   14.00    2.00    0.00   16.00    15  welog_vlive_rev
12:27:27 PM     0     24946   23.00    2.00    0.00   25.00     6  welog_vlive_rev
12:27:28 PM     0     24946   24    .00    0.00    0.00   24.00     6  welog_vlive_rev
12:27:29 PM     0     24946   12.00    1.00    0.00   13.00     5  welog_vlive_rev
12:27:30 PM     0     24946   18.00    3.00    0.00   21.00    19  welog_vlive_rev
```



### ksoftirqd内核线程和软中断次数

```bash
ps axu |grep ksoftirqd
root         3  0.1  0.0      0     0 ?        S    Jul01  11:33 [ksoftirqd/0]
root        17  0.0  0.0      0     0 ?        S    Jul01   7:57 [ksoftirqd/1]
root        24  0.0  0.0      0     0 ?        S    Jul01   6:38 [ksoftirqd/2]
root        30  0.0  0.0      0     0 ?        S    Jul01   8:05 [ksoftirqd/3]
root        36  0.0  0.0      0     0 ?        S    Jul01  11:28 [ksoftirqd/4]
root        42  0.0  0.0      0     0 ?        S    Jul01   7:37 [ksoftirqd/5]
root        48  0.0  0.0      0     0 ?        S    Jul01   9:00 [ksoftirqd/6]
root        54  0.0  0.0      0     0 ?        S    Jul01   7:31 [ksoftirqd/7]
root        60  0.0  0.0      0     0 ?        S    Jul01   4:06 [ksoftirqd/8]
root        66  0.0  0.0      0     0 ?        S    Jul01   4:13 [ksoftirqd/9]
root        72  0.0  0.0      0     0 ?        S    Jul01   3:43 [ksoftirqd/10]
root        78  0.0  0.0      0     0 ?        S    Jul01   3:48 [ksoftirqd/11]
root        84  0.0  0.0      0     0 ?        S    Jul01   3:59 [ksoftirqd/12]
root        90  0.0  0.0      0     0 ?        S    Jul01   4:06 [ksoftirqd/13]
root        96  0.0  0.0      0     0 ?        S    Jul01   4:08 [ksoftirqd/14]
root       102  0.0  0.0      0     0 ?        S    Jul01   4:10 [ksoftirqd/15]
root       108  0.0  0.0      0     0 ?        S    Jul01   4:10 [ksoftirqd/16]
root       114  0.0  0.0      0     0 ?        S    Jul01   4:10 [ksoftirqd/17]
root       120  0.0  0.0      0     0 ?        S    Jul01   4:13 [ksoftirqd/18]
root       126  0.0  0.0      0     0 ?        S    Jul01   4:10 [ksoftirqd/19]
root       132  0.0  0.0      0     0 ?        S    Jul01   4:19 [ksoftirqd/20]
root       138  0.0  0.0      0     0 ?        S    Jul01   4:14 [ksoftirqd/21]
root       144  0.0  0.0      0     0 ?        S    Jul01   3:34 [ksoftirqd/22]
root       150  0.0  0.0      0     0 ?        S    Jul01   3:28 [ksoftirqd/23]
```

查看软中断类型

这里打印了其中的2个核的数据，一般关注

- `NET_RX` ： 网络接收
- `NET_TX`： 网络发送
- `SCHED`：非自愿上下文切换

```bash
sudo watch -d cat /proc/softirqs
    CPU0 CPU1
HI: 23 0
TIMER: 103966864 102718609
NET_TX: 1155388 845354
NET_RX: 4168912032 2879097762
BLOCK: 3361469 4697095
IRQ_POLL: 0 0
TASKLET: 21706776 2191730
SCHED: 150110602 140183950
HRTIMER: 0 0
RCU: 159842480 209709537
```

### 硬中断

```bash
 sudo watch -d cat /proc/interrupts

            CPU0       CPU1
  0:     247701     250313   IO-APIC-edge      timer
  1:        501        567   IO-APIC-edge      i8042
  3:          1          1   IO-APIC-edge
  8:          1          0   IO-APIC-edge      rtc0
  9:        256        240   IO-APIC-fasteoi   acpi
 12:       1134       1149   IO-APIC-edge      i8042
 16:        629        554   IO-APIC-fasteoi   nvidia
 17:      21313      20869   IO-APIC-fasteoi   firewire_ohci, eth1
 18:          0          0   IO-APIC-fasteoi   mmc0
 19:      51822      50079   IO-APIC-fasteoi   ata_piix, ata_piix
 20:       5605       5255   IO-APIC-fasteoi   ehci_hcd:usb2, uhci_hcd:usb3, uhci_hcd:usb6
 21:          0          0   IO-APIC-fasteoi   uhci_hcd:usb4, uhci_hcd:usb7
 22:         33         33   IO-APIC-fasteoi   ehci_hcd:usb1, uhci_hcd:usb5, uhci_hcd:usb8
 45:        337        247   PCI-MSI-edge      eth0
 46:        441        447   PCI-MSI-edge      hda_intel
NMI:          0          0   Non-maskable interrupts
LOC:     169176     174899   Local timer interrupts
SPU:          0          0   Spurious interrupts
PMI:          0          0   Performance monitoring interrupts
PND:          0          0   Performance pending work
RES:      42289      40236   Rescheduling interrupts
CAL:        154       1076   Function call interrupts
TLB:       5838       5365   TLB shootdowns
TRM:          0          0   Thermal event interrupts
THR:          0          0   Threshold APIC interrupts
MCE:          0          0   Machine check exceptions
MCP:          5          5   Machine check polls
ERR:          1
MIS:          0
```


## 上下文切换

- 自愿上下问切换
- 非自愿上下文切换

### vmstat

查看系统的上下文切换次数

```bash
vmstat 1

procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
10  0      0 353276  78320 3922548    0    0   229   218    2    1 18 11 71  0  0
 7  0      0 339668  78348 3925860    0    0     0   440 224268 602168 14 12 75  0  0
 4  0      0 353336  78376 3928224    0    0     4 54352 235216 596429 11  9 80  0  0
```

### pidstat

- nvcswch： 非自愿上下文切换
- cswch：自愿上下文切换

```bash
pidstat -wt 1

Average:      UID      TGID       TID   cswch/s nvcswch/s  Command
Average:        0     24946         -    996.00      5.00  welog_vlive_rev
Average:        0         -     24946    996.00      5.00  |__welog_vlive_rev
Average:        0         -      9405     50.00      0.00  |__welog_vlive_rev
Average:        0         -      9406     46.00      0.00  |__welog_vlive_rev
Average:        0         -      9407     50.00      0.00  |__welog_vlive_rev
Average:        0         -      9408     53.00      1.00  |__welog_vlive_rev
Average:        0         -      9409     51.00      0.00  |__welog_vlive_rev
Average:        0         -      9410     55.00      0.00  |__welog_vlive_rev
Average:        0         -      9411     53.00      1.00  |__welog_vlive_rev
Average:        0         -      9412     62.00      0.00  |__welog_vlive_rev
Average:        0         -      9413     42.00      0.00  |__welog_vlive_rev
Average:        0         -      9414     53.00      0.00  |__welog_vlive_rev
Average:        0         -      9415     51.00      0.00  |__welog_vlive_rev
Average:        0         -      9416     38.00      0.00  |__welog_vlive_rev
Average:        0         -      9417     55.00      0.00  |__welog_vlive_rev
Average:        0         -      9418     48.00      0.00  |__welog_vlive_rev
Average:        0         -      9419     49.00      1.00  |__welog_vlive_rev
Average:        0         -      9420     52.00      1.00  |__welog_vlive_rev
Average:        0         -      9421     52.00      1.00  |__welog_vlive_rev
Average:        0         -      9422     46.00      1.00  |__welog_vlive_rev
Average:        0         -      9423     43.00      0.00  |__welog_vlive_rev
Average:        0         -      9424     57.00      0.00  |__welog_vlive_rev
Average:        0         -     10676     29.00      1.00  |__welog_vlive_rev
Average:        0         -     10677      1.00      0.00  |__welog_vlive_rev
Average:        0         -     10678      0.00      0.00  |__welog_vlive_rev
Average:        0         -     10679      0.00      0.00  |__welog_vlive_rev
```

### strace

追踪进程的系统调用

```bash
strace -fp 2123
```



## 平均负载

表示处于执行或者待执行状态的任务数，70%的核数以下负载都不高。一般1min、5min、15min有这三个统计数字，综合来看可以看出系统的负载正在升高还是降低。

### uptime

```bash
# 高亮变化的部分
watch -d uptime
```

### vmstat

```bash
vmstat 1

procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
10  0      0 353276  78320 3922548    0    0   229   218    2    1 18 11 71  0  0
```



## CPU缓存命中率

- `cachestat`提供了整个操作系统缓存的读写命中情况。
- `cachetop`提供了每个进程的缓存命中情况。


## 文件系统


### df -h
**存储空间容量、使用量和剩余空间**

```bash
df -h
Filesystem      Size  Used Avail Use% Mounted on
udev            7.7G     0  7.7G   0% /dev
tmpfs           1.6G  155M  1.4G  10% /run
/dev/sda1        29G  6.1G   21G  23% /
tmpfs           7.7G  128K  7.7G   1% /dev/shm
tmpfs           5.0M     0  5.0M   0% /run/lock
tmpfs           7.7G     0  7.7G   0% /sys/fs/cgroup
/dev/sda2       227M  103M  109M  49% /boot
/dev/sda5       232G  151G   69G  69% /data
cgmfs           100K     0  100K   0% /run/cgmanager/fs
tmpfs           1.6G     0  1.6G   0% /run/user/0
tmpfs           1.6G     0  1.6G   0% /run/user/1045
```


### df -i
**索引节点容量、使用量以及剩余量**

如果小文件特别多，需要关注一下

```bash
df -i

Filesystem       Inodes  IUsed    IFree IUse% Mounted on
udev            1997488    482  1997006    1% /dev
tmpfs           2002400    789  2001611    1% /run
/dev/sda1       1875968 521071  1354897   28% /
tmpfs           2002400     42  2002358    1% /dev/shm
tmpfs           2002400      4  2002396    1% /run/lock
tmpfs           2002400     18  2002382    1% /sys/fs/cgroup
/dev/sda2         60960    310    60650    1% /boot
/dev/sda5      15425536  22239 15403297    1% /data
cgmfs           2002400     14  2002386    1% /run/cgmanager/fs
tmpfs           2002400      4  2002396    1% /run/user/0
tmpfs           2002400      4  2002396    1% /run/user/1045
```

**缓存**

- 页缓存
- 具体文件系统（ext4的缓存）

```bash
cat /proc/meminfo | grep -E "SReclaimable|Cached"
Cached:           748316 kB
SwapCached:            0 kB
SReclaimable:     179508 kB
```

目录项缓存、索引节点缓存

```bash
sudo cat /proc/slabinfo | grep -E '^#|dentry|inode'
# name            <active_objs> <num_objs> <objsize> <objperslab> <pagesperslab> : tunables <limit> <batchcount> <sharedfactor> : slabdata <active_slabs> <num_slabs> <sharedavail>
mqueue_inode_cache     36     36    896   36    8 : tunables    0    0    0 : slabdata      1      1      0
fuse_inode             0      0    832   39    8 : tunables    0    0    0 : slabdata      0      0      0
ecryptfs_inode_cache      0      0   1024   32    8 : tunables    0    0    0 : slabdata      0      0      0
fat_inode_cache        0      0    728   45    8 : tunables    0    0    0 : slabdata      0      0      0
squashfs_inode_cache      0      0    704   46    8 : tunables    0    0    0 : slabdata      0      0      0
ext4_inode_cache   17028  20724   1080   30    8 : tunables    0    0    0 : slabdata    716    716      0
hugetlbfs_inode_cache    159    159    608   53    8 : tunables    0    0    0 : slabdata      3      3      0
sock_inode_cache   41570  71595    640   51    8 : tunables    0    0    0 : slabdata   1425   1425      0
shmem_inode_cache   7095   7869    696   47    8 : tunables    0    0    0 : slabdata    171    171      0
proc_inode_cache   43266  44362    648   50    8 : tunables    0    0    0 : slabdata   1021   1021      0
inode_cache        49880  51974    592   55    8 : tunables    0    0    0 : slabdata   1002   1002      0
dentry            142262 211260    192   42    2 : tunables    0    0    0 : slabdata   5030   5030      0
```

更好用的slabtop
```bash
Active / Total Objects (% used)    : 476197 / 504946 (94.3%)
 Active / Total Slabs (% used)      : 10389 / 10389 (100.0%)
 Active / Total Caches (% used)     : 80 / 121 (66.1%)
 Active / Total Size (% used)       : 140208.87K / 150044.70K (93.4%)
 Minimum / Average / Maximum Object : 0.01K / 0.30K / 12.00K

  OBJS ACTIVE  USE OBJ SIZE  SLABS OBJ/SLAB CACHE SIZE NAME
 88032  80074   0%    0.19K   2096       42     16768K dentry
 84360  82695   0%    0.13K   1406       60     11248K kernfs_node_cache
 65247  59521   0%    0.10K   1673       39      6692K buffer_head
 40078  38462   0%    1.07K   1382       29     44224K ext4_inode_cache
 32277  27715   0%    0.60K    609       53     19488K inode_cache
 21120  20885   0%    0.03K    165      128       660K kmalloc-32
 18944  18474   0%    0.50K    296       64      9472K kmalloc-512
 13568  13568 100%    0.02K     53      256       212K kmalloc-16
 12546  12546 100%    0.04K    123      102       492K ext4_extent_status
 12032  11000   0%    0.06K    188       64       752K kmalloc-64
  9728   9372   0%    0.06K    152       64       608K pid
  9216   9216 100%    0.01K     18      512        72K kmalloc-8
  9204   9204 100%    0.20K    236       39      1888K vm_area_struct
  8792   6680   0%    0.57K    157       56      5024K radix_tree_node
  8576   8089   0%    0.25K    134       64      2144K filp
  6440   6440 100%    0.07K    115       56       460K Acpi-Operand
  4968   4968 100%    0.09K    108       46       432K anon_vma
  4794   4794 100%    0.04K     47      102       188K Acpi-Namespace
  4620   4233   0%    0.09K    110       42       440K kmalloc-96
  4284   4284 100%    0.19K    102       42       816K kmalloc-192
  4042   3927   0%    0.67K     86       47      2752K proc_inode_cache
  4032   3027   0%    0.25K     63       64      1008K kmalloc-256
  3744   3744 100%    0.81K     96       39      3072K fuse_inode
  3570   3570 100%    0.05K     42       85       168K ftrace_event_fi
```



## 磁盘

-使用率
-IOPS
-吞吐量
-响应时间
-缓冲区

### iostat

```bash
iostat -d -x 1

Linux 4.9.70-040970-generic (bigo)      07/09/2020      _x86_64_        (32 CPU)

Device:         rrqm/s   wrqm/s     r/s     w/s    rkB/s    wkB/s avgrq-sz avgqu-sz   await r_await w_await  svctm  %util
sda               0.01     8.72   19.09   10.77  2072.94  3371.92   364.62     0.04    1.31    1.68    0.65   1.13   3.37

Device:         rrqm/s   wrqm/s     r/s     w/s    rkB/s    wkB/s avgrq-sz avgqu-sz   await r_await w_await  svctm  %util
sda               0.00    38.00    0.00    8.00     0.00   180.00    45.00     0.03    4.00    0.00    4.00   4.00   3.20

```

- %util  ，就是我们前面提到的磁盘 I/O 使用率；
- r/s+w/s  ，就是 IOPS；
- rkB/s+wkB/s ，就是吞吐量；
- r_await+w_await ，就是响应时间


### pidstat

```bash
sudo pidstat -d 1 -p 8576

05:40:59 PM   UID       PID   kB_rd/s   kB_wr/s kB_ccwr/s iodelay  Command
05:41:00 PM     0      8576      0.00   2444.00      0.00       0  globalagent_d
05:41:01 PM     0      8576      0.00   2436.00      0.00       0  globalagent_d
05:41:02 PM     0      8576      0.00   2248.00      0.00       0  globalagent_d
```

### lsof

```bash
sudo lsof -p 8576
COMMAND    PID USER   FD   TYPE             DEVICE   SIZE/OFF       NODE NAME
globalage 8576 root  cwd    DIR                8,1       4096          2 /
globalage 8576 root  rtd    DIR                8,1       4096          2 /
globalage 8576 root  txt    REG                8,5    2294914    3409270 /data/services/global_agent-0.0.7.6/bin/globalagent_d
globalage 8576 root  DEL    REG                0,5                262150 /SYSV2838bf26
globalage 8576 root  DEL    REG                0,5                 65538 /SYSV2838bf25
globalage 8576 root  mem    REG                8,1      14608     133275 /lib/x86_64-linux-gnu/libdl-2.23.so
globalage 8576 root  mem    REG                8,1    1868984     133273 /lib/x86_64-linux-gnu/libc-2.23.so
globalage 8576 root  mem    REG                8,1     138696     133272 /lib/x86_64-linux-gnu/libpthread-2.23.so
globalage 8576 root  mem    REG                8,1      89696     131263 /lib/x86_64-linux-gnu/libgcc_s.so.1
globalage 8576 root  mem    REG                8,1    1088952     131137 /lib/x86_64-linux-gnu/libm-2.23.so
globalage 8576 root  mem    REG                8,1    1566440    1707143 /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
globalage 8576 root  mem    REG                8,5      84936    3407879 /data/services/libs/libboost_thread-gcc44-mt-1_42.so.1.42.0
globalage 8576 root  mem    REG                8,1      31712     133291 /lib/x86_64-linux-gnu/librt-2.23.so
globalage 8576 root  mem    REG                8,1    2361856     131397 /lib/x86_64-linux-gnu/libcrypto.so.1.0.0
globalage 8576 root  mem    REG                8,1     428384     131398 /lib/x86_64-linux-gnu/libssl.so.1.0.0
globalage 8576 root  mem    REG                8,1     162632     133271 /lib/x86_64-linux-gnu/ld-2.23.so
globalage 8576 root    0u   CHR                1,3        0t0       1029 /dev/null
globalage 8576 root    1u   CHR                1,3        0t0       1029 /dev/null
globalage 8576 root    2u   CHR                1,3        0t0       1029 /dev/null
globalage 8576 root    3w   REG                8,5          5         15 /data/globalagent_lock.pid
globalage 8576 root    4w   REG                8,5          0    4980757 /data/bigo/log/globalagent_d/shmm_agent_2020_07_09-17.log
globalage 8576 root    5u   REG                8,5 1350162776    4981073 /data/bigo/log/welog_dbgw_d/welog_dbgw_d_2020_07_09-17.log
globalage 8576 root    6u   REG                8,5  149071855    4981195 /data/bigo/log/welog_share_server_brpc/welog_share_server_brpc_2020_07_09-17.log
globalage 8576 root    7u   REG                8,5  534215965    5111828 /data/bigo/log/welog_video_recom_discover_d/welog_video_recom_discover_d_2020_07_09-17.log
globalage 8576 root    8u   REG                8,5  780771152    4981196 /data/bigo/log/welog_notification_brpc/welog_notification_brpc_2020_07_09-17.log
globalage 8576 root    9u   REG                8,5  449048383    4981197 /data/bigo/log/welog_user_dbgw_d/welog_user_dbgw_d_2020_07_09-17.log
globalage 8576 root   10u   REG                8,5  483570969    4981198 /data/bigo/log/welog_video_reader/welog_video_reader_2020_07_09-17.log
globalage 8576 root   11u   REG                8,5  394847778    4981202 /data/bigo/log/welog_video_event_dbgw_d/welog_video_event_dbgw_d_2020_07_09-17.log
globalage 8576 root   12u   REG                8,5  154012009    4981203 /data/bigo/log/welog_roominfo_dbgw_d/welog_roominfo_dbgw_d_2020_07_09-17.log
globalage 8576 root   13u   REG                8,5   32328668    4981204 /data/bigo/log/welog_video_post_core_dbgw_d/welog_video_post_core_db
```


### strace


```bash
sudo strace -fp 8576
nanosleep({0, 2000000}, NULL)           = 0
write(14, "Jul  9 17:43:12 info welog_conta"..., 176) = 176
write(14, "Jul  9 17:43:12 info welog_conta"..., 176) = 176
write(19, "Jul  9 17:43:12 debug welog_vide"..., 123) = 123
write(7, "Jul  9 17:43:12 info welog_video"..., 164) = 164
write(5, "Jul  9 17:43:12 info welog_dbgw_"..., 323) = 323
write(5, "Jul  9 17:43:12 info welog_dbgw_"..., 93) = 93
write(12, "Jul  9 17:43:12 info welog_room_"..., 113) = 113
write(7, "Jul  9 17:43:12 info welog_video"..., 155) = 155
write(19, "Jul  9 17:43:12 info welog_video"..., 147) = 147
write(19, "Jul  9 17:43:12 info welog_video"..., 184) = 184
write(16, "Jul  9 17:43:12 info welog_frien"..., 162) = 162
write(16, "Jul  9 17:43:12 info welog_frien"..., 160) = 160
write(5, "Jul  9 17:43:12 info welog_dbgw_"..., 138) = 138
write(8, "I0709 17:43:12.132658  6118 3404"..., 203) = 203
write(11, "Jul  9 17:43:12 info welog_video"..., 158) = 158
write(11, "Jul  9 17:43:12 info welog_video"..., 169) = 169
write(8, "I0709 17:43:12.132716  6118 3404"..., 246) = 246
write(10, "Jul  9 17:43:12 info welog_video"..., 128) = 128
write(5, "Jul  9 17:43:12 info welog_dbgw_"..., 166) = 166
write(9, "Jul  9 17:43:12 info welog_user_"..., 192) = 192
write(5, "Jul  9 17:43:12 info welog_dbgw_"..., 122) = 122
write(16, "Jul  9 17:43:12 info welog_frien"..., 160) = 160
write(16, "Jul  9 17:43:12 info welog_frien"..., 160) = 160
write(7, "Jul  9 17:43:12 info welog_video"..., 100) = 100
write(26, "Jul  9 17:43:12 info welog_trans"..., 256) = 256
write(11, "Jul  9 17:43:12 info welog_video"..., 158) = 158
write(11, "Jul  9 17:43:12 info welog_video"..., 169) = 169
write(9, "Jul  9 17:43:12 info welog_user_"..., 213) = 213
```



## 系统内存指标

- 已用内存
- 剩余内存
- 可用内存
- 缺页异常
  - 主缺页异常
  - 次缺页异常
- 缓存/缓冲区
  - 使用量
  - 命中率
- Slabs


### free

查看系统内存情况
```bash
              total        used        free      shared  buff/cache   available
Mem:       32716480    28319700      294092     1153452     4102688     1940208
Swap:             0           0           0
```

buffer是磁盘数据的缓存，cache是文件数据缓存，还有slab那些。

### vmstat


```bash
vmstat 1
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
11  0      0 896784  97772 2821868    0    0    65   106    0    0 12  5 83  0  0
 9  1      0 853484  97772 2863376    0    0 33536     0 222933 168395 16  6 78  0  0

```


### sar -r


```bash
sar -r 1

04:35:41 PM kbmemfree kbmemused  %memused kbbuffers  kbcached  kbcommit   %commit  kbactive   kbinact   kbdirty
04:35:42 PM   1019204  15000000     93.64     97460   2000756  41099504    256.56  12884824    586204     38388
```

- kbcommit，表示当前系统负载需要的内存。它实际上是为了保证系统内存不溢出，对需要内存的估计值。%commit，就是这个值相对总内存的百分比。
- kbactive，表示活跃内存，也就是最近使用过的内存，一般不会被系统回收。
- kbinact, 表示不活跃内存，会被系统回收。



### sar -B

```bash
sar -B 1

05:08:42 PM  pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
05:08:43 PM      0.00      0.00   9707.00      0.00  20938.00      0.00      0.00    418.00      0.00
05:08:44 PM      0.00  62272.00  14407.00      0.00  23490.00      0.00      0.00    828.00      0.00
05:08:45 PM      0.00      0.00  90313.00      0.00  23462.00      0.00      0.00   1794.00      0.00
05:08:46 PM      0.00      0.00  32778.00      0.00  21673.00      0.00      0.00   1035.00      0.00
05:08:47 PM      0.00    276.00  22294.00      0.00  18126.00      0.00      0.00    828.00      0.00
05:08:48 PM    128.00      0.00  22439.00      1.00  23405.00      0.00      0.00   1244.00      0.00
05:08:49 PM      0.00    188.00  40103.00      0.00  19534.00      0.00      0.00    690.00      0.00
05:08:50 PM      0.00      0.00  11260.00      0.00  19395.00      0.00      0.00    834.00      0.00
05:08:51 PM      0.00      0.00  18353.00      0.00  24299.00      0.00      0.00   1848.00      0.00
05:08:52 PM      0.00    164.00   9144.00      0.00  25836.00      0.00      0.00   2380.00      0.00
05:08:53 PM      0.00      0.00  14347.00      0.00  22068.00      0.00      0.00    752.00      0.00
05:08:54 PM      0.00      0.00  15151.00      0.00  24216.00      0.00      0.00   2176.00      0.00
05:08:55 PM      0.00    160.00  28088.00      0.00  23353.00      0.00      0.00    952.00      0.00
05:08:56 PM      0.00      0.00  17477.00      0.00  30739.00      0.00      0.00    885.00      0.00
05:08:57 PM      0.00      0.00  11155.00      0.00  23145.00      0.00      0.00   1148.00      0.00
05:08:58 PM      0.00    164.00  14153.00      0.00  29748.00      0.00      0.00   1878.00      0.00

-B     Report paging statistics.  The following values are displayed:

  pgpgin/s
         Total number of kilobytes the system paged in from disk per second.

  pgpgout/s
         Total number of kilobytes the system paged out to disk per second.

  fault/s
         Number of page faults (major + minor) made by the system per second.  This is not a count of page faults that generate I/O, because some page faults can be resolved without I/O.

  majflt/s
         Number of major faults the system has made per second, those which have required loading a memory page from disk.

  pgfree/s
         Number of pages placed on the free list by the system per second.

  pgscank/s
         Number of pages scanned by the kswapd daemon per second.

  pgscand/s
         Number of pages scanned directly per second.

  pgsteal/s
         Number of pages the system has reclaimed from cache (pagecache and swapcache) per second to satisfy its memory demands.

  %vmeff
         Calculated as pgsteal / pgscan, this is a metric of the efficiency of page reclaim. If it is near 100% then almost every page coming off the tail of the inactive list is being  reaped.
         If it gets too low (e.g. less than 30%) then the virtual memory is having some difficulty.  This field is displayed as zero if no pages have been scanned during the interval of time.
```

## 进程内存指标

- 虚拟内存(VSS)
- 常驻内存(RSS)
- 按比例分配共享内存后的物理内存(PSS)
- 独占内存(USS)
- SWAP内存
- 缺页异常
  - 主缺页异常
  - 次缺页异常

### top


```bash
op - 16:53:00 up 632 days, 20:07,  1 user,  load average: 9.28, 7.78, 7.21                                                                                                           [1/1871]
Tasks: 533 total,   5 running, 528 sleeping,   0 stopped,   0 zombie
%Cpu(s): 16.4 us,  6.4 sy,  0.0 ni, 75.0 id,  0.1 wa,  0.0 hi,  2.1 si,  0.0 st
KiB Mem : 16019204 total,   338776 free, 12208344 used,  3472084 buff/cache
KiB Swap:        0 total,        0 free,        0 used.  2196036 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
22777 root      20   0  152068  49272   4480 R 100.0  0.3 318978:43 ./welog_time_proxy_d
17829 root      20   0 8803604 4.179g 277420 S  81.8 27.4   1033:35 ./welog_dbgw_d ../conf/live.xml
 6111 root      20   0 2456220 978.2m 274240 S  55.3  6.3   1389:26 ./welog_notification_brpc
27948 root      20   0  548464 334096 275956 S  45.4  2.1  23:51.54 ./welog_video_post_core_dbgw_d ../conf/server.conf
16241 root      20   0  698224 338952 268588 S  43.0  2.1   1813:00 ./welog_video_post_dbgw_d ../conf/server.conf
```


## SWAP

- 已用空间
- 剩余空间
- 换入速度
- 换出速度



## 网络层

考虑网络包数PPS

### ip -s
```bash
ip -s addr show dev eth0
2: eth0: <BROADCAST,MULTICAST,SLAVE,UP,LOWER_UP> mtu 1500 qdisc mq master wlan state UP group default qlen 1000
    link/ether 34:0a:98:82:4a:f7 brd ff:ff:ff:ff:ff:ff
    RX: bytes  packets  errors  dropped overrun mcast
    492680960278938 1780063434170 0       0       0       31857439
    TX: bytes  packets  errors  dropped carrier collsns
    320261618066962 1765882547781 0       0       0       0

```

- LOWER_UP： 连通
- mtu: 1500
- errors、dropped、overrun


### ping -c3 xxx
延迟和连通性
```bash
ping -c3 bigo.com
PING bigo.com (107.180.77.95) 56(84) bytes of data.
64 bytes from ip-107-180-77-95.ip.secureserver.net (107.180.77.95): icmp_seq=1 ttl=111 time=221 ms
64 bytes from ip-107-180-77-95.ip.secureserver.net (107.180.77.95): icmp_seq=2 ttl=111 time=221 ms
64 bytes from ip-107-180-77-95.ip.secureserver.net (107.180.77.95): icmp_seq=3 ttl=111 time=221 ms

--- bigo.com ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2002ms
rtt min/avg/max/mdev = 221.838/221.869/221.896/0.385 ms

```

## 传输层

BPS、吞吐量、连接数、延迟


### ss -s

可以查看timewait和半连接数

```bash
ss -s
Total: 31736 (kernel 0)
TCP:   30683 (estab 29754, closed 779, orphaned 0, synrecv 0, timewait 735/0), ports 0

Transport Total     IP        IPv6
*         0         -         -
RAW       1         1         0
UDP       4         3         1
TCP       29904     29085     819
INET      29909     29089     820
FRAG      0         0         0

````

### ss -lntp
查看半连接队列

```bash
ss -ltnp
State       Recv-Q Send-Q        Local Address:Port                                                                           Peer Address:Port
LISTEN      0      1024                  *:12334                                                                                     *:*
LISTEN      0      1024                  *:30001                                                                                     *:*
LISTEN      0      128                   *:5587                                                                                      *:*
LISTEN      0      128                   *:18868                                                                                     *:*
LISTEN      0      128                   *:15028                                                                                     *:*
```

### sar -n DEV 1

查看网络收发状况
```bash## 网络层

考虑网络包数PPS

### ip -s
```bash
ip -s addr show dev eth0
2: eth0: <BROADCAST,MULTICAST,SLAVE,UP,LOWER_UP> mtu 1500 qdisc mq master wlan state UP group default qlen 1000
    link/ether 34:0a:98:82:4a:f7 brd ff:ff:ff:ff:ff:ff
    RX: bytes  packets  errors  dropped overrun mcast
    492680960278938 1780063434170 0       0       0       31857439
    TX: bytes  packets  errors  dropped carrier collsns
    320261618066962 1765882547781 0       0       0       0

```

- LOWER_UP： 连通
- mtu: 1500
- errors、dropped、overrun


### ping -c3 xxx
延迟和连通性
```bash
ping -c3 bigo.com
PING bigo.com (107.180.77.95) 56(84) bytes of data.
64 bytes from ip-107-180-77-95.ip.secureserver.net (107.180.77.95): icmp_seq=1 ttl=111 time=221 ms
64 bytes from ip-107-180-77-95.ip.secureserver.net (107.180.77.95): icmp_seq=2 ttl=111 time=221 ms
64 bytes from ip-107-180-77-95.ip.secureserver.net (107.180.77.95): icmp_seq=3 ttl=111 time=221 ms

--- bigo.com ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2002ms
rtt min/avg/max/mdev = 221.838/221.869/221.896/0.385 ms

```

## 传输层

BPS、吞吐量、连接数、延迟


### ss -s

可以查看timewait和半连接数

```bash
ss -s
Total: 31736 (kernel 0)
TCP:   30683 (estab 29754, closed 779, orphaned 0, synrecv 0, timewait 735/0), ports 0

Transport Total     IP        IPv6
*         0         -         -
RAW       1         1         0
UDP       4         3         1
TCP       29904     29085     819
INET      29909     29089     820
FRAG      0         0         0

````

### ss -lntp
查看半连接队列

```bash
ss -ltnp
State       Recv-Q Send-Q        Local Address:Port                                                                           Peer Address:Port
LISTEN      0      1024                  *:12334                                                                                     *:*
LISTEN      0      1024                  *:30001                                                                                     *:*
LISTEN      0      128                   *:5587                                                                                      *:*
LISTEN      0      128                   *:18868                                                                                     *:*
LISTEN      0      128                   *:15028                                                                                     *:*
```

### sar -n DEV 1

查看网络收发状况
```bash
sar -n DEV 1
Average:        IFACE   rxpck/s   txpck/s    rxkB/s    txkB/s   rxcmp/s   txcmp/s  rxmcst/s   %ifutil
Average:        bond0      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
Average:         wlan  75835.00  76530.00  16778.49  13390.33      0.00      0.00     11.00      6.87
Average:           lo  12290.00  12290.00  10299.47  10299.47      0.00      0.00      0.00      0.00
Average:         eth1  41184.00  38281.00   7728.74   6723.80      0.00      0.00      9.00      6.33
Average:         eth3      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
Average:         eth2      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
Average:         eth0  34613.00  38232.00   9021.92   6664.97      0.00      0.00      2.00      7.39
Average:          lan      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
```

sar -n DEV 1
Average:        IFACE   rxpck/s   txpck/s    rxkB/s    txkB/s   rxcmp/s   txcmp/s  rxmcst/s   %ifutil
Average:        bond0      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
Average:         wlan  75835.00  76530.00  16778.49  13390.33      0.00      0.00     11.00      6.87
Average:           lo  12290.00  12290.00  10299.47  10299.47      0.00      0.00      0.00      0.00
Average:         eth1  41184.00  38281.00   7728.74   6723.80      0.00      0.00      9.00      6.33
Average:         eth3      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
Average:         eth2      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
Average:         eth0  34613.00  38232.00   9021.92   6664.97      0.00      0.00      2.00      7.39
Average:          lan      0.00      0.00      0.00      0.00      0.00      0.00      0.00      0.00
```
