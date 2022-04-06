/**
 * @file 9370.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-04-06 13:53
 *
 * @copyright Copyright (c) 2021
 *
 */
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
	"sort"
)

var in *bufio.Reader

const inf int = int(1e9)

type Pair struct {
	pos, cost int
}

type MaxHeap []Pair

func (h MaxHeap) Len() int {
	return len(h)
}

func (h MaxHeap) Less(i, j int) bool {
	r := h[i].cost > h[j].cost
	return r
}

func (h MaxHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(Pair))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type Edge struct {
	target, cost int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func dijkstra(start, size int, graph *[][]Edge) (dist []int) {
	pq := &MaxHeap{}
	heap.Init(pq)

	dist = make([]int, size+1)
	for i := 0; i <= size; i++ {
		dist[i] = inf
	}

	dist[start] = 0
	heap.Push(pq, Pair{cost: 0, pos: start})

	for pq.Len() > 0 {
		here := heap.Pop(pq).(Pair)

		if dist[here.pos] < here.cost {
			continue
		}

		for _, next := range (*graph)[here.pos] {
			if dist[next.target] > here.cost+next.cost {
				dist[next.target] = here.cost + next.cost
				heap.Push(pq, Pair{cost: here.cost + next.cost, pos: next.target})
			}
		}
	}

	return
}

func solve() {
	var n, m, t, s, g, h, midDist int
	fmt.Fscan(in, &n, &m, &t, &s, &g, &h)

	graph := make([][]Edge, n+1)
	for i := 0; i < n; i++ {
		graph[i] = make([]Edge, 0)
	}

	for i := 0; i < m; i++ {
		var a, b, d int
		fmt.Fscan(in, &a, &b, &d)
		graph[a] = append(graph[a], Edge{target: b, cost: d})
		graph[b] = append(graph[b], Edge{target: a, cost: d})
		if (a == g && b == h) || (a == h && b == g) {
			midDist = d
		}
	}

	nominated := make([]int, t)
	for i := 0; i < t; i++ {
		fmt.Fscan(in, &nominated[i])
	}

	distS := dijkstra(s, n, &graph)
	distG := dijkstra(g, n, &graph)
	distH := dijkstra(h, n, &graph)

	stog := distS[g]
	stoh := distS[h]

	ans := make([]int, 0)

	for _, target := range nominated {
		gtot := distG[target]
		htot := distH[target]
		stot := distS[target]

		if gtot == inf || htot == inf || stot == inf {
			continue
		}

		stogtot := stog + midDist + htot
		stohtot := stoh + midDist + gtot

		if stot == stogtot || stot == stohtot {
			ans = append(ans, target)
		}
	}

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	for _, v := range ans {
		fmt.Printf("%d ", v)
	}
	fmt.Println("")
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var tc int
	fmt.Fscan(in, &tc)

	for i := 0; i < tc; i++ {
		solve()
	}

	return
}
