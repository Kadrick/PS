/**
 * @file 14595.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief disjoint set
 * @version 0.1
 * @date 2022-04-07 17:50
 *
 * @copyright Copyright (c) 2021
 *
 */
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

const inf int = math.MaxInt32

//////////////////////////////////////////////////////////////

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

//////////////////////////////////////////////////////////////

var scanner = bufio.NewScanner(os.Stdin)
var print = bufio.NewWriter(os.Stdout)

func nextInt() int {
	scanner.Scan()
	text := scanner.Text()
	v, _ := strconv.Atoi(text)
	return v
}

//////////////////////////////////////////////////////////////

var parent, chk []int

type Pair struct {
	left, right int
}

func find(root int) int {
	if root == parent[root] {
		return root
	}
	parent[root] = find(parent[root])
	return parent[root]
}

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	n, m := nextInt(), nextInt()
	parent = make([]int, n+1)
	chk = make([]int, n+1)

	for i := 0; i <= n; i++ {
		parent[i] = i
	}

	ans := 0
	input := make([]Pair, 0)

	for i := 0; i < m; i++ {
		x, y := nextInt(), nextInt()
		input = append(input, Pair{left: x, right: y})
	}

	sort.Slice(input, func(i, j int) bool {
		return input[i].left < input[j].left
	})

	start, right := 0, 0

	for i := 0; i < len(input); i++ {
		start = input[i].left

		if start < right {
			start = right
		}

		root := find(start)

		for j := start; j <= input[i].right; j++ {
			parent[j] = root
		}

		right = input[i].right
	}

	for i := 1; i <= n; i++ {
		if chk[parent[i]] == 0 {
			chk[parent[i]] = 1
			ans++
		}
	}

	fmt.Fprintln(print, ans)

	return
}
