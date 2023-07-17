### 781.Rabbits-in-Forest

如果answers里面含有元素m，那么我们最多允许它出现m+1次，使得这m+1个汇报的兔子是属于共同颜色的。如果出现了第m+2只兔子同样汇报了m，那么它只能是另外一种颜色，即必然另外m+1只兔子属于另一个颜色圈。

更一般的，如果有n只兔子都汇报了m，那么“颜色圈”的数量最少是```k = (n-1) / (m+1) + 1```。那么对应有```(m+1)*k```只兔子。