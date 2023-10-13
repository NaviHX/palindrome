# 判断回文串

根据栈的FILO,队列的FIFO特性,可以将字符串分别压入栈和队列再逐个取出,判断出栈和出队的序列是否相等

## 调试报告

内存泄漏

```c++
 void queueFree(queue *q)
 {
     node *temp = q->head;
     node *pre;
     while (temp != NULL)
     {
         pre = temp;
         temp = temp->nxt;
         free(pre);
     }
+    free(q);
 }
```

没有释放队列结构的空间

## 查找回文子串算法

[Manacher Algorithm](https://refrigerator.navihx.top/posts/longest-palindrome/), 相对于朴素算法更优的算法, 利用已经计算出的回文半径.
