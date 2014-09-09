class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    def maxPoints(self, points):
        if len(points) == 0:
            return 0
        elif len(points) == 1:
            return 1

        ans = []
        for index1, value1 in enumerate(points):
            countdict = {}
            duplicate = 0
            duplicate_x = 0
            duplicate_y = 0
            maxvalue = 0
            for index2, value2 in enumerate(points):
                if index1 != index2:
                    x = value1.x - value2.x
                    y = value1.y - value2.y
                    if x == 0 and y == 0:
                        duplicate += 1
                    elif x == 0 and y != 0:
                        duplicate_x += 1
                    elif x != 0 and y == 0:
                        duplicate_y += 1
                    else:
                        tmp = y * 1.0 / x
                        if tmp not in countdict:
                            countdict[tmp] = 1
                        else:
                            countdict[tmp] += 1

            for k, v in countdict.iteritems():
                if v > maxvalue:
                    maxvalue = v

            if maxvalue < duplicate_x:
                maxvalue = duplicate_x
            elif maxvalue < duplicate_y:
                maxvalue = duplicate_y

            ans.append(maxvalue + duplicate + 1)
            # print "++++"
            # print maxvalue + duplicate
            # print "++++"

        retv = max(ans)
        return retv
