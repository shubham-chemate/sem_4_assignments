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
        self.table = [Record(-1, "DUMMY") for _ in range(D)]
        self.is_del = [0 for _ in range(D)]

    def Print(self):
        i=0
        for entry in self.table:
            print(i, entry)
            i += 1
        print("--------------")

    def getHashVal(self, key):
        return key % self.MAX_SIZE

    # Search for key in HashTable, if found return record else return dummy record
    def search(self, key):
        idx = self.getHashVal(key)
        while True:
            if (self.table[idx].ph_num==key):
                return self.table[idx]
            if (self.table[idx].ph_num==-1 and not self.is_del[idx]):
                return Record(-1, "DUMMY")
            idx = (idx+1)%self.MAX_SIZE

    def insert(self, key, val):
        # if key already present, return
        if (self.search(key).ph_num != -1):
            print("Record is already Present.")
            return

        idx = self.getHashVal(key)
        while self.table[idx].ph_num!=-1:
            idx = (idx+1)%self.MAX_SIZE
        self.table[idx]=Record(key, val)

    def delete(self, key):
        if (self.search(key).ph_num == -1):
            print("Record is not Present.")
            return

        idx = self.getHashVal(key)
        while True:
            if (self.table[idx].ph_num==key):
                self.is_del[idx]=1
                self.table[idx]=Record(-1, "DUMMY")
                break
            idx = (idx+1)%self.MAX_SIZE


def main():
    ht = HashTable(10)
    # ht.Print()
    ht.insert(22, "A")
    # ht.Print()
    ht.insert(32, "B")
    # ht.Print()
    ht.insert(42, "C")
    ht.Print()
    ht.insert(44, "D")
    ht.insert(52, "E")
    ht.Print()

main()
