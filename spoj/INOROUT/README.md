Problem statement: https://www.spoj.com/problems/INOROUT/

Category: computational geometry

What I learned: Using cross product and the center of polygon to determine
which side of the line a point is on. 
1. Given the vertices, compute all the edges of the polygon (subtracting two
points gives a vector).
2. Compute the center of gravity of the polygon.
3. For each vertex `i`, compute the vector `v1` from vertex `i` to point Q, and
the vector `v2` from vertex `i` to the center.
4. For each edge `u`, compute the cross products `u x v1` and `u x v2`. If `u x
v1` equals 0, then Q is on the edge and considered to be inside the polygon. If
`u x v1` and `u x v2` have the different sign, then Q is on opposite sides of
the center and therefore outside the polygon. 
