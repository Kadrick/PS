/**
 * @file 25308.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief ccw
 * @version 0.1
 * @date 2022-09-02 09:18
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

var (
	scanner = bufio.NewScanner(os.Stdin)
	print   = bufio.NewWriter(os.Stdout)
)

func nextInt() int {
	scanner.Scan()
	text := scanner.Text()
	v, _ := strconv.Atoi(text)
	return v
}

//////////////////////////////////////////////////////////////

type Point struct {
	x float64
	y float64
}

var unitV = [8]Point{
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1},
}

func getPos(dist, direction int) Point {
	var ret Point
	fdist := float64(dist)

	if direction%2 == 0 {
		ret = Point{
			x: fdist * unitV[direction].x,
			y: fdist * unitV[direction].y,
		}
	} else {
		fdist = fdist / math.Sqrt(2)
		ret = Point{
			x: fdist * unitV[direction].x,
			y: fdist * unitV[direction].y,
		}
	}

	return ret
}

// point 1 to point 3 clockwise check
// -1 = clockwise, 0 = straight, 1 = counterclockwise
func ccw(p1, p2, p3 Point) int {
	p1top2Vec := Point{p2.x - p1.x, p2.y - p1.y}
	p2top3Vec := Point{p3.x - p2.x, p3.y - p2.y}

	zValue := p1top2Vec.x*p2top3Vec.y - p2top3Vec.x*p1top2Vec.y

	if zValue > 0 {
		return 1
	} else if zValue == 0 {
		return 0
	}
	return -1
}

func Factorial(n int) int {
	var result int
	if n > 0 {
		result = n * Factorial(n-1)
		return result
	}
	return 1
}

func checkConcave(array []int) bool {
	array = append(array, array[0:2]...)

	for i := 0; i < 8; i++ {
		pStart, pCenter, pEnd := getPos(array[i], i%8),
			getPos(array[i+1], (i+1)%8),
			getPos(array[i+2], (i+2)%8)
		if ccw(pStart, pCenter, pEnd) == 1 {
			return true
		}
	}
	return false
}

var impossible int = 0

func Permutation(src, gen []int, visit []bool) {
	if len(gen) == len(visit) {
		if checkConcave(gen) {
			impossible++
		}
	}

	for i := 0; i < len(visit); i++ {
		if visit[i] {
			continue
		}

		visit[i] = true
		gen = append(gen, src[i])
		Permutation(src, gen, visit)
		gen = gen[0 : len(gen)-1]
		visit[i] = false
	}
}

func solve(arr []int) int {
	maximum := Factorial(len(arr))
	Permutation(arr, make([]int, 0), make([]bool, len(arr)))
	return maximum - impossible
}

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	stats := make([]int, 0)

	for i := 0; i < 8; i++ {
		point := nextInt()
		stats = append(stats, point)
	}

	fmt.Fprintf(print, "%d\n", solve(stats))

	return
}
