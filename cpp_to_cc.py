import os

files = os.listdir()

for file in files:
    if os.path.isdir(file):
        continue
    if not os.path.isfile(file):
        continue
    filename = os.path.splitext(file)
    if filename[len(filename) - 1] == '.cpp':
        newfilename = ''
        for name in filename:
            if name == '.cpp':
                break
            newfilename += name
        newfilename += '.cc'
        try:
            os.rename(file, newfilename)
        except FileExistsError as fee:
            print(fee)
        except Exception as e:
            print(e)