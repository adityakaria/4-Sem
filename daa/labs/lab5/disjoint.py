

class Node:
    def __init__(self, name=None, parent=None, rank = 0):
        self.name = name
        if (parent == None):
            self.parent = self
        else:
            self.parent = parent
        # self.rank = rank
    
    def findset(self, bool=True):
        primeParent = self.parent
        if (primeParent != None):
            while ((primeParent.parent != None) and (primeParent.parent != primeParent)):
                primeParent = primeParent.parent
                print("===->")
            if (bool == False):
                return primeParent.name
            else:
                return primeParent
        else:
            if (bool == False):
                return self.name
            else:
                return self
        
    
class DisjointSet:
    def __init__(self, node = None, name=None):
        if (node == None):
            if (name != None):
                node = Node(name=name)
            else:
                node = Node(raw_input("Enter node name:\t"))
        self.head = node
        self.head.parent = self.head
        # self.nodes = []
        # self.nodes.append(Node)
    
    # def __str__(self):
        # pass
    
    # def makeset(self, disSet=None):
    #     primeParent = self.head.parent
    #     while ((primeParent != None) and (primeParent.parent != primeParent)):
    #         print("\t--<<>> ")
    #         primeParent = primeParent.parent
    #     print("\t-->", self.head.name, disSet.head.name)

    #     disSet.head.parent = primeParent.parent
    #     disSet.head = self.head

    def union(self, disSet=None):
        primeHead = self.head
        while ((primeHead.findset().head != None) and (primeHead.findset().head != primeHead)):
            print("\t--<<>> ")
            primeHead = primeHead.findset().head
        print("\t|-->", self.head.name, disSet.head.name)

        disSet.head.parent = primeHead.findset().head.parent
        disSet.head = self.head
        else:
            pass


def main():
    a = DisjointSet(name='a')
    b = DisjointSet(name='b')
    c = DisjointSet(name='c')
    d = DisjointSet(name='d')
    e = DisjointSet(name='e')
    f = DisjointSet(name='f')
    g = DisjointSet(name='g')
    
    print(a.head.findset(False))
    print(b.head.findset(False))
    print(c.head.findset(False))
    print(d.head.findset(False))
    print(e.head.findset(False))
    print(f.head.findset(False))
    print(g.head.findset(False))

    b.union(g)
    e.union(b)
    d.union(e)
    c.union(d)


    a.union(c)
    

    print(a.head.findset(False))
    print(b.head.findset(False))
    print(c.head.findset(False))
    print(d.head.findset(False))
    print(f.head.findset(False))
    print(f.head.findset(False))
    print(g.head.findset(False))


if __name__ == '__main__':
    main()