/**
 * @file 15904.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief string
 * @version 0.1
 * @date 2022-04-26 13:28
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
var print = bufio.NewWriter(os.Stdout)

func nextInt() int {
	scanner.Scan()
	text := scanner.Text()
	v, _ := strconv.Atoi(text)
	return v
}

//////////////////////////////////////////////////////////////

var ans bool
var pointer int = 0
var ucpcString []byte = []byte("UCPC")
var goodString string = "I love UCPC"
var hateString string = "I hate UCPC"

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	for scanner.Scan() {
		word := scanner.Text()
		for _, char := range word {
			if ucpcString[pointer] == byte(char) {
				pointer++
			}

			if pointer == 4 {
				ans = true
				break
			}
		}

		if ans {
			break
		}
	}

	if ans {
		fmt.Fprintln(print, goodString)
	} else {
		fmt.Fprintln(print, hateString)
	}

	return
}
