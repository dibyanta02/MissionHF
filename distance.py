v=[1,2,3]
w=[4,5,6]
def subtract(a,b):
    assert len(a)==len(b), "Not same length"
    return [i-j for i,j in zip(a,b)]
def dist_2_points(v,w):
    return (sos(subtract(v,w))) #The function SOS returns Sum Of Squares
print(dist_2_points(v, w))
