### 1884.Egg-Drop-With-2-Eggs-and-N-Floors

此题是```887.Super-Egg-Drop```的简化版本。

对于i层楼，如果只有一个鸡蛋，我们需要测几次呢？显然只能一层一层，从第1层开始尝试，最多可能一直到到第i层都不碎（注意题目允许在最高层都不碎）。所以需要n次测试，我们记做```dp[i][1]=i```.

现在我们有两个鸡蛋。我们遍历第一个鸡蛋放在哪里。假设放在第j层，如果碎了，那么说明我们需要用剩下的一颗鸡蛋来确定极限层（恰好不破）在下方的j-1层的哪里，即dp[j-1][1]. 如果没有碎，说明极限层在第j层到第n层之间。此时我们可以把第j层看做相当于第0层（因为肯定不会破），所以我们需要的是在剩下的i-j层里面用两颗鸡蛋来确定极限层，即dp[i-j][2]. 考虑最坏情况，取```max{dp[j-1][1], dp[i-j][2]}```

注意，我们在遍历第一个鸡蛋的位置j时，最终选择的是最优解，即```dp[i][2] = min{max{dp[j-1][1], dp[i-j][2]}} for j=1,2,..,i```.