*This project has been created as part of the 42 curriculum by nambirak, aranirin.*

# push_swap

## Description

`push_swap` is a sorting project from the 42 curriculum. The goal is to sort a list of integers using only two stacks (named `a` and `b`) and a limited set of operations (push, swap, rotate, reverse rotate), using the fewest operations possible.

This repository implements multiple sorting strategies and an adaptive dispatcher that selects the best algorithm depending on input size and disorder level.

## Authors & Contributions

- **nambirak** - core stack and sorting operations, index assignment, disorder computation, adaptive strategy,simple strategy, medium strategy, benchmarking,strategy selector (`ft_push.c`,`ft_rotate.c`,`ft_rotate_reverse.c`,`ft_swap_a.c`,`algo_simple.c`,`chunk_sort.c` `adaptive.c` ,`flag.c`,`ft_printf_fd.c`,`Bench.c`,`flag_utils.c`,`chunks_utils.c`).
- **aranirin** - main launcher & program error management & README.md : duplicated parsing, integer overflow , and complex radix logic , leaks solver (`radix.c`,`radix utils.c`,`init.c`,`error.c`,`ft_check_duplicate.c`,`l atoi.c`,`main.c`,`is_valid_format.c`,`ft_free_split.c`,`README.md` , `push_swap.h`,`Makefile`,`utils.c`).

## Instructions

### Requirements

- Linux or macOS
- C compiler (cc) supporting C99 or later
- Make

### Compilation

```bash
make
```
Available targets:

- `make` - build `push_swap`
- `make clean` - remove object files
- `make fclean` - remove object files and binary
- `make re` - full rebuild

### Execution

```bash
./push_swap <list of integers>
```

Example:

```bash
./push_swap 5 3 1 4 2
```

Output is a list of operations (one per line) that sorts the input stack in ascending order.

### Validation with checker

```bash
chmod +x checker_linux
ARG="5 3 1 4 2" && ./push_swap $ARG | ./checker_linux $ARG
```

Should print `OK` if the operations correctly sort the stack.

### Error handling

```bash
./push_swap 1 2 one    # Error - not an integer
./push_swap 1 2 2      # Error - duplicate
./push_swap            # no output, no error
```

## Usage examples

```bash
# Already sorted - no output
./push_swap 1 2 3

# 3 elements
./push_swap 3 2 1
# Output: sa rra

# 5 elements
./push_swap 5 3 1 4 2

# 100 random numbers
shuf -i 0-999 -n 100 > args.txt
./push_swap $(cat args.txt) | wc -l

# 500 random numbers

```

## Algorithms - explanation and justification

### Data structure

push_swap/
├── main.c \
├── init.c \
├── is_valid_format.c \
├── ft_check_duplicate.c \
├── l_atoi.c \
├── ft_free_split.c \
├── error.c \
├── ft_push.c \
├── ft_swap_a.c \
├── ft_rotate.c \
├── ft_rotate_reverse.c \
├── algo_simple.c \
├── chunk_sort.c \
├── radix.c \
├── adaptive.c \
├── utils.c \
├── chunks_utils.c \
├── radix_utils.c \
├── flag.c \
├── flag_utils.c \
├── bench.c \
└── ft_printf_fd.c

We use a custom singly-linked list `t_stack` with three fields:

- `value` - the actual integer
- `index` - its rank in the sorted order (0 = smallest)
- `next` - pointer to next stack

Using `index` instead of `value` in algorithms like radix_sort simplifies the logic and makes it work with any integer range.

### 1. Simple sort - O(n²)

**File:** `simple_sort.c`.
**For 2 elements:** one `sa` if needed.

**For 3 elements:** five hardcoded cases covering all permutations with at most 2 operations.

**For 4-5 elements:** push the minimum to B repeatedly until 3 remain, sort those 3, then push B back.

**Justification:** for tiny inputs, pattern-based approaches produce fewer operations than general algorithms. Overhead of chunk or radix is unnecessary.

### 2. Chunk sort — O(n√n)

**File:** `chunk_sort.c`
The algorithm works in three main steps:

1 - Index the elements based on their sorted order.\
2 - Push elements to stack B in groups (chunks).\
3 - Push them back to A in the correct order.\
Indexing (index_stack)
Each value is replaced by its rank (0 → smallest, n-1 → largest)
Push to B (push_to_b)
Elements are moved to stack B in chunks to reduce operations
Find max (max_pos)
Locate the biggest element in stack B
Push back (push_max_to_a)
Bring the largest element to the top (using rb or rrb), then pa
**Justification:** chunking reduces the number of full-stack scans. Instead of scanning for the global min every time (O(n²)), we scan for elements within a bounded range, spreading the work efficiently. With tuned chunk sizes this gives good results for ~100 elements.

### 3. Radix sort — O(n log n)
**File:** `radix.c`
**Approach:** LSD binary radix on `index` values (ranks 0..n-1):

- For each bit position from LSB to MSB:
  - Scan all n elements of A
  - If bit = 0 → push to B
  - If bit = 1 → rotate A
  - Push everything from B back to A
- Repeat for all bits needed to represent the maximum index

**Justification:** radix on ranks performs exactly `n * k` operations where k = number of bits ≈ log2(n). For 500 elements this is ~9 passes × 500 = ~4500 operations, which is well within the excellent performance target (<5500).

### 4. Adaptive strategy

**File:** `adaptive.c` .

**Disorder metric:** disorder is measured as inversions / max_inversions, giving a value in [0, 1]. This metric is computed before sorting and could be used to refine the threshold decisions.

**Justification:** no single algorithm is optimal for all sizes. The adaptive approach combines:

- Fast hardcoded sequences for tiny inputs
- Chunk-based locality for medium inputs
- Predictable bit-manipulation for large inputs

## Resources

- 42 project subject (push_swap rules and constraints)
- Community write-ups: search "push_swap 42 chunk sort", "push_swap radix sort"
- Wikipedia: Radix sort, Insertion sort, chunk sort,
- https://push-swap42-visualizer.vercel.app/ for testing operation .

## AI usage
## 🤖 AI Usage

Artificial Intelligence tools were used during the development of this project as a **learning and assistance tool**, not as a replacement for understanding.

AI was mainly used for:

* Explaining algorithms (radix sort, chunk sort, small sort)
* Clarifying concepts such as complexity and optimization
* Debugging and identifying logical errors
* Improving code structure and readability

AI served as a **support tool to accelerate learning**, while maintaining full control over the design and implementation of the project.



## Command line flags

The implementation supports the following flags:

- `--bench` — enable benchmark reporting to `stderr` after sorting
- `--simple` — force the simple sort algorithm (`algo_simple`, O(n²))
- `--medium` — force chunk sort (`chunk_sort`, O(n√n))
- `--complex` — force radix sort (`radix`, O(n log n))
- `--adaptive` — use the adaptive strategy (`adaptive`) (default)

Flags may appear anywhere in the command line and are removed before input parsing. Numeric tokens can be provided as separate arguments or in quoted strings.

### Example

```bash
./push_swap --bench --complex 5 3 1 4 2
