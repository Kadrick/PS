package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

const (
	debug       = true
	inf   int64 = math.MaxInt64
)

/*========================================================================*/
/* I/O */

var (
	// scanner = bufio.NewScanner(os.Stdin)
	// outF, _ = os.OpenFile("out.txt", os.O_WRONLY|os.O_TRUNC|os.O_CREATE, 0644)
	// print   = bufio.NewWriter(outF)

	scanner = bufio.NewScanner(os.Stdin)
	print   = bufio.NewWriter(os.Stdout)
)

func nextInt() int64 {
	scanner.Scan()
	text := scanner.Text()
	v, _ := strconv.ParseInt(text, 10, 64)
	return v
}

func nextString() string {
	scanner.Scan()
	text := scanner.Text()
	return text
}

/*========================================================================*/

type Filter struct {
	lv    int
	order []int
	child *Filter
}

func NewFilter(lv int) *Filter {
	if lv > 0 {
		ret := &Filter{
			lv:    lv,
			order: []int{0, 1, 2, 3},
			child: NewFilter(lv - 1),
		}
		return ret
	}
	return nil
}

func (this *Filter) vFlip(level int) {
	if this.lv >= level {
		tmp := this.order
		this.order = []int{tmp[3], tmp[2], tmp[1], tmp[0]}
	}
	if this.lv > 1 {
		this.child.vFlip(level)
	}
}

func (this *Filter) hFlip(level int) {
	if this.lv >= level {
		tmp := this.order
		this.order = []int{tmp[1], tmp[0], tmp[3], tmp[2]}
	}
	if this.lv > 1 {
		this.child.hFlip(level)
	}
}

func (this *Filter) rRotate(level int) {
	if this.lv >= level {
		tmp := this.order
		this.order = []int{tmp[3], tmp[0], tmp[1], tmp[2]}
	}
	if this.lv > 1 {
		this.child.rRotate(level)
	}
}

func (this *Filter) lRotate(level int) {
	if this.lv >= level {
		tmp := this.order
		this.order = []int{tmp[1], tmp[2], tmp[3], tmp[0]}
	}
	if this.lv > 1 {
		this.child.lRotate(level)
	}
}

func (this *Filter) vertical(level int) {
	if this.lv <= level {
		tmp := this.order
		this.order = []int{tmp[3], tmp[2], tmp[1], tmp[0]}
	}
	if this.lv > 1 {
		this.child.vertical(level)
	}
}

func (this *Filter) horizontal(level int) {
	if this.lv <= level {
		tmp := this.order
		this.order = []int{tmp[1], tmp[0], tmp[3], tmp[2]}
	}
	if this.lv > 1 {
		this.child.horizontal(level)
	}
}

func (this *Filter) right(level int) {
	if this.lv <= level {
		tmp := this.order
		this.order = []int{tmp[3], tmp[0], tmp[1], tmp[2]}
	}
	if this.lv > 1 {
		this.child.right(level)
	}
}

func (this *Filter) left(level int) {
	if this.lv <= level {
		tmp := this.order
		this.order = []int{tmp[1], tmp[2], tmp[3], tmp[0]}
	}
	if this.lv > 1 {
		this.child.left(level)
	}
}

func (this *Filter) get(level int) []int {
	if this.lv == level {
		return this.order
	}
	return this.child.get(level)
}

/*========================================================================*/

type Renderer struct {
	lv    int
	child []*Renderer
	y, x  int
}

func NewRenderer(y, x, lv int) *Renderer {
	ret := &Renderer{
		lv:    lv,
		child: nil,
	}

	if lv > 0 {
		size := 1 << lv
		ret.child = make([]*Renderer, 4)
		ret.child[0] = NewRenderer(y+0, x+0, lv-1)
		ret.child[1] = NewRenderer(y+0, x+size/2, lv-1)
		ret.child[2] = NewRenderer(y+size/2, x+size/2, lv-1)
		ret.child[3] = NewRenderer(y+size/2, x+0, lv-1)
	} else {
		ret.y, ret.x = y, x
	}

	return ret
}

func (this *Renderer) render(src, dst [][]int, filter *Filter, y, x int) {
	if this.lv == 0 {
		dst[y][x] = src[this.y][this.x]
	} else {
		size := 1 << this.lv
		order := filter.get(this.lv)
		this.child[order[0]].render(src, dst, filter, y+0, x+0)
		this.child[order[1]].render(src, dst, filter, y+0, x+size/2)
		this.child[order[2]].render(src, dst, filter, y+size/2, x+size/2)
		this.child[order[3]].render(src, dst, filter, y+size/2, x+0)
	}
}

func main() {
	scanner.Split(bufio.ScanWords)
	defer print.Flush()

	n, r := nextInt(), nextInt()

	arr, ans := make([][]int, 1<<n), make([][]int, 1<<n)
	for i := 0; i < 1<<n; i++ {
		arr[i] = make([]int, 1<<n)
		ans[i] = make([]int, 1<<n)
		for j := 0; j < 1<<n; j++ {
			arr[i][j] = int(nextInt())
		}
	}

	filter := NewFilter(int(n))

	for i := 0; i < int(r); i++ {
		k, l := int(nextInt()), int(nextInt())

		switch k {
		case 1:
			filter.vertical(l)
		case 2:
			filter.horizontal(l)
		case 3:
			filter.right(l)
		case 4:
			filter.left(l)
		case 5:
			filter.vFlip(l + 1)
		case 6:
			filter.hFlip(l + 1)
		case 7:
			filter.rRotate(l + 1)
		case 8:
			filter.lRotate(l + 1)
		}
	}

	renderer := NewRenderer(0, 0, int(n))
	renderer.render(arr, ans, filter, 0, 0)

	for i := 0; i < 1<<n; i++ {
		for j := 0; j < 1<<n; j++ {
			fmt.Fprintf(print, "%d ", ans[i][j])
		}
		fmt.Fprintf(print, "\n")
	}

}
