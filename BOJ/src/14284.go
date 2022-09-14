/**
 * @file 14284.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief dijkstra
 * @version 0.1
 * @date 2022-04-08 14:09
 *
 * @copyright Copyright (c) 2022
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

type edge struct {
	dst  int
	cost int
}

var ans int

type Item struct {
	value    int
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func (pq *PriorityQueue) update(item *Item, value int, priority int) {
	item.value = value
	item.priority = priority
	heap.Fix(pq, item.index)
}

func findShortestPath(n, start, end int, graph [][]edge) int {
	dist := make([]int, n+1)
	for i := 0; i <= n; i++ {
		dist[i] = inf
	}
	dist[start] = 0

	q := &PriorityQueue{}
	heap.Init(q)
	heap.Push(q, &Item{priority: 0, value: start})

	for q.Len() != 0 {
		current := heap.Pop(q).(*Item)

		for _, value := range graph[current.value] {
			if dist[value.dst] > current.priority+value.cost {
				dist[value.dst] = current.priority + value.cost
				q.Push(&Item{value: value.dst, priority: dist[value.dst]})
			}
		}
	}

	ret := -1

	if dist[end] != inf {
		ret = dist[end]
	}

	return ret
}

func main() {
	scanner.Split(bufio.ScanWords)
	defer stdout.Flush()

	n, m := nextInt(), nextInt()

	graph := make([][]edge, n+1)
	for i := 0; i < n; i++ {
		graph[i] = make([]edge, 0)
	}

	for i := 0; i < m; i++ {
		a, b, c := nextInt(), nextInt(), nextInt()
		graph[a] = append(graph[a], edge{dst: b, cost: c})
		graph[b] = append(graph[b], edge{dst: a, cost: c})
	}

	s, t := nextInt(), nextInt()

	ans = findShortestPath(n, s, t, graph)
	fmt.Fprintf(stdout, "%d\n", ans)

	return
}
