# 调试分析报告

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
