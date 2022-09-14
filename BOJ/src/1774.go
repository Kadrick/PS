/**
* @file 1774.go
* @author kadrick (kbk2581553@gmail.com)
* @brief mst
* @version 0.1
* @date 2022-04-05
*
* @copyright Copyright (c) 2022
*
 */
package main

import (
	"fmt"
	"math"
	"sort"
)

var n, m int

type Vertex struct {
	x, y float64
	id   int
}

type Edge struct {
	u, v int
	cost float64
}

func getDist(u, v Vertex) float64 {
	return math.Pow(u.x-v.x, 2) + math.Pow(u.y-v.y, 2)
}

var parent []int

func find(here int) int {
	if here == parent[here] {
		return here
	} else {
		parent[here] = find(parent[here])
		return parent[here]
	}
}

func union(u, v int) bool {
	u = find(u)
	v = find(v)

	if u == v {
		return false
	}

	if u > v {
		tmp := u
		u = v
		v = tmp
	}

	parent[v] = u
	return true
}

func main() {
	fmt.Scan(&n, &m)

	parent = make([]int, n)
	vinfo := make([]Vertex, 0)
	elist := make([]Edge, 0)

	for i := 0; i < n; i++ {
		parent[i] = i
		var x, y float64
		fmt.Scan(&x, &y)
		var v = Vertex{x: x, y: y, id: i}
		vinfo = append(vinfo, v)
	}

	cnt := 0
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		if union(u-1, v-1) {
			cnt++
		}
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			var e = Edge{u: i, v: j, cost: getDist(vinfo[i], vinfo[j])}
			elist = append(elist, e)
		}
	}

	sort.Slice(elist, func(i, j int) bool {
		return elist[i].cost < elist[j].cost
	})

	ans := 0.0
	for _, edge := range elist {
		if union(edge.u, edge.v) {
			cnt++
			ans += math.Sqrt(edge.cost)
		}
		if cnt == n-1 {
			break
		}
	}

	fmt.Printf("%.2f", ans)
	return
}
