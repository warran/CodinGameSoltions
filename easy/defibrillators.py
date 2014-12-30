import sys, math

def parse_float(s):
    ns = '.'.join(s.split(','))
    return float(ns)
    
def parse_defib(s):
    data = s.split(';')
    name = data[1]
    lon = parse_float(data[-2])
    lat = parse_float(data[-1])
    return (name, lon, lat)

def dist(lon1, lat1, lon2, lat2):
    x = (lon2 - lon1) * math.cos((lat1 + lat2)/2.0)
    y = lat2 - lat1
    return math.sqrt(x*x + y*y) * 6371.0

LON = parse_float(raw_input())
LAT = parse_float(raw_input())
N = int(raw_input())

mname = ""
mdist = 100.0 * 6371.0    # definietly bigger than earths equator length
for i in xrange(N):
    name, lon, lat = parse_defib(raw_input())
    d = dist(LON, LAT, lon, lat)
    if d < mdist:
        mdist = d
        mname = name

print mname
