# Python script to find Dot Product of 2 vectors.
v1=[1,2,3]
v2=[4,5,6]
def dot_prod(v1, v2):
    assert len(v1)==len(v2),"Not same"
    return sum([v1_i*v2_i for v1_i,v2_i in zip(v1,v2)])
print(dot_prod(v1, v2))
