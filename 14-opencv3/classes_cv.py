#!/usr/bin/env python

import classes_cv

t = classes_cv.World()

t.init_cv_mat(3, 2)

vec = t.cv_mat_vec_self()
print(vec)

l1 = list(range(10))
l2 = list(range(10, 20))

u = t.transform(l1, l2)

print(u)
print(u[0])
print(u[1])
