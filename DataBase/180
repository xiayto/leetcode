# Write your MySQL query statement below
SELECT t1.Num as ConsecutiveNums
FROM logs AS t1, logs AS t2, logs AS t3
WHERE t1.Id = t2.Id-1 and t2.Id = t3.Id-1 and t1.Num = t2.Num and t2.Num = t3.Num
GROUP BY t1.Num
