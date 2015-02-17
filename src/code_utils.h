/*
 * code_utils.h
 *
 *  Created on: 2015
 *      Author: Ares Rayan (yweiyun@gmail.com)
 */

#ifndef CODE_UTILS_H_
#define CODE_UTILS_H_
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
template<typename T>
void print_array(const T array[], size_t n)
{

}


template<int>
void print_array(const int array[], size_t n)
{
	while(n>0) {
		printf("%d\t",array[--n]);
	}
	putchar('\n');

}
/** 生成随机的n个数 */
void generate_array(int a[],int n);
/** 生成无头节点单链表*/
ListNode* create_slist(int n);
ListNode* create_slist(int a[],int n);
void destroy_slist(ListNode* h);
void print_slist(ListNode* h);
size_t length_slist(ListNode* h);
ListNode* reverse_slist(ListNode* head);
/**获取单链表的中间节点*/
ListNode* get_middle_slist(ListNode* h);
// 将两个有序的单链表合并(升序)
ListNode* merge_list(ListNode* h1, ListNode* h2);

/** 生成无头节点循环单链表*/
ListNode* create_sclist(int n);
ListNode* create_sclist(int a[],int n);
void destroy_sclist(ListNode* h);
void print_sclist(ListNode* h);

inline ListNode* alloc_list_node(int n)
{
	return new ListNode(n);
}
inline void dealloc_list_node(ListNode* node)
{
	delete node;
}
/** 内部函数*/
ListNode* create_list(int n, int list_type);
ListNode* create_list(int a[],int n, int list_type);
void destroy_list(ListNode* h, ListNode* end);
void print_list(ListNode* h, ListNode* end);
ListNode* get_middle_list(ListNode* h, ListNode* end);
size_t length_list(ListNode* h, ListNode* end);
#define ARRAY_SIZE_UNSAFE(a) \
		 sizeof(a)/sizeof(a[0])

#endif /* CODE_UTILS_H_ */
