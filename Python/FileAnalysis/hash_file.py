import hashlib

def hash_file(filename):
   """"This function returns the SHA-1 hash
   of the file passed into it"""
   h = hashlib.sha1()                    # make a hash object
   with open(filename,'rb') as file:     # open file for reading in binary mode
       chunk = 0                         # loop till the end of the file
       while chunk != b'':
           chunk = file.read(1024)       # read only 1024 bytes at a time
           h.update(chunk)
   return h.hexdigest()                  # return the hex representation of digest
message = hash_file("file1.txt")
print(message)
