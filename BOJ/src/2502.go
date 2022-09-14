/**
 * @file 2502.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-04-06 11:11
 *
 * @copyright Copyright (c) 2021
 *
 */
package main

import "fmt"

func main() {
	var d, k int
	fmt.Scan(&d, &k)

	fibo := make([]int, d+1)
	fibo[1] = 1

	for i := 2; i < d; i++ {
		fibo[i] = fibo[i-1] + fibo[i-2]
	}

	// target(k) = A * fibo[d - 2] + B * fibo[d - 1]
	ansA, ansB := 1, 1

	for {
		ansB = (k - ansA*fibo[d-2]) / fibo[d-1]

		if ansA*fibo[d-2]+ansB*fibo[d-1] == k {
			break
		}
		ansA++
	}

	fmt.Println(ansA)
	fmt.Println(ansB)

	return
}
