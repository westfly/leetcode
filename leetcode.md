leetcode


**two sum**

```
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```
题目的意思是在一个数组中，找出两个和为特定值的索引号。
最暴力的方法，是假定一个值，然后再在数组中搜索另外一个值。假设数组长度为n，复杂度为O(n^2).

```cpp
for(i = 0; i < array_size; ++i) {
 for(j = i+1; j < array_size; ++j) {
    if (array[i] + array[j] == target) {
        return (i,j);
    }
}
```
如果是有序的数组，通过首尾指针法，是很容易找到的，但是并没有说是有序的数组，这种方法，会破坏原数组的索引，还需要从原数组中反向搜索其索引，时间复杂度为O(n)，加上排序的复杂度，总的复杂度为O(nlogn).
考虑到，其实是一个固定一个元素，在数组中搜索另外一个元素的思路，我们能否通过某种方式来减少搜索的复杂度？这里选取hashmap的方式。具体如下
```cpp
for (int i = 0; i < n; ++i)
{
  element = array[i];
  if(hashmap.find(element) == hashmap.end())
  {
    // save with 2nd key
    hashmap[target - element] = i + 1;
    continue;
  }
  return (hash_map[element], i + 1);
}
```
## Add Two Numbers
```
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
```
链表的归并算法，简单题，主要是主要通过有头节点，能够简化代码的实现。

```
```
## Longest Substring Without Repeating Characters

```
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
```
[xxx](http://blog.csdn.net/likecool21/article/details/10858799)
** Median of Two Sorted Arrays ** 

[Median of Two Sorted Arrays](https://oj.leetcode.com/problems/median-of-two-sorted-arrays/)

```
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
```

这道题是某年Yahoo的笔试题目。

暴力解法是将A和B数组，组成C数组，然后直接取C[(m+n)/2]，空间复杂度为O(n+m)，
归并的时间复杂度为O(m+n)。
可以将题目转换一下，在一个m

