/**
 * @file 1600.go
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief BFS
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

type move struct {
	x int
	y int
}

type trace struct {
	x int
	y int
	k int
}

type element struct {
	coordinate move
	step       int
	knight     int
}

var knightDir [8]move = [8]move{
	{x: 2, y: 1},
	{x: 1, y: 2},
	{x: -1, y: 2},
	{x: -2, y: 1},
	{x: -2, y: -1},
	{x: -1, y: -2},
	{x: 1, y: -2},
	{x: 2, y: -1},
}

var monkeyDir [4]move = [4]move{
	{x: 1, y: 0},
	{x: 0, y: 1},
	{x: -1, y: 0},
	{x: 0, y: -1},
}

type queue struct {
	data []element
}

func NewQueue() *queue {
	return &queue{
		data: make([]element, 0),
	}
}

func (q *queue) push(obj element) {
	q.data = append(q.data, obj)
}

func (q *queue) empty() bool {
	return len(q.data) == 0
}

func (q *queue) pop() element {
	retData := q.data[0]
	q.data = q.data[1:]
	return retData
}

func inRange(x, y, w, h int) bool {
	return (0 <= x && x < w && 0 <= y && y < h)
}

func checkTile(x, y, k, w, h int, visit map[trace]bool, board map[move]bool) bool {
	_, visited := visit[trace{x: x, y: y, k: k}]
	_, possible := board[move{x: x, y: y}]
	return inRange(x, y, w, h) && !visited && possible
}

func main() {
	scanner.Split(bufio.ScanWords)
	defer stdout.Flush()

	ans, k, w, h := 0, nextInt(), nextInt(), nextInt()

	find := false
	q := NewQueue()
	end := move{x: w - 1, y: h - 1}
	visit, board := make(map[trace]bool), make(map[move]bool)

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			possible := nextInt()
			if possible == 0 {
				board[move{x: j, y: i}] = true
			}
		}
	}

	q.push(element{
		coordinate: move{x: 0, y: 0},
		step:       0,
		knight:     0,
	})

	visit[trace{}] = true

	for !q.empty() {
		current := q.pop()

		if current.coordinate == end {
			find = true
			ans = current.step
			break
		}

		if current.knight < k {
			for i := 0; i < 8; i++ {
				nx := current.coordinate.x + knightDir[i].x
				ny := current.coordinate.y + knightDir[i].y

				if checkTile(nx, ny, current.knight+1, w, h, visit, board) {
					next := element{
						coordinate: move{x: nx, y: ny},
						step:       current.step + 1,
						knight:     current.knight + 1,
					}

					q.push(next)
					visit[trace{x: nx, y: ny, k: next.knight}] = true
				}
			}
		}

		for i := 0; i < 4; i++ {
			nx := current.coordinate.x + monkeyDir[i].x
			ny := current.coordinate.y + monkeyDir[i].y

			if checkTile(nx, ny, current.knight, w, h, visit, board) {
				next := element{
					coordinate: move{x: nx, y: ny},
					step:       current.step + 1,
					knight:     current.knight,
				}

				q.push(next)
				visit[trace{x: nx, y: ny, k: next.knight}] = true
			}
		}
	}

	if find {
		fmt.Fprintln(stdout, ans)
	} else {
		fmt.Fprintln(stdout, -1)
	}

	return
}
