/**
 * @file 2212.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief greedy
 * @version 0.1
 * @date 2022-04-05
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	if k >= n {
		fmt.Print(0)
		return
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	tmp := arr[0]
	dist := make([]int, 0)
	for i := 1; i < n; i++ {
		dist = append(dist, arr[i]-tmp)
		tmp = arr[i]
	}

	sort.Slice(dist, func(i, j int) bool {
		return dist[i] < dist[j]
	})

	ans := 0
	for i := 0; i < n-k; i++ {
		ans += dist[i]
	}

	fmt.Printf("%d", ans)
	return
}
