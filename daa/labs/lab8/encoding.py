import heapq

class Node:
    def __init__(self, freq, symb, left, right):
        self.freq = freq
        self.symb = symb
        self.left = left
        self.right = right
    
    def __lt__(self, newNode):
        return(self.freq < newNode.freq)
    
    def __str__(self):
        return self.symb

def huffman(S, F):
    leaves = []
    for i in range(len(S)):
        node = Node(F[i], S[i], None, None)
        leaves.append(node)
    heapq.heapify(leaves)
    for i in range(len(S) - 1):
        x = heapq.heappop(leaves)
        y = heapq.heappop(leaves)
        node = Node(x.freq + y.freq, x.symb + y.symb, x, y)
        heapq.heappush(leaves, node)
    return heapq.heappop(leaves)
        

def main():
    inList=[('a', 20), ('b', 12), ('c', 10), ('d', 8), ('e', 4), ('f', 3)]
    S = []
    F = []
    for i in inList:
        S.append(i[0])
        F.append(i[1])
    
    result = huffman(S, F)
    root = None
    encoding = ''
    # print(result.left, result.right)

    fileSize = 0
    for i, j in inList:
        # print("\t", i, j)
        root = result
        encoding = ''
        while (root.left is not None) and (root.right is not None):
            # print("\t", root.left, root.right)
            if encoding == root.symb:
                # print("--1--")
                print(root.symb, ": ", encoding)
                break
            elif i in root.left.symb:
                # print("--2--")
                encoding = (encoding + '0')
                root = root.left
            elif i in root.right.symb:
                # print("--3--")
                encoding = (encoding + '1')
                root = root.right
            else:
                print("ERROR: Node not found")
                break
        print(root.symb, ": ", encoding)
        fileSize += len(encoding) * root.freq
    print("Filesize: ", fileSize)

if __name__ == '__main__':
    main()