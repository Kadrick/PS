/**
 * @file 2800.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief stack
 * @version 0.1
 * @date 2022-04-08 14:09
 *
 * @copyright Copyright (c) 2022
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

var (
	scanner = bufio.NewScanner(os.Stdin)
	stdout  = bufio.NewWriter(os.Stdout)
)

func nextInt() int {
	scanner.Scan()
	text := scanner.Text()
	v, _ := strconv.Atoi(text)
	return v
}

func nextString() string {
	scanner.Scan()
	text := scanner.Text()
	return text
}

//////////////////////////////////////////////////////////////

type Pair struct {
	lPos int
	rPos int
}

func unique(arr []string) []string {
	keys := make(map[string]bool)
	list := []string{}
	for _, entry := range arr {
		if _, value := keys[entry]; !value {
			keys[entry] = true
			list = append(list, entry)
		}
	}
	return list
}

func bytesToStrWithTrim(arr []byte) string {
	retBytes := make([]byte, 0)
	for i := 0; i < len(arr); i++ {
		if arr[i] != 32 {
			retBytes = append(retBytes, arr[i])
		}
	}

	return string(retBytes)
}

func solve(input []byte) []string {
	ret := make([]string, 0)
	stack := make([]int, 0)
	pairs := make([]Pair, 0)

	for i := 0; i < len(input); i++ {
		if input[i] == byte('(') {
			stack = append(stack, i)
		} else if input[i] == byte(')') {
			pairs = append(pairs, Pair{lPos: stack[len(stack)-1], rPos: i})
			stack = stack[0 : len(stack)-1]
		}
	}

	for cases := 0; cases < (1 << len(pairs)); cases++ {
		bucket := make([]byte, len(input))
		copy(bucket, input)
		for idx := 0; idx < len(pairs); idx++ {
			if ((cases >> idx) & 1) == 0 {
				bucket[pairs[idx].lPos] = byte(32)
				bucket[pairs[idx].rPos] = byte(32)
			}
		}
		ret = append(ret, bytesToStrWithTrim(bucket))
	}

	return ret[0 : len(ret)-1]
}

func main() {
	scanner.Split(bufio.ScanWords)
	defer stdout.Flush()

	input := nextString()

	ans := unique(solve([]byte(input)))

	sort.Strings(ans)
	for i := 0; i < len(ans); i++ {
		fmt.Fprintf(stdout, "%s\n", ans[i])
	}

	return
}
