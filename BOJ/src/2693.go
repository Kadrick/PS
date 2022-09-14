/**
 * @file 2693.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
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

var scanner = bufio.NewScanner(os.Stdin)
var print = bufio.NewWriter(os.Stdout)

func nextInt() int {
	scanner.Scan()
	text := scanner.Text()
	v, _ := strconv.Atoi(text)
	return v
}

//////////////////////////////////////////////////////////////

var n int

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	n = nextInt()

	for i := 0; i < n; i++ {
		arr := make([]int, 10)
		for j := 0; j < 10; j++ {
			arr[j] = nextInt()
		}

		sort.Slice(arr, func(i2, j int) bool {
			return arr[i2] > arr[j]
		})

		fmt.Fprintln(print, arr[2])
	}

	return
}
