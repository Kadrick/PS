/**
* @file 1303.go
* @author kadrick (kbk2581553@gmail.com)
* @brief bfs
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
)

var n, m, blue, white int
var board [][]byte
var visited [][]bool

type Point struct {
	x, y int
}

func inRange(x, y int) bool {
	return 0 <= x && x < m && 0 <= y && y < n
}

func search(x, y int, color byte) (power int) {
	power = 1
	visited[x][y] = true
	q := make([]Point, 0)
	q = append(q, Point{x, y})

	dx := []int{-1, 0, 1, 0}
	dy := []int{0, 1, 0, -1}

	for len(q) != 0 {
		front := q[0]
		q = q[1:]

		for i := 0; i < 4; i++ {
			nx := front.x + dx[i]
			ny := front.y + dy[i]

			if inRange(nx, ny) {
				if board[nx][ny] == color && !visited[nx][ny] {
					power++
					q = append(q, Point{nx, ny})
					visited[nx][ny] = true
				}
			}
		}
	}

	power = int(math.Pow(float64(power), 2))
	return
}

func main() {
	fmt.Scan(&n, &m)
	board = make([][]byte, m)

	for i := 0; i < m; i++ {
		board[i] = make([]byte, n)
		fmt.Scan(&board[i])
	}

	visited = make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}

	blue = 0
	white = 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if !visited[i][j] {
				power := search(i, j, board[i][j])
				if board[i][j] == byte('B') {
					blue += power
				} else {
					white += power
				}
			}
		}
	}

	fmt.Print(white, blue)
	return
}
