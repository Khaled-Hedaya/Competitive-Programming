/*
For a given array with  n  numbers  a[0...n - 1]  we have to colorize the numbers in the smallest number of colors, so that each color forms a non-increasing subsequence. (decreasing with equal values)

To solve this, we notice that the minimum number of required colors is equal to the length of the longest increasing subsequence.

Proof: We need to prove the duality of these two problems.

Let's denote by 'x' the length of the longest increasing subsequence and by  'y' the least number of non-increasing subsequences that form a cover. We need to prove that  x = y .

It is clear that  y < x is not possible, because if we have  x strictly increasing elements, then no two elements can be part of the same non-increasing subsequence. Therefore we have  y >= x .

We will now show that  y > x$ is not possible by contradiction. Suppose that  y > x . Then we consider any optimal set of  y  non-increasing subsequences. We transform this in set in the following way: as long as there are two such subsequences such that the first begins before the second subsequence,
and the first sequence start with a number greater than or equal to the second, then we unhook this starting number and attach it to the beginning of second. After a finite number of steps we have  y subsequences,
and their starting numbers will form an increasing subsequence of length  y . Since we assumed that  y > x  we reached a contradiction.

Thus it follows that  y = x .... :))

Ex:
n = 11
(4) 2 (5) (6) 10 1 (7) 6 12 (8) (9)
 0  0  1   2   3 0  3  2  4  4   5 
len of LIS = number of minimum colors = 6
*/

