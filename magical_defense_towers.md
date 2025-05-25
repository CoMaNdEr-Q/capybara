
# 🏰 Magical Defense Towers

## 🧾 Problem Statement

You are defending a magical kingdom with **N towers** placed on a straight line. Each tower has a magical power level `p[i]` and can cast a defensive spell that covers a range of `r[i]` units in both directions from its position.

However, there's a catch: when two or more towers' spell ranges **overlap**, their combined magical energy creates **interference**. The interference **reduces the effective power** of *all* overlapping towers by exactly half (integer division), or more if more towers are involved.

---

## Additional Rules

1. A tower at position `pos[i]` with range `r[i]` covers positions `[pos[i] - r[i], pos[i] + r[i]]` (inclusive).
2. If 2 towers overlap at a point, each tower's power becomes `power // 2`.
3. If 3 towers overlap at a point, each becomes `power // 3`.
4. If 4 or more towers overlap, each becomes `power // 4`, and so on.
5. The final defense strength is the **sum of all effective tower powers**.

---

## Input Format

- First line: Integer `N` — the number of towers.
- Next `N` lines: Three integers each: `pos[i] p[i] r[i]`  
  (Position, power, and range of tower `i`)

---

## Output Format

- A single integer: The **total effective defense strength**.

---

## Constraints

- \( 1 \leq N \leq 10^5 \)
- \( 1 \leq     ext{pos}[i] \leq 10^9 \)
- \( 1 \leq p[i] \leq 10^6 \)
- \( 1 \leq r[i] \leq 10^6 \)

---

## Sample Input 1

```
3
5 100 2
10 200 3
15 150 1
```

### Sample Output 1

```
300
```

### Explanation

- Tower 1 covers `[3, 7]`, power = 100  
- Tower 2 covers `[7, 13]`, power = 200  
- Tower 3 covers `[14, 16]`, power = 150  

Tower 1 and 2 overlap at position `7`, so both get `power // 2`.  
Tower 3 has no overlap.

Final powers:
- Tower 1: `100 // 2 = 50`  
- Tower 2: `200 // 2 = 100`  
- Tower 3: `150`  

**Total = 50 + 100 + 150 = 300**

---

## Sample Input 2

```
4
1 60 1
2 80 1
3 90 2
6 120 1
```

### Sample Output 2

```
136
```

### Explanation

- Tower 1: `[0, 2]`  
- Tower 2: `[1, 3]`  
- Tower 3: `[1, 5]`  
- Tower 4: `[5, 7]`  

Overlaps:
- Positions 1–2: Towers 1, 2, and 3 overlap → divide all by 3
- Position 5: Towers 3 and 4 overlap → divide by 2  
  *But Tower 3 already has a worse division (by 3), so that dominates.*

Final powers:
- Tower 1: `60 // 3 = 20`  
- Tower 2: `80 // 3 = 26`  
- Tower 3: `90 // 3 = 30`  
- Tower 4: `120 // 2 = 60`  

**Total = 20 + 26 + 30 + 60 = 136**


---


