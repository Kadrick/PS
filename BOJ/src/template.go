/**
 * @file template.go
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
var stdout = bufio.NewWriter(os.Stdout)

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

var ans int

func main() {
	scanner.Split(bufio.ScanWords)
	defer stdout.Flush()

	ans = nextInt()
    fmt.Fprintf(stdout, "%d\n", ans)

	return
}
