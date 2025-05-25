
# 🏰 Editorial: Magical Defense Towers

## 🧾 Problem Summary

We are given `N` magical towers located on a 1D line. Each tower has:

- A position `pos[i]`
- A power level `p[i]`
- A spell range `r[i]`, covering positions from `pos[i] - r[i]` to `pos[i] + r[i]` (inclusive)

**Key twist**:  
If multiple towers’ ranges overlap at a point, their powers are weakened due to **magical interference**. Specifically:

- If `k` towers overlap at a point, each tower’s power is divided by `k` (using floor division).
- The **effective power** of a tower is determined by the **maximum overlap count** within its range.
- The final defense strength is the **sum of the effective powers** of all towers.

---

## 💡 Goal

Compute the **total effective defense strength**, after applying interference-based reductions due to range overlaps.

---

## 🔍 Observations

1. Each tower casts a **symmetric range**: from `pos[i] - r[i]` to `pos[i] + r[i]`.
2. If towers overlap at a single point, they all suffer interference.
3. The **worst interference level** (maximum overlap count) within a tower’s range determines the power reduction.

Thus, for each tower, we must:
- Determine how many towers overlap **at any point** within its range.
- Find the **maximum overlap count** in that range.
- Divide the original power by that maximum count to get the effective power.

---

## 🧠 Key Idea: Sweep Line Algorithm

To efficiently determine overlapping tower counts across all positions, we use a **sweep line algorithm**. Here's how:

### Step 1: Range Event Representation

For each tower with range \([L_i, R_i]\), create two events:

- **Start** of coverage at \(L_i\): `(+1)`
- **End** of coverage at \(R_i + 1\): `(-1)`

This models the **change in active tower count** as we "sweep" across the number line.

### Step 2: Coordinate Compression

- The coordinate space goes up to \(10^9\), so iterating directly is infeasible.
- We collect all **critical points**: `L_i`, `R_i + 1` for all towers.
- We **compress** them into a smaller space of unique sorted indices.

This enables fast processing using a segment tree, Fenwick tree, or even a prefix sum array.

### Step 3: Building Overlap Count Map

- Using the sorted events, sweep from left to right.
- Maintain a current `active_count` as events are processed.
- For each segment between two coordinates, note the current `active_count`.

This gives us the number of overlapping towers at each segment of the line.

### Step 4: For Each Tower, Query Max Overlap in its Range

For tower \(i\) with range \([L_i, R_i]\):

- Use binary search to find compressed indices for `L_i` and `R_i`.
- Query the **maximum overlap count** in that range using a segment tree or precomputed array.

Then, compute:

\[
	ext{effective power}_i = \left\lfloor rac{p[i]}{	ext{max overlap count in range}} ightfloor
\]

Sum all effective powers to get the final result.

---

## 🧮 Time and Space Complexity

### Time Complexity

- Coordinate compression: \(O(N \log N)\)
- Sorting events: \(O(N \log N)\)
- Sweeping to build overlap array: \(O(N)\)
- For each tower, querying max overlap: \(O(\log N)\) with segment tree

**Total**: \(O(N \log N)\)

### Space Complexity

- \(O(N)\) for storing events, overlaps, and compressed coordinates

---

## 🧾 Example

### Input:
```
4
1 60 1
2 80 1
3 90 2
6 120 1
```

### Breakdown:

| Tower | Range        | Power | Covered Points     |
|-------|--------------|-------|--------------------|
| 1     | [0, 2]       | 60    | 0, 1, 2            |
| 2     | [1, 3]       | 80    | 1, 2, 3            |
| 3     | [1, 5]       | 90    | 1, 2, 3, 4, 5      |
| 4     | [5, 7]       | 120   | 5, 6, 7            |

At positions:

- 1, 2 → 3 towers overlap ⇒ power // 3
- 5 → towers 3 and 4 overlap ⇒ tower 4 gets power // 2  
  But tower 3 already has 3-way interference, so remains //3

### Final effective powers:

- Tower 1: 60 // 3 = 20
- Tower 2: 80 // 3 = 26
- Tower 3: 90 // 3 = 30
- Tower 4: 120 // 2 = 60

**Total = 20 + 26 + 30 + 60 = 136**

---

## ✅ Implementation Summary

1. Collect all range boundaries (start and end).
2. Compress coordinates for efficient access.
3. Build a difference array for overlaps.
4. Accumulate to find overlap count at each point.
5. For each tower, find maximum overlap in its range.
6. Divide power by that count.
7. Return total effective power.

---

## ✨ Final Thoughts

This problem beautifully combines geometry, interval manipulation, and prefix-based range processing using:

- **Sweep line algorithm**
- **Coordinate compression**
- **Efficient interval maximum tracking**

These tools make it possible to handle large inputs and complex overlaps efficiently.

---
