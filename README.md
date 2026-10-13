# Lab A1a — making decisions

Three questions, one file each. Each one reads its input, decides, and prints the
answer — nothing more. You need only what is already covered: operator precedence,
`if`/`else`, integer arithmetic, and where a variable lives.

This course uses **C++17**. Build any question with:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic q1.cpp -o q1
./q1
```

Each program reads its input from the keyboard and prints **one line**.

---

## q1 — over-current protection

Input: `current safeLimit stopFlag` (a current, the safe limit, and `1` when the
emergency stop is pressed, `0` when it is not).

Test the conditions in this order — exceptional case first:

| Condition | Print |
| --- | --- |
| the current is negative | `INVALID` |
| the emergency stop is pressed, **or** the current is above `safeLimit` | `TRIP` |
| the current is above 90% of `safeLimit` | `WARNING` |
| anything else | `NORMAL` |

The order is the whole point. A negative reading is meaningless, so it is reported
before anything else is even considered — including the stop button.

Use `else if` for the middle conditions, so that reaching one means every condition
above it was already false. Watch the boundaries: *above* the limit trips, exactly at
it does not.

```text
3 10 0    -> NORMAL
9.5 10 0  -> WARNING
12 10 0   -> TRIP
```

## q2 — is the reading above the average?

Input: `lowLimit highLimit reading`, three whole numbers.

| Condition | Print |
| --- | --- |
| the reading is below the average of the two limits | `BELOW` |
| the reading is exactly the average | `EQUAL` |
| anything else | `ABOVE` |

The average of the two limits is `(lowLimit + highLimit) / 2` — but these are whole
numbers, and whole-number division throws the half away. With limits 3 and 4 the true
average is 3.5, yet `(3 + 4) / 2` is 3, so a reading of 3 would be called `EQUAL` when
it is really below.

Double the reading instead of halving the sum:

```cpp
if (2 * reading < lowLimit + highLimit)
```

Nothing is thrown away, and the comparison is exact. `*` and `+` both bind tighter
than `<`, so no brackets are needed.

```text
10 20 14 -> BELOW
10 20 15 -> EQUAL
10 20 16 -> ABOVE
3 4 3    -> BELOW
```
## q3 — is it a multiple?

Input: `value divisor`.

| Condition | Print |
| --- | --- |
| `divisor` is zero | `INVALID` |
| `value` is an exact multiple of `divisor` | `DIVISIBLE` |
| anything else | `NOT DIVISIBLE` |

`value % divisor` is the remainder left after dividing, so a remainder of zero means
it divided exactly.

`%` is **undefined when the divisor is zero** — the program may do anything at all,
including crash. So the zero has to be ruled out before the `%` is reached. Test it
first, or let `&&` stop early:

```cpp
if (divisor != 0 && value % divisor == 0)
```

The left side is checked first, and if it is false the right side never runs.

Zero is a multiple of everything, and negative values work the same way — check both
against your code rather than guessing.

```text
12 4 -> DIVISIBLE
13 4 -> NOT DIVISIBLE
7 0  -> INVALID
```

---

## Check your work

```bash
chmod +x check.sh
./check.sh
```

`chmod` is only needed once — unzipping a download removes the executable bit.

The check builds each question and runs five cases against it, then prints `PASS` or
shows you the input, what was expected, and what your program printed. The untouched
template fails every case; that is expected until you write the code.

## Submitting

Commit and push to `main`. The last commit on `main` at the deadline is what gets
graded. Editing a file only on your own machine does not submit anything.
