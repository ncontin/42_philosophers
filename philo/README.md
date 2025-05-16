# 42_philosophers

## Overview

This project implements the classic Dining Philosophers problem, a synchronization and resource allocation challenge in concurrent programming.

## Problem Description

- A specified number of philosophers sit around a circular table
- Each philosopher alternates between thinking and eating
- A fork is placed between each pair of philosophers
- A philosopher needs two forks to eat (left and right)
- After eating, philosophers put down forks and start thinking again
- The simulation stops if a philosopher dies of starvation

## Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

## Example

```bash
./philo 5 800 200 200 7
```

## Implementation Details

- Each philosopher is represented by a thread
- Forks are shared resources protected by mutexes
- Death detection runs in parallel with philosopher activities
- All timestamps are in milliseconds

## Requirements

- No data races
- No philosopher should die if parameters are reasonable
- Implementation must comply with 42 norm
