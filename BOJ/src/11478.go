/**
 * @file 11478.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief map
 * @version 0.1
 * @date 2022-09-01 13:38
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
	print   = bufio.NewWriter(os.Stdout)
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

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	ans := 0
	memo := make(map[string]bool)
	input := []byte(nextString())

	for size := 1; size <= len(input); size++ {
		for start := 0; start <= len(input)-size; start++ {
			if _, exist := memo[string(input[start:start+size])]; !exist {
				memo[string(input[start:start+size])] = true
				ans++
			}
		}
	}

	fmt.Fprintf(print, "%d\n", ans)

	return
}
