/**
 * @file 10942.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-04-06 17:14
 *
 * @copyright Copyright (c) 2021
 *
 */
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"strconv"
)

var in *bufio.Reader
var n, m, s, e int
var arr []int
var dp [][]int

func solve(start, end int) int {
	if start == end {
		return 1
	}

	if start+1 == end {
		if arr[start] == arr[end] {
			return 1
		}
		return 0
	}

	if dp[start][end] == -1 {
		ret := solve(start+1, end-1)

		if arr[start] == arr[end] {
			dp[start][end] = ret
		} else {
			dp[start][end] = 0
		}
	}

	return dp[start][end]
}

func main() {
	in = bufio.NewReader(os.Stdin)

	fmt.Fscan(in, &n)

	arr = make([]int, n)
	dp = make([][]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i])

		dp[i] = make([]int, n)
		for j := 0; j < n; j++ {
			dp[i][j] = -1
		}
	}

	fmt.Fscan(in, &m)

	var buf bytes.Buffer
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &s, &e)
		buf.Write([]byte(strconv.Itoa(solve(s-1, e-1))))
		buf.WriteByte('\n')
	}

	fmt.Print(buf.String())

	return
}
