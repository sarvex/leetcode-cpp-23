### 940.Distinct-Subsequences-II

#### 解法1：(deprecated)

此题是字符串序列的一道经典题。如果第一次做的话，可能会觉得有难度。

尝试构造状态dp[i]，表示截止第i个字符为止，我们能够创建的distinct子序列有多少．对于这个dp[i]的定义，我们并不要求s[i]必须是子序列的一部分。

接下来，对于第i个字符ch，我们尝试思考它如何参与到已有子序列dp[i-1]的构建来．

情况I:如果它不参与到子序列的构建，那么dp[i-1]有多少子序列，dp[i]一定会保留全部的这些，所以```dp[i]+=dp[i-1]```。举个例子，如果对于dp[i-1]已经有了如下的不同子序列
```
XXXX   (1)
XXX    (2) 
XXX    (3)
XX     (4)
```
那么对于dp[i]而言，以上这些字符串仍然是其一部分。

情况II:如果它参与到子序列的构建，那么dp[i-1]有多少子序列（包括空序列），末位加上S[i]之后，就能生成同样数目的新子序列．所以继续有```dp[i]+=dp[i-1]```．假设s[i]=='a'，那么我们就可以构造出新的子序列（接上面的例子）
```
XXXXa (5)
XXXa  (6)
XXXa  (7)
XXa   (8)
```
所以综合一下，```dp[i]=dp[i-1]*2```  (*)

但是我们显然要处理一种重复的情况，比如说(1)和(6)会不会重复？出现重复的原因在于，如果(1)中的最后一个字符也是'a'，当(1)中的前三个字符和(6)中的前三个字符的来源相同时，这些序列的数目就在```(*)```式里面被重复计算了两遍。

如何去掉这个重复呢？对于(1)而言，我们需要定位第四个字符'a'的位置j。这个j是i之前最后一次出现字符'a'的index。我们可以验证，dp[j-1]所对应子序列xxx，加上s[j]，可以得到"xxxa"的形式；同时dp[j-1]所对应子序列xxx，加上s[i]，也可以得到"xxxa"的形式。这两部分的子序列是完全相同的，是被```(*)```式所重复计算的，所以我们需要减去。

所以综上，dp[i]的更新式子是:```dp[i] = dp[i-1]*2-dp[j-1]```其中```j```就是i前面最后一个满足```S[j]==S[i]```的index。

在实际操作中，我们将S改写成1-index的形式。那么初始状态dp[0]表示的是“空集”所对应的子序列，我们令dp[0]=1代表“空字串”，并参与到后续dp的更新中去。举个例子s="#aba"，当我们查看i=3时，j指向了0，故```dp[3] = dp[2]*2-dp[0]```，这个减法其实就是消去了“空集+a”这样的字符串，而这个字符串在dp[1]中就已经被计算了。

最终的输出是dp[n]。但是这个数字包含了“空字串”，所以答案需要再减去1.

##### 补充
有一个听众问我，为什么去重的操作里，只需要减去dp[j-1]（j是上一个满足S[j]==S[i]的字符的index），而不减去其他的dp[k-1]（k是在j更早之前的某些字符，也满足S[k]==S[i])。这个问题很深刻。

我举个例子：...XXX... (a1) ...YYY... (a2) ...ZZZ... (a3), 其中a1,a2,a3都代表相同的字符a，他们对应的index分别是k,j,i. XXX/YYY/ZZZ表示在各自区间内取的某个subsequence.

我们在计算dp[i]的时候，减去了dp[j-1]，这是因为这两部分是重复的：
```
XXXYYY(a2)
XXXYYY(a3)
```
而我们为什么没有考虑下面这两部分的重复呢？
```
XXX(a1)
XXX(a3)
```
这是因为```XXX(a1)```本质是和```XXXYYY(a2)```重合的！就最终的subsequence的样子而言，前者就是后者的一部分。我们计算dp[i]时，减去的dp[j-1]，去掉了形如```XXXYYY(a2)```的重复，其实也就已经去掉了形如```XXX(a1)```的重复。所以我们不需要考虑其他在j之前的任何S[k]==S[i]的case。

#### 解法2：(preferred)
此题和`1987.Number-of-Unique-Good-Subsequences`几乎一样。

我们令dp[c]表示截止到目前，以字母c结尾的unique subsequence的数目。

核心的代码是：
```cpp
    for (int i=0; i<n; i++)
    {       
        char c = s[i];
        dp[c] = sum(dp) + 1;
    }
```
从字面上看，计算得到的dp[c]是以s[i]为结尾的unqiue subsequence，看上去和我们对于dp的定义并不一致。但事实上，“以字母c结尾的unique subsequence的数目”，必然等同于“以s[i]为结尾的unique subsequence的数目”。前者的任意一个序列都可以把最终的c安排在s[i]，而后者任意一个序列也必然是属于前者。故两者是一一对应关系。

最终的答案就是`sum{dp[c]}, over c='a','b',...`


[Leetcode Link](https://leetcode.com/problems/distinct-subsequences-ii)