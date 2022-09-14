/**
 * @file 14916.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief math
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	ans := 0

	if n == 1 || n == 3 {
		ans = -1
	} else if n%5 == 0 {
		ans = n / 5
	} else if (n%5)%2 == 0 {
		ans = n/5 + (n%5)/2
	} else {
		ans = n/5 - 1 + ((n%5)+5)/2
	}

	fmt.Println(ans)

	return
}
