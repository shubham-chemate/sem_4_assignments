# Author : Shubham (Roll No.: 21118)
# DSA Assignment 04 : Hashing Techniques

class Record():
    def __init__(self, num, name):
        self.ph_num, self.name = num, name

    def __str__(self):
        return "Phone Num: " + str(self.ph_num) + ", Name: " + str(self.name)


class HashTable():
    def __init__(self, D):
        self.MAX_SIZE = D
        self.table = [-1 for _ in range(D)]
        self.nxtIdx = [-1 for _ in range(D)]
        self.is_occu = [0 for _ in range(D)]

    def Print(self):
        i=0
        for entry in self.table:
            print(entry, end=" ")
            print(self.nxtIdx[i])
            i += 1
        print("--------------")

    def getHashVal(self, key):
        return key % self.MAX_SIZE

    def Search(self, key):
        idx = self.getHashVal(key)
        while self.table[idx] != -1:
            if self.table[idx].ph_num == key:
                self.table[idx].Print()
                return True
            idx = self.nxtIdx[idx]
        return False

    def insert(self, key, val):
        if (self.Search(key)):
            print("Record is already Present.")
            return
        idx = self.getHashVal(key)
        while self.is_occu[idx]:
            idx = (idx+1) % self.MAX_SIZE
        self.table[idx] = Record(key, val)
        self.is_occu[idx] = 1


def main():
    ht = HashTable(10)
    ht.insert(22, "A")
    ht.Print()
    ht.insert(33, "B")
    ht.Print()
    ht.insert(42, "C")
    ht.Print()
    ht.insert(32, "D")
    ht.Print()

main()
