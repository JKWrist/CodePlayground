#!/usr/bin/env python3

d = {}
print(d, type(d))

d = {"name":"雪碧", "price":19, "count": 2, "volume":500}
print(d)

d["price"] = 3
print(d)

d["made in"] = "China"

d.update({"color":"white"})
print(d)