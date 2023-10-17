package main

import "time"

type Group struct {
	members   []string
}

type Project struct {
	due_date    time.Time
	description string
	submission_date []time.Time
}

func main() {
}
