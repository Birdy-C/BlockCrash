# BlockCrash

## Introduction

这个软件是针对方块消消消开发的一个简单的AI。

方块消消消是一个AI小程序。

操作方法：用户单击方块，在上方会显示摆放位置。

视频地址1： <https://www.bilibili.com/video/av54230862/>

视频地址2： https://youtu.be/WkcEchs5uzc



原游戏界面：

![方块消消消](https://img-blog.csdn.net/20180415203842366?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2JpcmR5Xw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)



## Code

![色块](https://img-blog.csdn.net/20180415205423448?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2JpcmR5Xw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

### Project BlockCrash

命令行操作，输入数字，其中输入0撤销。



### Project BlockCrash_autotest

用随机数进行测试，输出平均得分。



### Project BlockCrash_GUI

在之前的基础上加入了Qt界面。

release v1.0下为该项目导出文件。



### class Board

棋盘相关的操作，包括评分、加入操作等。



### class BlockGenerate

根据输入的数字返回对应的方块，或者返回随机方块。