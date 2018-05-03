#!/usr/bin/env python

from policies import Example

#e = Example() # won't work, constructore not available from python
f1 = Example.factory()
s1 = Example.singleton()

f2 = Example.factory()
s2 = Example.singleton()


print ("f1 =",id(f1))
print ("f2 =",id(f2))

print ("s1 =",id(s1))
print ("s2 =",id(s2))

assert id(f1) != id(f2)
assert id(s1) == id(s2)