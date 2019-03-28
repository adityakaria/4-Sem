class node:
	def __init__(self,name):
		self.p=name
		self.al=[0]*3
		self.max=[0]*3
		self.done=False

		self.need=[0]*3

class SafeSequence:
	def __init__(self,n):
		self.n=n
		self.S=[]
		self.p=[0]*n
		self.ava=[0]*3
		self.i=0

	def getdata(self):
		for i in range(self.n):
			print("Process ",i+1, ": name, allocation, maximum:" )
			na=input()
			self.p[i]=node(na)
			k=input().split()
			self.p[i].al[0],self.p[i].al[1],self.p[i].al[2]=int(k[0]),int(k[1]),int(k[2])
			l=input().split()
			self.p[i].max[0],self.p[i].max[1],self.p[i].max[2]=int(l[0]),int(l[1]),int(l[2])
			self.p[i].need[0],self.p[i].need[1],self.p[i].need[2]=self.p[i].max[0]-self.p[i].al[0],self.p[i].max[1]-self.p[i].al[1],self.p[i].max[2]-self.p[i].al[2]
		print("Available: ", end="\t")
		m=input().split()
		print("-------------------------------------------------------\n")
		self.ava[0],self.ava[1],self.ava[2]=int(m[0]),int(m[1]),int(m[2])

	def findseq(self):
		while(True):
			if self.countn()==0:
				break;
			print(self.i)
			if (self.comparev(self.i)):
				k=self.p[self.i]
				self.ava[0]+=k.al[0]
				self.ava[1]+=k.al[1]
				self.ava[2]+=k.al[2]
				k.done=True
				self.S.append(k.p)
			self.i+=1
			if self.i>=self.n:
				self.i=0




	def comparev(self,i):
		k=self.p[i].need
		l=self.ava
		if(k[0]<=l[0] and k[1]<=l[1] and k[2]<=l[2]):
			return True
		return False


	def countn(self):
		count=0
		for i in range(self.n):
			if self.p[i].done==False:
				count+=1
		print("remaining = ",count)
		return count

def main():
	n=int(input("Enter the number of processes : "))
	SS=SafeSequence(n)
	SS.getdata()

	SS.findseq()
	print("\n-------------------------------------------------------\n")

	print("The required safe sequence  : ")
	for i in range(n):
		print(SS.S[i],end=" --> ")
	print("\n")

if __name__ == '__main__':
	main()

"""
Enter the number of processes : 5
Process  1 : name, allocation, maximum:
0
2 1 0
6 4 3
Process  2 : name, allocation, maximum:
1 
5 1 2
7 8 9
Process  3 : name, allocation, maximum:
2    
4 5 0 
5 6 2
Process  4 : name, allocation, maximum:
3 
0 5 8
4 6 9
Process  5 : name, allocation, maximum:
4
7 5 0
8 9 1
Available:      5 1 6

"""