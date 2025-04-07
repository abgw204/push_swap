# 🧠 Push Swap

This is a sorting algorithm project from the 42 curriculum.

The goal is to sort a stack of integers with a limited set of operations and using only two stacks (`a` and `b`). The challenge is to do it with **as few moves as possible**.

---

### 📚 About the Algorithm

I used a **binary Radix Sort** strategy to solve the problem efficiently.

It works by:
- Indexing all the numbers to normalize the input.
- Sorting them bit by bit (from LSB to MSB).
- Using only the allowed operations: `sa`, `pb`, `ra`, `rb`, `pa`, etc.

This method guarantees sorting in **O(n × log n)** operations, which is performant and within project expectations.

---

### ⚙️ How to Use

```bash
# Compile
make

# Run with a list of numbers
./push_swap 3 2 1
