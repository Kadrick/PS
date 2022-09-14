/**
 * @file 14494.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief DP
 * @version 0.1
 * @date 2022-04-07 10:23
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
var n, m int
var dp [][]int
var MOD = int(1e9 + 7)
var dx = []int{0, -1, -1}
var dy = []int{-1, -1, 0}

func solve(x, y int) int {
	if x == 1 && y == 1 {
		return 1
	}

	if dp[x][y] != -1 {
		return dp[x][y]
	}

	sum := 0
	for i := 0; i < 3; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if 1 <= nx && 1 <= ny {
			sum += solve(nx, ny)
			sum %= MOD
		}
	}

	dp[x][y] = sum
	return sum
}

func main() {
	in = bufio.NewReader(os.Stdin)

	fmt.Fscan(in, &n, &m)

	dp = make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			dp[i][j] = -1
		}
	}

	var buf bytes.Buffer
	buf.Write([]byte(strconv.Itoa(solve(n, m))))
	buf.WriteByte('\n')
	fmt.Print(buf.String())

	return
}
