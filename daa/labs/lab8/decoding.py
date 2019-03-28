from encoding import huffman, Node

def main():
    inList=[('a', 20), ('b', 12), ('c', 10), ('d', 8), ('e', 4), ('f', 3)]
    S = []
    F = []
    for i in inList:
        S.append(i[0])
        F.append(i[1])
    
    result = huffman(S, F)
    print(result)

    a = Node(2, 'aaa', None, None)
    print(a)

if __name__ == '__main__':
    main()