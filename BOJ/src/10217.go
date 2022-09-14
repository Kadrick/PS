/**
 * @file 10217.go
 * @author kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-04-07 10:23
 *
 * @copyright Copyright (c) 2021
 *
 */
package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
)

const inf int = math.MaxInt32

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

//////////////////////////////////////////////////////////////

type Edge struct {
	target, cost, time int
}

type Vertex struct {
	here, time, money int
}

type Hp []Vertex

func (h Hp) Len() int {
	return len(h)
}

func (h Hp) Less(i, j int) bool {
	return h[i].time < h[j].time
}

func (h Hp) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *Hp) Push(x interface{}) {
	*h = append(*h, x.(Vertex))
}

func (h *Hp) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

func solve() {
	n, m, k := nextInt(), nextInt(), nextInt()
	var graph [101][]Edge

	for i := 0; i < n; i++ {
		graph[i] = make([]Edge, 0)
	}

	for i := 0; i < k; i++ {
		u, v, c, d := nextInt(), nextInt(), nextInt(), nextInt()
		graph[u] = append(graph[u], Edge{target: v, cost: c, time: d})
	}

	pq := new(Hp)

	dist := [101][10001]int{}
	for i := 0; i <= n; i++ {
		for j := 0; j <= m; j++ {
			dist[i][j] = inf
		}
	}

	dist[1][0] = 0
	heap.Push(pq, Vertex{here: 1, time: 0, money: 0})

	for pq.Len() > 0 {
		airport := heap.Pop(pq).(Vertex)

		if airport.time > dist[airport.here][airport.money] {
			continue
		}

		for _, next := range graph[airport.here] {
			if next.cost+airport.money > m {
				continue
			}

			if next.time+airport.time < dist[next.target][next.cost+airport.money] {
				for i := next.cost + airport.money; i <= m; i++ {
					if dist[next.target][i] > dist[airport.here][i-next.cost]+next.time {
						dist[next.target][i] = dist[airport.here][i-next.cost] + next.time
					} else {
						break
					}
				}
				heap.Push(pq, Vertex{
					here:  next.target,
					time:  airport.time + next.time,
					money: airport.money + next.cost,
				})
			}
		}

	}

	ans := inf

	for i := 0; i <= m; i++ {
		ans = min(dist[n][i], ans)
	}

	if ans == inf {
		fmt.Fprintln(print, "Poor KCM")
	} else {
		fmt.Fprintln(print, ans)
	}

	return
}

//////////////////////////////////////////////////////////////

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	var tc = nextInt()

	for i := 0; i < tc; i++ {
		solve()
	}

	return
}
