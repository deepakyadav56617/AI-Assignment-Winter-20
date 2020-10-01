from pprint import pprint
import queue
import os

write_file = open('output.txt', 'w')

def printPath(node):
	while node.parent != None:
		write_file.write(str(node))
		node = node.parent

def delete(node):
	i=0
	while i < len(CLOSED):
		if node.y == CLOSED[i].y:
			del CLOSED[i]
		else:
			i += 1;	

class Queen():
	
	def __init__(self, x, y, cost, parent):
		self.x = x
		self.y = y
		self.cost = cost
		self.parent = parent

	def __repr__(self):
		return '({}, {})'.format(self.y, self.x)		

def cost(node):
	if(len(CLOSED) == 0):
		return False
	for i in range(0, len(CLOSED)):
		if (node.x == CLOSED[i].x and node.y != CLOSED[i].y) or ( abs(CLOSED[i].x - node.x) == abs(CLOSED[i].y - node.y) ):
			return True
    
	return False

def goalTest(node):
	if node.y == N and node.cost == False:
		return True
	else:
		return False	    				

def stateGen(node):
	if node.y + 1 <= N:	
		for i in range(1,N+1):
			tempNode = Queen(0, 0, True, None)
			tempNode.x = i
			tempNode.y = node.y + 1
			tempNode.parent = node
			tempNode.cost = cost(tempNode)
			OPEN.put(tempNode)
				

def main():
	startState = Queen(0, 0, False, None)
	OPEN.put(startState)
	while OPEN.empty() == False:
		temp = OPEN.get()
		delete(temp)
		if goalTest(temp) == True:
			write_file.write('Found solution! HURRAY!!!')
			printPath(temp)
			return

		if temp.cost == False:
			if(temp.x != 0 and temp.y != 0):
				CLOSED.insert(0, temp)
			stateGen(temp)		
	write_file.write('No solution :(')
	return			

file = open('input.txt', 'r')
content = file.read()
N = int(content)
OPEN = queue.LifoQueue(maxsize= N*N)
CLOSED = []

main()
file.close()
write_file.close()
	
			

