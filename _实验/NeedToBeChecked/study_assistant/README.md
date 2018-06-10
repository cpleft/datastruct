# About study_assistant #
* * *

## PreCoding ##

**What you want to implement:**
> 英文小说存于一个文本文件中(有多行),需要统计的单词由键盘输入。
> 程序运行结束后输出该关键字在文中出现的总次数以及出现该关键字的行号和在该行中出现的次数。

**So we need:**
>+ A English novel text stored in a "Novel.txt" file.
>+ Input one word which needs to be checked.
>+ Each time read one line into RAM, and find that whether the line has the word. if it has, record this line and find how many that kind of words this line has; if doesn't, do nothing.
>+ In the end, report these: How many the kind of words the whole novel has?  Which line has the words and how many the kind of words this line has?

## Structure ##
**There are 4 files in this fold:**
>+ README.md
>+ Study_assistant.cpp
>+ Novel.txt
>+ a.out

#### README.md ####
Overview about this fold

#### Study_assistant.cpp ####
This file should implement following things:
>+ 让用户输入要查找的单词
>+ 打开文件"Novel.text"，逐行读取文本，用KMP算法进行匹配，然后得到相应的结果。
So there are  functions :
>+ KMP
>+ NextArray
>+ main : About read file by line and deal with the values. 

#### Novel.txt ####
Store a novel in the file. 

#### a.out ####
executable file.


