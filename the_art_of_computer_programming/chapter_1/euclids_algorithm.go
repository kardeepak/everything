package main

import (
    "testing"
    "fmt"
)

func greatest_common_divisor(m, n int) int {
    testing.assert(m > 0 && n > 0);
    r := m % n;
    if r == 0 {
        return n
    } else {
        return greatest_common_divisor(n, r)
    }
}

func main() {
    fmt.Println("hello world")
}