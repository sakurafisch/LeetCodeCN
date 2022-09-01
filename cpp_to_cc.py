import os

files = os.listdir()
for file in files:
    if os.path.isdir(file):
        continue
    if not os.path.isfile(file):
        continue
    print(file)
    filename = os.path.splitext(file)
    print(filename)
    if filename[1] == '.cpp':
        newfilename = filename[0] + '.cc'
        os.rename(file, newfilename)
