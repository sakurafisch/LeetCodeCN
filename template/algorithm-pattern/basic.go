package algorithm_pattern

import (
	"fmt"
	"sort"
	"strconv"
)

// 栈
func stack_pattern() {
	// 创建栈
	stack := make([]int, 0)
	// push 压入
	stack = append(stack, 10)
	// pop 弹出
	_ = stack[len(stack)-1]
	stack = stack[:len(stack)-1]
	// 检查栈空
	if len(stack) == 0 {
		fmt.Println("Stack is empty")
	}
}

// 队列
func queue_pattern() {
	// 创建队列
	queue := make([]int, 0)
	// enqueue 入队
	queue = append(queue, 10)
	// dequeue 出队
	_ = queue[0]
	queue = queue[1:]
	// 检查队空
	if len(queue) == 0 {
		fmt.Println("Queue is empty")
	}
}

func map_pattern() {
	// 创建
	m := make(map[string]int)
	// 设置 kv
	m["hello"] = 1
	// 删除 k
	delete(m, "hello")
	for k, v := range m {
		println(k, v)
	}
}

func std_pattern() {
	// 整数排序
	sort.Ints([]int{})
	// 字符串排序
	sort.Strings([]string{})
	// 自定义排序
	s := []int{}[:]
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
}

func type_convert_pattern() {
	// byte 转数字
	s := "12345"
	num := int(s[0] - '0')
	str := string(s[0])
	b := byte(num + '0')
	fmt.Printf("%d%s%c\n", num, str, b)

	// 字符串转数字
	num, _ = strconv.Atoi(s)

	// 数字转字符串
	str = strconv.Itoa(num)
}
