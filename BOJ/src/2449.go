/**
* @file 2449.go
* @author kadrick (kbk2581553@gmail.com)
* @brief DP
* @version 0.1
* @date 2022-04-05
*
* @copyright Copyright (c) 2022
*
 */
package main

import "fmt"

var n, k int
var color []int
var dp [][]int

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func solve(left, right int) int {
	if left >= right {
		return 0
	}

	if dp[left][right] != -1 {
		return dp[left][right]
	}

	ans := 987654321
	for i := left; i < right; i++ {
		lv := solve(left, i)
		rv := solve(i+1, right)
		changeColor := 0
		if color[left] != color[i+1] {
			changeColor = 1
		}
		sum := lv + rv + changeColor

		ans = min(ans, sum)
	}

	dp[left][right] = ans
	return ans
}

func main() {
	fmt.Scan(&n, &k)
	color = make([]int, n)
	dp = make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = -1
		}
	}

	for i := 0; i < n; i++ {
		fmt.Scan(&color[i])
	}

	fmt.Println(solve(0, n-1))

	return
}
